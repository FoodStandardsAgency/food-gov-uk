<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

  // For search results which are file entities convert the heading into a link, so that it's consistent with node results.
  if (isset($row->entity_type) && $row->entity_type == 'file' && isset($row->ts_uri) && !empty($row->ts_uri) && isset($row->sm_field_file_title[0]) && !empty($row->sm_field_file_title[0]) && isset($fields['zs_view_mode_search_result']->content)) {
    $title = '<h2 property="title">' . $row->sm_field_file_title[0] . '</h2>';
    $title_replacement = '<h2 property="title">' . l($row->sm_field_file_title[0], $row->ts_uri) . '</h2>';

    // Sometimes the heading tag has a space before property attribute.
    $title_alternative = '<h2  property="title">' . $row->sm_field_file_title[0] . '</h2>';
    $fields['zs_view_mode_search_result']->content = str_replace($title_alternative, $title, $fields['zs_view_mode_search_result']->content);

    $fields['zs_view_mode_search_result']->content = str_replace($title, $title_replacement, $fields['zs_view_mode_search_result']->content);
  }

?>
<?php foreach ($fields as $id => $field): ?>
  <?php if (!empty($field->separator)): ?>
    <?php print $field->separator; ?>
  <?php endif; ?>

  <?php print $field->wrapper_prefix; ?>
    <?php print $field->label_html; ?>
    <?php print $field->content; ?>
  <?php print $field->wrapper_suffix; ?>
<?php endforeach; ?>
