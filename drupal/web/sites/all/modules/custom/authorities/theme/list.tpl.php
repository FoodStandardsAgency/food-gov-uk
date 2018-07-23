<?php

	/**
	 * @file list.tpl.php
	 * Renders authorities as a list
	 *
	 * Available variables:
	 *	$authorities : The collection of authorities
	 *	$parameters : The query-string parameters
	 */

	$element = array();

	// only display the list if there are any search results
	if ($authorities->count() > 0) {
      // if we have a large number of results, remove the numbers because we probably have multiple matching locations
      if ($authorities->count() > 9 ) {
        $type = 'ul';
        $distance = false;
      }
      else {
        $type = 'ol';
        $distance = true;
      }

		// iterate over all the authorities and theme them
		$items = array();
		foreach ($authorities as $authority) {

			$item = array(
				'#theme' => THEME_AUTHORITIES_LIST_ITEM,
				'#authority' => $authority,
				'#parameters' => $parameters,
                '#showdistance' => $distance,
			);

			$items[] = drupal_render($item);
		}

		$element += array(
			'#theme' => 'item_list',
			'#items' => $items,
			'#type' => $type,
			'#attributes' => array('class' => 'authorities'),
		);

	} else {

		// there are no results, so display some notification
		$notification = t('Search did not find any matching names or places.');
		$element['#markup'] = "<div class='no-results'>{$notification}</div>";
	}
?>
<div id='authorities-list'>
	<?=drupal_render($element);?>
</div>
