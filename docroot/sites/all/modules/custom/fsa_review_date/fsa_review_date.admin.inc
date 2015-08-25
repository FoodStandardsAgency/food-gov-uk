<?php
/**
 * @file
 * Admin functions for the FSA Review Date module
 */

/**
 * Displays a list of content requiring review.
 */
function fsa_review_date_list_content() {
  $output[] = _fsa_review_date_content_table(t('Content for review today'));
  $output[] = _fsa_review_date_content_table(t('Content for review in the future'), FALSE);
  return $output;
}


/**
 * Returns a table of content for review
 */
function _fsa_review_date_content_table($heading = 'For review today', $today = TRUE) {
  $header = array(
    array(
      'data' => t('Title'),
      'field' => 'n.title',
      'sort' => 'ASC'
    ),

    array(
      'data' => t('Review date'),
      'field' => 'r.review_date',
      'sort' => 'ASC'
    ),

    array('data' => t('Review comment'),
      'field' => 'r.comment',
      'sort' => 'ASC'
    ),
  );

  $query = db_select('node', 'n');
  $query->fields('n');
  $query->innerJoin('fsa_review_date', 'r', 'n.nid = r.nid and r.vid = n.vid');
  $query->fields('r');
  $operator = $today ? '=' : '>';
  $query->condition('r.review_date', mktime(0,0,0), $operator);
  $query->extend('PagerDefault');
  $query->extend('TableSort')->orderByHeader($header);
  $results = $query->execute();

  $rows = array();
  foreach ($results as $row) {
    $rows[] = array(
      l($row->title, 'node/' . $row->nid),
      format_date($row->review_date, 'custom', 'd F Y'),
      $row->review_comment,
    );
  }


  $output[] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => $heading,
  );

  $output[] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => t('No content found'),
  );

  # add the pager
  //$output .= theme('pager');

  return $output;
}
