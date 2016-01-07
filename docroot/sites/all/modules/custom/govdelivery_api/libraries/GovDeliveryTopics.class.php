<?php
/**
 * @file
 * Topics endpoint class for the GovDelivery API.
 */

class GovDeliveryTopics extends GovDeliveryEndpoint {
  protected $endpoint = 'topics';
  protected $element = 'topic';


  /**
   * Add category(ies) to topic method
   */
  function addCategories($params = array()) {
    $endpoint = $this->endpoint . '/' . $params[$this->element . '_code'] . '/categories.xml';
    return new GovDeliveryResult($this->sendRequest('PUT', $this->buildXmlDocument('add_categories', $params), $endpoint), $this->element);
  }
  
  /**
   * Create a topic
   */
  function create($params = array()) {
    
    // Call the generic create method from the parent
    $response = parent::create($params);
    
    // Get the result object
    $topic = $response->getResult();
    
    // If the request wasn't successful or we don't have an element code,
    // or we don't have any categories to add, return the response now
    if (empty($response->success) || empty($topic->element_code) || empty($params['categories'])) {
      return $response;
    }

    // Add categories to the topic
    $params['topic_code'] = $topic->element_code;
    
    // Wait for the topic to be created before trying to add categories. If we
    // don't do this, the GovDelivery API may return an exception
    sleep(3);
    
    // Call this object's addCategories() method
    $this->addCategories($params);

    return $response;
    
  }
  
  /**
   * Update a topic
   */
  function update($params = array()) {

    // Call the generic create method from the parent
    $response = parent::update($params);

    // Get the result object
    $topic = $response->getResult();
    
    // If the request wasn't successful or we don't have an element code,
    // or we don't have any categories to add, return the response now
    if (empty($response->success) || empty($topic->element_code) || (!empty($params['categories']) && !is_array($params['categories']))) {
      return $response;
    }
    
    // Add categories to the topic
    $params['topic_code'] = $topic->element_code;    

    // Wait for the topic to be updated before trying to add categories.
    sleep(3);
    
    $this->addCategories($params);
    
    return $response;
  }

  /**
   * XML document builder
   */
  function buildXmlDocument($action = '', $params = array()) {

    switch ($action) {

      case 'create':
      case 'update':
        $xml_doc = new SimpleXMLElement("<topic></topic>");
        $xml_doc->addChild('name', $params['topic_name']);
        $xml_doc->addChild('short-name', $params['topic_name']);
        $xml_doc->addChild('description', $params['topic_description']);
        $xml_doc->addChild('pagewatch-enabled', 'true')->addAttribute('type', 'boolean');
        
        
        $autosend = isset($params['pagewatch_autosend']) ? $params['pagewatch_autosend'] : 'true';
        
        $xml_doc->addChild('pagewatch-autosend', $autosend)->addAttribute('type', 'boolean');
        $xml_doc->addChild('pagewatch-type', 1)->addAttribute('type', 'integer');

        if (!empty($params['pages'])) {
          
          $pages = $xml_doc->addChild('pages');
          $pages->addAttribute('type', 'array');
          foreach ($params['pages'] as $page) {
            $pages->addChild('page')->addChild('url', $page);
          }
        }

        if (!empty($params['categories'])) {
          $cats = $xml_doc->addChild('categories');
          $cats->addAttribute('type', 'array');
          foreach ($params['categories'] as $category) {
            $temp = $cats->addChild('category');
            $temp->addChild('code', $category);
          }
        }
        $xml_doc->addChild('code', $params['topic_code']);
        break;

      case 'add_categories':

        $xml_doc = new SimpleXMLElement("<topic></topic>");
        $cats = $xml_doc->addChild('categories');
        $cats->addAttribute('type', 'array');
        if (!empty($params['categories'])) {
          foreach ($params['categories'] as $category) {
            $temp = $cats->addChild('category');
            $temp->addChild('code', $category);
          }
        }
        $xml_doc->addChild('code', $params['topic_code']);

        break;

    }
    return $xml_doc->asXML();
  }



}
