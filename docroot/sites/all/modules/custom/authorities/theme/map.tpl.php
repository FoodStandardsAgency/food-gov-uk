<?php

	/**
	 * @file map.tpl.php
	 * Renders authorities as a map
	 *
	 * Available variables:
	 *	$authorities : The collection of authorities
	 *	$parameters : The query-string parameters
	 */

	$key = variable_get_value('food_bing_api_key');

	$latitude = $parameters->getLatitude();
	$longitude = $parameters->getLongitude();
	$zoom = $parameters->getZoom();

	$width = $parameters->getWidth();
	$height = $parameters->getHeight();

	$url = "http://dev.virtualearth.net/REST/v1/Imagery/Map/Road/{$latitude},{$longitude}/{$zoom}";

	// add the map size
	$url .= "?mapSize={$width},{$height}";

	// the center where to put the star
	$url .= "&pp={$latitude},{$longitude};0;";

	// do we have the position in the parameters?
	// that means we should only display this one on the map
	if ($parameters->hasPosition()) {

		$position = $parameters->getPosition();
		$authority = $authorities->getForIndex($position);

		if (!is_null($authority)) {

			$url .= "&pp={$authority->getLatitude()},{$authority->getLongitude()};2;{$position}";
		}
	} else {

		// iterate over all the authorities and append their coordinates
		foreach ($authorities as $authority) {
			$position = $authority->getPosition() + 1;
			$url .= "&pp={$authority->getLatitude()},{$authority->getLongitude()};2;{$position}";
		}
	}


	$url .= "&mapVersion=v1&key={$key}";

	// build the render element
	$element = array(
		'#theme' => 'image',
		'#path' => $url,
		'#attributes' => array(
			'id' => t('Map'),
			'name' => t('Map'),
		),
	);


// ignore the below code for now. we may put the zoom controller in next time
/*
	// the zoom control goes from 5 .. 17 with as the default
	// we put those values on the zoom-in and zoom-out tags,
	// so the javascript can pick up those and act accordingly
	$zoomMin = 5;
	$zoomMax = 17;
$diff = $zoomMax - $zoomMin;
$ratio = $zoom / $diff * 100;
$zoombarStyle = "style='width:{$ratio}%;'";
<div id="map-zoom">
		<a id="zoomOut" href="#" title="Zoom out" zoomMin="<?=$zoomMin;?>">-</a><span id="zoomIndicator"><span id="zoomBar" <?=$zoombarStyle;?> zoom="<?=$zoom;?>"></span></span><a id="zoomIn" href="#" title="Zoom in" zoomMax="<?=$zoomMax;?>">+</a>
</div>
*/

?>
<div>
	<div id='authorities-map'>
		<?=drupal_render($element);?>
	</div>
</div>
