<?php

	/**
	 * @file localities-list-item.tpl.php
	 * Renders one locality as a clickable link
	 *
	 * Available variables:
	 *	$authority : The authority
	 *	$parameters : The query-string parameters
	 */

	$width = $parameters->getWidth();
	$height = $parameters->getWidth();

	// get the page without the query-string
	// see: http://stackoverflow.com/a/6975045
	$detailUrl = strtok($_SERVER["REQUEST_URI"],'?');
	$detailUrl .= "?width={$width}&height={$height}";

	// whack the outward into the postcode parameter,
	// so BING will return the result around that place
	$locality = $authority->getLocality();
	$detailUrl .= "&city={$locality}";

	// and add the outward. otherwise BING will again return 2 results for the London-Croydon one
	$outward = $authority->getOutward();
	$detailUrl .= "&postcode={$outward}";

	$detailUrl .= "&zoom={$parameters->getZoom()}";

	$detailUrl .= "&category={$parameters->getCategory()}";

	$position = $authority->getPosition() + 1;
?>
<a class="mapChanger" href="<?=$detailUrl;?>"><?=$authority->getLocality();?></a>
