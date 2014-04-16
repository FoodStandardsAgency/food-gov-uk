<?php

	/**
	 * @file list-item.tpl.php
	 * Renders one authority
	 *
	 * Available variables:
	 *	$authority : The authority
	 *	$parameters : The query-string parameters
	 */

	// calculate the distance between the search lat/long and the actual authority.
	// formulas are based on the LBI code
	$lat0 = $parameters->getLatitude();
	$lon0 = $parameters->getLongitude();

	$lat1 = $authority->getLatitude();
	$lon1 = $authority->getLongitude();

	$x = 60.0 * ($lat0 - $lat1);
	$y = 60.0 * ($lon0 - $lon1) * cos(M_PI * ($lat0 + $lat1) / 360.0);
	$dist = sqrt($x * $x + $y * $y);	// Nautical Miles
	$miles = $dist * 6048.0 / 5280.0;	// Miles
	$km = 1.6 * $dist;				// kilometers

	$width = $parameters->getWidth();
	$height = $parameters->getWidth();

	// get the page without the query-string
	// see: http://stackoverflow.com/a/6975045
	$detailUrl = strtok($_SERVER["REQUEST_URI"],'?');
	$detailUrl .= "?width={$width}&height={$height}&latitude={$lat0}&longitude={$lon0}";

	$street = $parameters->getStreet();
	if (!is_null($street)) { $detailUrl .= "&street={$street}"; }

	$city = $parameters->getCity();
	if (!is_null($city)) { $detailUrl .= "&city={$city}"; }

	$postcode = $parameters->getPostcode();
	if (!is_null($postcode)) { $detailUrl .= "&postcode={$postcode}"; }

	$detailUrl .= "&zoom={$parameters->getZoom()}";

	$detailUrl .= "&category={$parameters->getCategory()}";

	$position = $authority->getPosition() + 1;
	$detailUrl .= "&position={$position}";
?>
<div id='authority-<?=$position;?>' class='authority'>
	<div class="details">
		<div class="role">
			<b><?=t('Role');?>:</b>
			<a class="mapChanger" href="<?=$detailUrl;?>">
				<span class="contactType"><?=$authority->getRole();?></span>
			</a>
		</div>
		<div class="address">
			<span class="streetAddress"><?=$authority->getAddr1();?></span><br>
			<span class="addressLocality"><?=$authority->getAddr2();?></span><br>
			<span class="addressRegion"><?=$authority->getAddr3();?></span>,
			<span class="postalCode"><?=$authority->getPostcode();?></span>
		</div>
		<div class="tel">
			<b><?=t('Telephone');?>:</b>
			<span class="telephone"><?=$authority->getTelephone();?></span>
		</div>
		<div class="mail">
			<b><?=t('Email');?>:</b>
			<?php
				// there are some without a valid email address.
				// in that case, render it without a link
				$mail = $authority->getMail();
				if (valid_email_address($mail)) :
			?>
				<a href="mailto:<?=$mail;?>"><?=$mail;?></a>
			<?php	else : ?>
				<span><?=$mail;?></span>
			<?php endif ?>
		</div>
		<div class="web">
			<b><?=t('Website');?>:</b>
			<a href="<?=$authority->getUrl();?>" target="_blank" title="<?=$authority->getAddr1();?> <?=t('(Opens in new window)');?>" itemprop="url"><?=$authority->getUrl();?></a>
		</div>
	</div>
	<div class="distance">
		<div>
			<b><?=t('Distance');?>:</b><?=number_format($km, 2);?> km<br>
			<a class="mapChanger" href="<?=$detailUrl?>"><?=t('View map')?></a>
		</div>
	</div>
</div>