<?php

	/**
	 * @file localities.tpl.php
	 * Renders the localities as a list
	 *
	 * Available variables:
	 *	$authorities : The collection of authorities
	 *	$parameters : The query-string parameters
	 */

	$element = array();

	// only display the list if there are any search results
	if ($authorities->count() > 0) {

		// iterate over all the authorities and theme them
		$items = array();
		foreach ($authorities as $authority) {

			$locality = $authority->getLocality();

			if (!isset($items[$locality])) {

				$item = array(
					'#theme' => THEME_AUTHORITIES_LOCALITIES_ITEM,
					'#authority' => $authority,
					'#parameters' => $parameters,
				);

				$items[$locality] = drupal_render($item);
			}
		}

		// order them alphabetically
		ksort($items);

		$element += array(
			'#theme' => 'item_list',
			'#items' => $items,
			'#type' => 'ul',
			'#attributes' => array('class' => 'localities'),
		);
	}
?>
<div id='localities-list'>
	<?=drupal_render($element);?>
</div>
