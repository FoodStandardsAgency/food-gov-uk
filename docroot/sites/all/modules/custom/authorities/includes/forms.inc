<?php

/**
 * Returns the search form
 */
function _authorities_search_form($form, &$form_state) {

	// add the categories
	$form['category'] = array(
		'#type' => 'fieldset',
		'#title' => t('Select the appropriate option'),
		'#weight' => 0,
	);

	$options = array(
		'environment' => t('Environmental Health Officer'),
		'trading' => t('Trading Standards Officer'),
	);

	$form['category']['category'] = array(
		'#title' => '',
		'#type' => 'radios',
		'#options' => $options,
		'#default_value' => key($options),
		'#required' => FALSE,
	);

	// add the address
	$form['address'] = array(
		'#type' => 'fieldset',
		'#title' => t('Then enter the details of the business'),
		'#weight' => 5,
	);

	$form['address']['street'] = array(
		'#title' => t('Street'),
		'#attributes' => array('placeholder' => t('Enter street of business')),
		'#type' => 'textfield',
		'#size' => 20,
		'#maxlength' => 64,
		'#required' => FALSE,
	);

	$form['address']['city'] = array(
		'#title' => t('City'),
		'#attributes' => array('placeholder' => t('Enter town or city of business')),
		'#type' => 'textfield',
		'#size' => 20,
		'#maxlength' => 64,
		'#required' => FALSE,
	);

	$form['address']['postcode'] = array(
		'#title' => t('Postcode'),
		'#attributes' => array('placeholder' => t('Enter postcode')),
		'#type' => 'textfield',
		'#size' => 20,
		'#maxlength' => 64,
		'#required' => FALSE,
	);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Submit'),
		'#weight' => 10,
	);

	return $form;
}

/**
 * Submit-handler for the search-form
 * @param $form
 * @param $form_state
 */
function _authorities_search_form_submit($form, &$form_state) {

	$input = $form_state['input'];

	$query = array(
		'category' => $input['category'],
	);

	$street = trim($input['street']);
	$city = trim($input['city']);
	$postcode = trim($input['postcode']);

	if (strlen($street) > 0) { $query['street'] = $street; }
	if (strlen($city) > 0) { $query['city'] = $city; }
	if (strlen($postcode) > 0) { $query['postcode'] = $postcode; }

	// we have to redirect the user so the browser is going to display the map and list.
	// and for that we have to provide the values in the query-string
	$path = variable_get_value('authorities_result_page');

	$form_state['redirect'] = array(
		$path,
		array('query' => $query)
	);
}
