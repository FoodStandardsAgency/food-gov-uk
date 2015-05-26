<?php

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {
    private $drupal_users;
    private $current_user;

    /**
     * Initializes context.
     *
     * Every scenario gets its own context instance.
     * You can also pass arbitrary arguments to the
     * context constructor through behat.yml.
     *
     * @param array $drupal_users
     *   Array of drupal_users and credentials
     *
     */
    public function __construct(array $drupal_users) {
        $this->drupal_users = $drupal_users;
    }

    /**
     * @Given I log in as an existing :role
     */
    public function iLogInAsAnExisting($role)
    {
        $user_pass = $this->fetchUserPassword($role);
        if ($user_pass) {
            $login_info = explode('/', $user_pass);
            if ($login_info && count($login_info) == 2) {
                $this->user = (object) array(
                    'name' => $login_info[0],
                    'pass' => $login_info[1],
                    'role' => $role,
                );
                return $this->userLogin();
            } else {
                $err = 'Role not defined properly in behat.yml, expected username/password.';
            }
        } else {
            $err = 'Role not found in behat.yml';
        }

        throw new \Exception($err);
    }

    /**
     * @When /^I check (?:the box )?"(?P<option>[^"]*)" in "(?P<block>[^"]*)"$/
     *
     * @param string $option
     *   Checkbox option text.
     * @param string $block
     *   Block to search, identified by CSS id.
     */
    public function iCheckOptionInBlock($option, $block)
    {
        $page_element = $this->getSession()->getPage();
        if (!$page_element) {
            throw new \Exception('Page not found.');
        }

        $block_element = $page_element->find('xpath', "//div[@id='$block']");
        if (!$block_element) {
            throw new \Exception('Block "' . $block . '" not found.');
        }

        $block_element->checkField($this->fixStepArgument($option));
    }

    /**
     * @When I click on the element with css selector :selector
     */
    public function iClickOnTheElementWithCssSelector($selector)
    {
        $session = $this->getSession();
        $element = $session->getPage()->find('xpath',
            $session->getSelectorsHandler()->selectorToXpath('css', $selector));
        if ($element === null) {
            throw new \InvalidArgumentException("Could not evaluate CSS selector \"$selector\"");
        }

        $element->click();
    }

    /**
     * @When I wait :n second
     * @When I wait :n seconds
     * @When I wait for :n second
     * @When I wait for :n seconds
     */
    public function iWaitForSeconds($n)
    {
        usleep($n * 1000000);
    }

    /**
     * @Given I edit the current node
     */
    public function iEditTheCurrentNode()
    {

        if ($nid = $this->getDrupalNid()) {
            $this->getSession()->visit($this->locatePath('/node/' . $nid . '/edit'));
        } else {
            throw new \Exception('Can\'t get nid.');
        }
    }

    /**
     * @Given I mouse over :link
     */
    public function iMouseOver($link)
    {
        $page_element = $this->getSession()->getPage();
        if (!$page_element) {
            throw new \Exception('Page not found.');
        }
        $link_element = $this->findLink($page_element, $link);
        if (!$link_element) {
            throw new \Exception('Link "' . $link . '" not found.');
        }
        $link_element->mouseOver();
    }

    /**
     * @Given I am logged out
     * @Given I logout
     * @Given I am anonymous
     */
    public function iLogout()
    {
        if ($this->loggedIn()) {
            $this->logout();
        }
    }

    /* END STEP FUNCTIONS */

    /**
     * Return a link by text or class name.
     *
     * @param Element $parent
     *   Element object to search
     * @param string $link
     *   Link text, class name or ID to look for.
     */
    public function findLink($parent, $link)
    {
        $element = $parent->findLink($link);
        if (!$element) {
            $element = $parent->find('xpath', "//a[@class='$link']");
            if (!$element) {
                $element = $parent->find('xpath', "//a[@id='$link']");
            }
        }
        if ($element) {
            $this->initVars();
            $this->vars['link-text'] = $element->getText();
        }
        return $element;
    }

    /**
     * Helper function to fetch user passwords from behat.yml.
     *
     * @param string $type
     *   The user type, e.g. drupal or git.
     *
     * @param string $name
     *   The role to fetch the password for.
     *
     * @return string
     *   The matching username/password or FALSE on error.
     */
    public function fetchUserPassword($name)
    {
        try {
            return $this->drupal_users[$name];
        } catch (\Exception $e) {
            throw new \Exception("Non-existent user/password for $name. Please check behat.yml");
        }
    }

    /**
     * Log in the current user.
     */
    public function userLogin()
    {
        if (empty($this->user)) {
            throw new \Exception('User must be set before userLogin.');
        }

        $user = $this->whoami();
        if (strtolower($user) == strtolower($this->user->name)) {
            // Already logged in.
            return;
        }

        $page_element = $this->getSession()->getPage();
        if (empty($page_element)) {
            throw new \Exception('Page not found.');
        }

        if ($user != $this->current_user) {
            $this->logout();
        }

        $this->getSession()->visit($this->locatePath('/user'));
        if ($this->isLoginForm()) {
            // If I see this, I'm not logged in at all, so log in.
            $this->customLogin();
            if ($this->loggedIn()) {
                // Redirect to /user because sometimes we don't wait
                // for full page load.
                $this->getSession()->visit($this->locatePath('/user'));
                return;
            }
            throw new \Exception('Not logged in.');
        }
        throw new \Exception('Failed to reach the login page.');
    }

    public function isLoginForm()
    {
        $page_element = $this->getSession()->getPage();
        $button = $page_element->findButton($this->getDrupalText('log_in'));
        return (bool) $button;
    }

    public function logout()
    {
        $this->getSession()->visit($this->locatePath('/user/logout'));
    }

    public function whoami()
    {
        $page_element = $this->getSession()->getPage();
        if (!$page_element) {
            throw new \Exception('Page not found.');
        }

        try {
            $data_element = $page_element->find('css', '#behat-data');
            if ($data_element) {
                $data = $data_element->getHtml();
                $matches = array();
                if (preg_match('/drupal username:(\w*)/', $data, $matches)) {
                    return $matches[1];
                }
            }
        } catch (\Exception $e) {
            echo 'Caught exception: ', $e->getMessage(), '\n';
        }

        return $this->current_user;
    }

    public function customLogin()
    {
        $page_element = $this->getSession()->getPage();
        $page_element->fillField($this->getDrupalText('username_field'), $this->user->name);
        $page_element->fillField($this->getDrupalText('password_field'), $this->user->pass);
        $submit = $page_element->findButton($this->getDrupalText('log_in'));
        if (!$submit) {
            throw new \Exception('No submit button on "' . $this->getSession()->getCurrentUrl() . '".');
        }
        $submit->click();
    }

    protected function fixStepArgument($argument)
    {
        $argument = str_replace('\\"', '"', $argument);
        $this->initVars();
        static $random = array();
        for ($start = 0;
             ($start = strpos($argument, '[', $start)) !== FALSE;
             /* omitted */  ) {
            $end = strpos($argument, ']', $start);
            if ($end === FALSE) {
                break;
            }
            $name = substr($argument, $start + 1, $end - $start - 1);
            if ($name == 'random') {
                $this->vars[$name] = Random::name(8);
                $random[] = $this->vars[$name];
            } elseif (substr($name, 0, 7) == 'random:') {
                $num = substr($name, 7);
                if (is_numeric($num) && $num <= count($random)) {
                    $this->vars[$name] = $random[count($random) - $num];
                }
            }
            if (isset($this->vars[$name])) {
                $argument = substr_replace($argument, $this->vars[$name], $start, $end - $start + 1);
                $start += strlen($this->vars[$name]);
            } else {
                $start = $end + 1;
            }
        }

        return $argument;
    }

    private function initVars()
    {
        if (!isset($this->vars['host'])) {
            $this->vars['host'] = parse_url($this->getSession()->getCurrentUrl(), PHP_URL_HOST);
        }
    }

    private function getDrupalNid()
    {
        $nid = null;
        $data = $this->getDrupalData();
        $matches = array();
        if (preg_match('/drupal nid:(\w*)/', $data, $matches)) {
            if (!$nid = $matches[1]) {
                throw new \Exception('Can\'t get nid.');
            }
        }
        return $nid;
    }

    private function getDrupalData()
    {
        $page_element = $this->getSession()->getPage();
        $page_url = $this->getSession()->getCurrentUrl();
        if (!$page_element) {
            throw new \Exception('Page not found.');
        }

        $data_element = $page_element->find('css', '#behat-data');
        if ($data_element) {
            return $data_element->getHtml();
        }
    }
}
