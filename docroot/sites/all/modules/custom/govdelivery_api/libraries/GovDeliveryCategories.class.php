<?php
/**
 * @file
 * Categories endpoint class for the GovDelivery API.
 */

class GovDeliveryCategories extends GovDeliveryEndpoint {
  protected $endpoint = 'categories';
  protected $element = 'category';
  
  /**
   * Get topics for the category
   */
  function getTopics($category_code = NULL) {
    $endpoint = $this->endpoint . '/' . $category_code . '/topics.xml';
    return new GovDeliveryResult($this->sendRequest('GET', NULL, $endpoint), $this->element);
  }
  
  function buildXmlDocument($action = '', $params = array()) {
    
    $defaults = array(
      'allow_subscriptions' => 'true',
      'default_open' => 'true',
    );
    
    $params += $defaults;
    
    switch ($action) {
      case 'create':
      case 'update':
        $xml_doc = new SimpleXMLElement("<category></category>");
        $xml_doc->addChild('name', $params['category_name']);
        $xml_doc->addChild('short-name', $params['category_short_name']);
        $xml_doc->addChild('description', $params['category_description']);
        //if (!empty($params['category_code'])) {
          $xml_doc->addChild('code', $params['category_code']); 
        //}
        $xml_doc->addChild('allow-subscriptions', $params['allow_subscriptions'])->addAttribute('type', 'boolean');
        $xml_doc->addChild('default-open', $params['default_open'])->addAttribute('type', 'boolean');
        if (!empty($params['parent_category'])) {
          $xml_doc->addChild('parent')->addChild('code', $params['parent_category']);
        }
        break;
    }
    return $xml_doc->asXML();
  }
}
