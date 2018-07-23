<?php

/**
 * @file
 * Theme implementation to display standard social media icons block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content - not rendered in this template
 * - $items: Array of social media icons. Each item is an associative array with
 *   the following elements:
 *   - classes: A string of CSS classes to apply to the list item
 *   - title: The title text for the item
 *   - url: The URL of the social media platform
 *   - alt: Alternative text for the image
 *   - icon: A rendered image icon
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 * @see fsa_social_media_preprocess_block()
 *
 * @ingroup themeable
 *
 * Adds custom block classes so that we can target when using rounded corners in
 * combination with border radius
 */
?>
<div<?php print $attributes; ?>>
	<div class="custom-block-inner">
    <?php print render($title_prefix); ?>
    <?php if ($block->subject): ?>
    <div class="custom-block-title-wrapper">
      <h2<?php print $title_attributes; ?>><?php print $block->subject; ?></h2>
    </div>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <div<?php print $content_attributes; ?>>
      <div class="custom-block-content-inner">
        <?php if ($show_labels): ?>
          <div class="label-wrapper">
            <?php if (!$maintenance_mode): ?>
              <span class="left-label"><?php print t('Stay updated'); ?>:</span>
              <span class="right-label"><?php print t('Keep connected'); ?>:</span>
            <?php else: ?>
              <?php print t('Keep connected'); ?>
            <?php endif; ?>
          </div>
        <?php endif; ?>
        <div class="icons-wrapper">
        <ul>
          <?php if (!$maintenance_mode): ?>
            <li><a href="https://www.food.gov.uk/news-alerts" target="_blank" title="email"><img alt="email" src="/sites/all/themes/site_frontend/images/icons/34x34/email.png" /></a></li>
            <li><a href="https://www.food.gov.uk/news-alerts" target="_blank" title="phone"><img alt="phone" src="/sites/all/themes/site_frontend/images/icons/34x34/phone.png" /></a></li>
            <li class="extra-margin"><a href="https://www.food.gov.uk/news-alerts" target="_blank" title="RSS"><img alt="RSS" src="/sites/all/themes/site_frontend/images/icons/34x34/rss.png" /></a></li>
          <?php endif; ?>
          <?php foreach($items as $item): ?>
            <li class="<?= $item['classes']; ?>"><a href="<?php print render($item['url']); ?>" target="_blank" title="<?php print render($item['title']); ?>"><?php print render($item['icon']); ?></a></li>
          <?php endforeach; ?>
        </ul>
        </div>
      </div>
    </div>
	</div>
</div>
