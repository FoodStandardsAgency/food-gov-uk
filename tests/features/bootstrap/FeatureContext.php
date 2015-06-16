<?php

use Behat\Behat\Tester\Exception\PendingException;
use Drupal\DrupalExtension\Context\RawDrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Context\MinkContext;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {
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
     * @Given I log in as a(n) :role
     */
    public function iLogInAsA($role)
    {
        $user_pass = $this->drupal_users[$role];
        if (!$user_pass) {
            throw new Exception("No $role defined in behat.yml");
        }

        if (!strpos($user_pass, '/')) {
            throw new Exception("$role incorrectly specified in behat.yml");
        }

        list($user, $pass) = explode('/', $user_pass, 2);
        $this->user = (object) array(
            'name' => $user,
            'pass' => $pass,
            'role' => $role,
        );

        $this->login();
    }

    /**
     * @When I edit a new general page
     */
    public function iEditANewGeneralPage()
    {
        $session = $this->getSession();
        $session->visit($this->locatePath('/node/add/document-page'));

        if ($this->pageTitle() !== 'Create General Page') {
            throw new Exception('Error creating new general page');
        }

        $this->nodeDefaults();

        $page = $session->getPage();

        $page->findLink('Menu settings')->click();
        $page->findField('edit-menu-parent-hierarchical-select-selects-1')->selectOption('About us');
    }

    /**
     * @When I enable the :setting page setting
     */
    public function iEnableThePageSetting($setting)
    {
        static $settings = array(
            'Back to top' => 'edit-field-setting-backtotop-und',
        );

        $session = $this->getSession();

        $page = $session->getPage();
        $page->findLink('Page settings')->click();
        $page->findField($settings[$setting])->click();
    }

    /**
     * @When I save the page
     */
    public function iSaveThePage()
    {
        $page = $this->getSession()->getPage();
        $page->findButton('edit-submit')->click();

        if (!$page->has('named', array('content', '"has been created"'))) {
            throw new Exception('error saving new page');
        }
    }

    /**
     * @Then I should see a back to top link
     */
    public function iShouldSeeABackToTopLink()
    {
        $page = $this->getSession()->getPage();
        if (!$page->has('css', '.section-back-top > a')) {
            throw new Exception('Back to top link not found');
        }
    }

    /**
     * @When I edit a new audit report
     */
    public function iEditANewAuditReport()
    {
        $session = $this->getSession();
        $session->visit($this->locatePath('/node/add/audit-report'));

        if ($this->pageTitle() !== 'Create Audit Report') {
            throw new Exception('Error creating new audit report');
        }

        $this->nodeDefaults();

        $page = $session->getPage();
        $page->findLink('Audit')->click();
        $page->findField('Audit type')->selectOption('Approved establishments audit');
        $page->findField('Authority')->selectOption('Amber Valley');
        $page->findField('Authority Type')->selectOption('County');
    }

    /**
     * @When I edit a new consultation
     */
    public function iEditANewConsultation()
    {
        $session = $this->getSession();
        $session->visit($this->locatePath('/node/add/consultation'));

        if ($this->pageTitle() !== 'Create Consultation') {
            throw new Exception('Error creating new consultation');
        }

        $this->nodeDefaults();
    }

    /**
     * @When I edit a new FAQ entry
     */
    public function iEditANewFaqEntry()
    {
        $session = $this->getSession();
        $session->visit($this->locatePath('/node/add/faq'));

        if ($this->pageTitle() !== 'Create FAQ') {
            throw new Exception('Error creating new FAQ entry');
        }

        $this->nodeDefaults();

        $page = $session->getPage();

        $page->findLink('Menu settings')->click();
        $page->findField('edit-menu-enabled')->check();
        $page->findField('edit-menu-parent-hierarchical-select-selects-1')->selectOption('About us');
    }

    /**
     * @When I edit a new job listing
     */
    public function iEditANewJobListing()
    {
        $session = $this->getSession();
        $session->visit($this->locatePath('/node/add/job'));

        if ($this->pageTitle() !== 'Create Job') {
            throw new Exception('Error creating new job listing');
        }

        $this->nodeDefaults();

        $page = $session->getPage();
        $page->findLink('Menu settings')->click();
        $page->findField('edit-menu-parent-hierarchical-select-selects-1')->selectOption('About us');
    }

    /**
     * @When I edit a new news post
     */
    public function iEditANewNewsPost()
    {
        throw new PendingException();
        // TODO: figure out how to attach a feature image
        $session = $this->getSession();
        $session->visit($this->locatePath('/node/add/news'));

        if ($this->pageTitle() !== 'Create News') {
            throw new Exception('Error creating new news post');
        }

        $this->nodeDefaults();

        $page = $session->getPage();
        $page->findLink('News *')->click();
        $page->findField('News type')->selectOption('General news');
        $page->findLink('Feature image *')->click();
        $page->findLink('Browse')->click();
        $session->wait(5000);
        $page->findLink('Library')->click();
        $page->find('css', '.media-item img')->click();
        $page->find('css', '.ui-dialog')->findLink('submit')->click();
    }

    /**
     * @When I edit a new research project
     */
    public function iEditANewResearchProject()
    {
        $session = $this->getSession();
        $session->visit($this->locatePath('/node/add/project'));

        if ($this->pageTitle() !== 'Create Research Project') {
            throw new Exception('Error creating new research project');
        }

        $this->nodeDefaults();
    }

    /**
     * @When I edit a new alert
     */
    public function iEditANewAlert()
    {
        $session = $this->getSession();
        $session->visit($this->locatePath('/node/add/alert'));

        if ($this->pageTitle() !== 'Create Alert') {
            throw new Exception('Error creating new alert');
        }

        $this->nodeDefaults();
    }

    public function pageTitle()
    {
        $page = $this->getSession()->getPage();
        $title = $page->findById('page-title');
        if (!$title) {
            $title = $page->find('css', '.page-title');
        }
        return $title->getText();
    }

    public function loggedIn()
    {
        // parent::loggedIn() doesn't work when the admin menu doesn't
        // show up, so try a different check
        $session = $this->getSession()->visit($this->locatePath('/user'));
        return $this->pageTitle() === $this->user->name;
    }

    /**
     * Set up some common defaults for creating a new node.
     */
    public function nodeDefaults()
    {
        $page = $this->getSession()->getPage();

        $page->findField('edit-title')->setValue('test');
        $page->findField('edit-field-title-short-und-0-value')->setValue('test');
        $page->findLink('Audience')->click();
        $page->findField('England')->check();
        $page->findField('edit-field-site-section-und-15')->check();
    }
}