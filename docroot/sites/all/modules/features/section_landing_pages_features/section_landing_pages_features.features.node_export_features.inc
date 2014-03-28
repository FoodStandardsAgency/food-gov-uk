<?php
/**
 * @file
 * section_landing_pages_features.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function section_landing_pages_features_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'198\',
      \'uid\' => \'1\',
      \'title\' => \'Policy and advice\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'cd3e56b2-551b-49f3-b74e-8924fc448a51\',
      \'nid\' => \'3\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442141\',
      \'changed\' => \'1395490256\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'347a84d6-9e63-48bc-a5ef-3e7861750fe4\',
      \'revision_timestamp\' => \'1395490256\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>In this section you&#39;ll find background information on a range of topics as well as our ongoing work in these areas, including GM foods, additives, allergy and campylobacter.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>In this section you\'ll find background information on a range of topics as well as our ongoing work in these areas, including GM foods, additives, allergy and campylobacter.</p>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'The Food Standards Agency carries out a range of work to make sure food is safe to eat, including funding research on chemical, microbiological and radiological safety, as well as food hygiene, GM and allergy.\',
            \'format\' => NULL,
            \'safe_value\' => \'The Food Standards Agency carries out a range of work to make sure food is safe to eat, including funding research on chemical, microbiological and radiological safety, as well as food hygiene, GM and allergy.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'3\',
            \'uid\' => \'1\',
            \'filename\' => \'policy.jpg\',
            \'uri\' => \'public://banner-image/policy.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'22716\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'0bd8a845-c201-4e9f-94de-59b6ee70fa9e\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Subtitle here\',
            \'format\' => NULL,
            \'safe_value\' => \'Subtitle here\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'policy-and-advice\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_1\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'4\',
      \'current_revision_id\' => \'198\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Policy & advice\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-48\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'5\',
        \'source\' => \'node/3\',
        \'alias\' => \'policy-advice\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'200\',
      \'uid\' => \'1\',
      \'title\' => \'Enforcement and regulation\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'5f09b377-b7d5-4012-9e5c-9b32940d6872\',
      \'nid\' => \'5\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442205\',
      \'changed\' => \'1395490422\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'35faa675-ba52-4be4-9a85-66356897d121\',
      \'revision_timestamp\' => \'1395490422\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>As well as information on food safety legislation, this section also provides enforcement officers with all the tools they need to ensure that food safety and legal requirements are maintained and monitored in their area.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => \'<p>As well as information on food safety legislation, this section also provides enforcement officers with all the tools they need to ensure that food safety and legal requirements are maintained and monitored in their area.</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'The Food Standards Agency works closely with local authority enforcement officers to make sure food law is applied throughout the food chain.\',
            \'format\' => NULL,
            \'safe_value\' => \'The Food Standards Agency works closely with local authority enforcement officers to make sure food law is applied throughout the food chain.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'5\',
            \'uid\' => \'1\',
            \'filename\' => \'enforcement.jpg\',
            \'uri\' => \'public://banner-image/enforcement.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'13866\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'8cf22425-4c26-4595-b322-7796e76716b8\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
          ),
        ),
      ),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'enforcement-and-regulation\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_3\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'3\',
      \'current_revision_id\' => \'200\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Enforcement & regulation\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-46\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'3\',
        \'source\' => \'node/5\',
        \'alias\' => \'enforcement\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'157\',
      \'uid\' => \'1\',
      \'title\' => \'Error 403 - Access denied \',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'0\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'5d0be1af-c4aa-491f-ab7e-d1dedfb69ca9\',
      \'nid\' => \'86\',
      \'type\' => \'document_page\',
      \'language\' => \'en\',
      \'created\' => \'1395240347\',
      \'changed\' => \'1395240347\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'3e69dd26-2c2a-4ea3-babb-c1840323aa99\',
      \'revision_timestamp\' => \'1395240347\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_updated\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2014-03-19 00:00:00\',
            \'timezone\' => \'Europe/London\',
            \'timezone_db\' => \'Europe/London\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_summary\' => array(),
      \'field_feature_image\' => array(),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Sorry, the page you are looking for cannot be found.\',
            \'format\' => NULL,
            \'safe_value\' => \'Sorry, the page you are looking for cannot be found.\',
          ),
        ),
      ),
      \'field_fc_page_section\' => array(
        \'und\' => array(
          array(
            \'value\' => \'98\',
            \'revision_id\' => \'275\',
          ),
          array(
            \'value\' => \'99\',
            \'revision_id\' => \'276\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'error-403\',
          ),
        ),
      ),
      \'field_featured_item\' => array(),
      \'field_site_section\' => array(
        \'und\' => array(
          array(
            \'tid\' => \'15\',
          ),
        ),
      ),
      \'field_nation\' => array(
        \'und\' => array(
          array(
            \'tid\' => \'4\',
          ),
        ),
      ),
      \'field_display_updated_date\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'field_table_of_contents_level\' => array(
        \'und\' => array(
          array(
            \'value\' => \'off\',
          ),
        ),
      ),
      \'field_fc_side_content_generic\' => array(),
      \'field_links_see_also\' => array(),
      \'field_links_external\' => array(),
      \'field_child_page_style\' => array(
        \'und\' => array(
          array(
            \'field_collection_select\' => \'fc_teaser\',
          ),
        ),
      ),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'157\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => NULL,
      \'path\' => array(
        \'pid\' => \'90\',
        \'source\' => \'node/86\',
        \'alias\' => \'error-403\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
      \'field_collection_deploy\' => array(
        \'field_fc_page_section\' => array(
          array(
            \'item_id\' => \'98\',
            \'revision_id\' => \'275\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'3086b205-9de5-4a64-b92d-e900273f64c0\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'This might be because\',
                  \'format\' => NULL,
                  \'safe_value\' => \'This might be because\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\r\\n<div class=\\"field__items\\">\\r\\n<div class=\\"field__item even\\">\\r\\n<ul>\\r\\n\\t<li>You may have typed the web address incorrectly.</li>\\r\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\r\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\r\\n</ul>\\r\\n</div>\\r\\n</div>\\r\\n</div>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\n<div class=\\"field__items\\">\\n<div class=\\"field__item even\\">\\n<ul><li>You may have typed the web address incorrectly.</li>\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\n</ul></div>\\n</div>\\n</div>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
          array(
            \'item_id\' => \'99\',
            \'revision_id\' => \'276\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'0b903ffa-14ba-409c-a697-124d524de5a1\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Please try the following\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Please try the following\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\r\\n<div class=\\"field__items\\">\\r\\n<div class=\\"field__item even\\">\\r\\n<ul>\\r\\n\\t<li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\r\\n\\t<li>Return to the <a class=\\"ext\\" href=\\"http://food.gov.uk/\\" target=\\"_blank\\">food.gov.uk home page.</a></li>\\r\\n\\t<li>Use our site search.</li>\\r\\n\\t<li>If you still encounter problems then try <a class=\\"ext\\" href=\\"http://food.gov.uk/about-us/aboutsite/\\" target=\\"_blank\\">&#39;About this website&#39;</a>.</li>\\r\\n</ul>\\r\\n</div>\\r\\n</div>\\r\\n</div>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\n<div class=\\"field__items\\">\\n<div class=\\"field__item even\\">\\n<ul><li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\n\\t<li>Return to the <a class=\\"ext\\" href=\\"http://food.gov.uk/\\" target=\\"_blank\\">food.gov.uk home page.</a></li>\\n\\t<li>Use our site search.</li>\\n\\t<li>If you still encounter problems then try <a class=\\"ext\\" href=\\"http://food.gov.uk/about-us/aboutsite/\\" target=\\"_blank\\">\'About this website\'</a>.</li>\\n</ul></div>\\n</div>\\n</div>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
        ),
        \'field_fc_side_content_generic\' => array(
          array(
            \'item_id\' => \'98\',
            \'revision_id\' => \'275\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'3086b205-9de5-4a64-b92d-e900273f64c0\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'This might be because\',
                  \'format\' => NULL,
                  \'safe_value\' => \'This might be because\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\r\\n<div class=\\"field__items\\">\\r\\n<div class=\\"field__item even\\">\\r\\n<ul>\\r\\n\\t<li>You may have typed the web address incorrectly.</li>\\r\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\r\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\r\\n</ul>\\r\\n</div>\\r\\n</div>\\r\\n</div>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\n<div class=\\"field__items\\">\\n<div class=\\"field__item even\\">\\n<ul><li>You may have typed the web address incorrectly.</li>\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\n</ul></div>\\n</div>\\n</div>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
          array(
            \'item_id\' => \'99\',
            \'revision_id\' => \'276\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'0b903ffa-14ba-409c-a697-124d524de5a1\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Please try the following\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Please try the following\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\r\\n<div class=\\"field__items\\">\\r\\n<div class=\\"field__item even\\">\\r\\n<ul>\\r\\n\\t<li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\r\\n\\t<li>Return to the <a class=\\"ext\\" href=\\"http://food.gov.uk/\\" target=\\"_blank\\">food.gov.uk home page.</a></li>\\r\\n\\t<li>Use our site search.</li>\\r\\n\\t<li>If you still encounter problems then try <a class=\\"ext\\" href=\\"http://food.gov.uk/about-us/aboutsite/\\" target=\\"_blank\\">&#39;About this website&#39;</a>.</li>\\r\\n</ul>\\r\\n</div>\\r\\n</div>\\r\\n</div>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\n<div class=\\"field__items\\">\\n<div class=\\"field__item even\\">\\n<ul><li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\n\\t<li>Return to the <a class=\\"ext\\" href=\\"http://food.gov.uk/\\" target=\\"_blank\\">food.gov.uk home page.</a></li>\\n\\t<li>Use our site search.</li>\\n\\t<li>If you still encounter problems then try <a class=\\"ext\\" href=\\"http://food.gov.uk/about-us/aboutsite/\\" target=\\"_blank\\">\'About this website\'</a>.</li>\\n</ul></div>\\n</div>\\n</div>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
        ),
      ),
    ),
  (object) array(
      \'vid\' => \'103\',
      \'uid\' => \'1\',
      \'title\' => \'FSA in Northern Ireland\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'fea37d66-8363-47ca-907b-4f80d9279ff1\',
      \'nid\' => \'50\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1395146644\',
      \'changed\' => \'1395148057\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'45eeab8d-023a-4970-9674-fe6ace84b0ba\',
      \'revision_timestamp\' => \'1395148057\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'northern-ireland\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'6\',
      \'current_revision_id\' => \'103\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Northern Ireland\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'0\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'FSA in Northern Ireland\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'54\',
        \'source\' => \'node/50\',
        \'alias\' => \'northern-ireland\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'100\',
      \'uid\' => \'1\',
      \'title\' => \'FSA in Scotland\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'992a118e-32b1-4259-bf30-96098982fc0a\',
      \'nid\' => \'47\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1395109826\',
      \'changed\' => \'1395147345\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'45ff34ff-2788-41c6-984f-7cb1d5640c47\',
      \'revision_timestamp\' => \'1395147345\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'scotland\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'5\',
      \'current_revision_id\' => \'100\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Scotland\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'48\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'FSA in Scotland\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'51\',
        \'source\' => \'node/47\',
        \'alias\' => \'scotland\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'203\',
      \'uid\' => \'1\',
      \'title\' => \'News and Updates\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'c7efcd49-a9d6-45f7-90c8-6eb5820c35e6\',
      \'nid\' => \'2\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442104\',
      \'changed\' => \'1395504154\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'6dd92932-f132-4138-8e61-ea7f947389e7\',
      \'revision_timestamp\' => \'1395504154\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>You will also find information about our latest campaigns, consultations, food recalls and allergy alerts.</p>\\r\\n\\r\\n<p>Journalists requiring further information should contact the Press Office on 020 7276 8888.</p>\\r\\n\\r\\n<p>For other contact details please see contact us.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>You will also find information about our latest campaigns, consultations, food recalls and allergy alerts.</p>\\n\\n<p>Journalists requiring further information should contact the Press Office on 020 7276 8888.</p>\\n\\n<p>For other contact details please see contact us.</p>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => "Keep up-to-date with the Agency\'s latest news in this section.",
            \'format\' => NULL,
            \'safe_value\' => \'Keep up-to-date with the Agency&#039;s latest news in this section.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'2\',
            \'uid\' => \'1\',
            \'filename\' => \'news.jpg\',
            \'uri\' => \'public://banner-image/news.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'15281\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'5c0a0f1f-acd2-40c4-a6ce-bdcf82eb457e\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Keep up-to-date with latest news\',
            \'format\' => NULL,
            \'safe_value\' => \'Keep up-to-date with latest news\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'news-and-updates\',
          ),
        ),
      ),
      \'field_popular_links\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'93\',
          ),
        ),
      ),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block\',
          ),
        ),
      ),
      \'field_current_topics\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'100\',
          ),
          array(
            \'target_id\' => \'31\',
          ),
          array(
            \'target_id\' => \'103\',
          ),
          array(
            \'target_id\' => \'104\',
          ),
        ),
      ),
      \'field_resources\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'99\',
          ),
          array(
            \'target_id\' => \'101\',
          ),
          array(
            \'target_id\' => \'100\',
          ),
          array(
            \'target_id\' => \'31\',
          ),
        ),
      ),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'5\',
      \'current_revision_id\' => \'203\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'News & updates\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-49\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'6\',
        \'source\' => \'node/2\',
        \'alias\' => \'news-updates\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'206\',
      \'uid\' => \'1\',
      \'title\' => \'About us\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'8c2b6d30-0d48-46f2-8918-b1ed9d47c24a\',
      \'nid\' => \'7\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442261\',
      \'changed\' => \'1395507611\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'8502d102-914b-44f9-b355-29f3c237035b\',
      \'revision_timestamp\' => \'1395507611\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Everything we do reflects our vision of &lsquo;Safer food for the nation&rsquo;. We aim to ensure that food produced or sold in the UK is safe to eat, consumers have the information they need to make informed choices about where and what they eat and that regulation and enforcement is risk-based and focused on improving public health.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => \'<p>Everything we do reflects our vision of ‘Safer food for the nation’. We aim to ensure that food produced or sold in the UK is safe to eat, consumers have the information they need to make informed choices about where and what they eat and that regulation and enforcement is risk-based and focused on improving public health.</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'The Food Standards Agency is an independent government department responsible for food safety and hygiene across the UK. We work with businesses to help them produce safe food, and with local authorities to enforce food safety regulations.\',
            \'format\' => NULL,
            \'safe_value\' => \'The Food Standards Agency is an independent government department responsible for food safety and hygiene across the UK. We work with businesses to help them produce safe food, and with local authorities to enforce food safety regulations.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'7\',
            \'uid\' => \'1\',
            \'filename\' => \'about-us.jpg\',
            \'uri\' => \'public://banner-image/about-us.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'6719\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'664c5f9e-abac-471e-adb7-d41761e08be6\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Subtitle here\',
            \'format\' => NULL,
            \'safe_value\' => \'Subtitle here\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'about-us\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_5\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'5\',
      \'current_revision_id\' => \'206\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'About us\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-44\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'1\',
        \'source\' => \'node/7\',
        \'alias\' => \'about-us\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'1\',
      \'uid\' => \'1\',
      \'title\' => \'Home Page\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'3ab80956-ca1b-42e0-a8b2-19284f6a1990\',
      \'nid\' => \'1\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1391441873\',
      \'changed\' => \'1392978505\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'9aeebc91-574a-42ec-8b2c-8bdf4e1b5493\',
      \'revision_timestamp\' => \'1392978505\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Welcome to the home page.</p>\\r\\n\\r\\n<p>&nbsp;</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>Welcome to the home page.</p>\\n\\n<p> </p>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'1\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Home\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-50\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'0\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => FALSE,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'156\',
      \'uid\' => \'1\',
      \'title\' => \'Error 404 - Page not found\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'0\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'5fcc8200-b02a-4aa5-ad33-1365b1ac46d1\',
      \'nid\' => \'85\',
      \'type\' => \'document_page\',
      \'language\' => \'und\',
      \'created\' => \'1395239969\',
      \'changed\' => \'1395239969\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'c9206553-dfb6-4cb8-978f-5873ea0eb605\',
      \'revision_timestamp\' => \'1395239969\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_updated\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2014-03-19 00:00:00\',
            \'timezone\' => \'Europe/London\',
            \'timezone_db\' => \'Europe/London\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Sorry, the page you are looking for cannot be found.\',
            \'format\' => NULL,
            \'safe_value\' => \'Sorry, the page you are looking for cannot be found.\',
          ),
        ),
      ),
      \'field_feature_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_fc_page_section\' => array(
        \'und\' => array(
          array(
            \'value\' => \'96\',
            \'revision_id\' => \'273\',
          ),
          array(
            \'value\' => \'97\',
            \'revision_id\' => \'274\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'error-404\',
          ),
        ),
      ),
      \'field_featured_item\' => array(),
      \'field_site_section\' => array(
        \'und\' => array(
          array(
            \'tid\' => \'15\',
          ),
        ),
      ),
      \'field_nation\' => array(
        \'und\' => array(
          array(
            \'tid\' => \'4\',
          ),
        ),
      ),
      \'field_display_updated_date\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'field_table_of_contents_level\' => array(
        \'und\' => array(
          array(
            \'value\' => \'off\',
          ),
        ),
      ),
      \'field_fc_side_content_generic\' => array(),
      \'field_links_see_also\' => array(),
      \'field_links_external\' => array(),
      \'field_child_page_style\' => array(
        \'und\' => array(
          array(
            \'field_collection_select\' => \'fc_teaser\',
          ),
        ),
      ),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'156\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => NULL,
      \'path\' => array(
        \'pid\' => \'89\',
        \'source\' => \'node/85\',
        \'alias\' => \'error-404\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
      \'field_collection_deploy\' => array(
        \'field_fc_page_section\' => array(
          array(
            \'item_id\' => \'96\',
            \'revision_id\' => \'273\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'2db50b4b-21bb-48e9-8889-6ed50e4db43e\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'This might be because\',
                  \'format\' => NULL,
                  \'safe_value\' => \'This might be because\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<ul>\\r\\n\\t<li>You may have typed the web address incorrectly.</li>\\r\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\r\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\r\\n</ul>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<ul><li>You may have typed the web address incorrectly.</li>\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\n</ul>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
          array(
            \'item_id\' => \'97\',
            \'revision_id\' => \'274\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'73f80dd0-8e3d-41d9-ab97-9b6ae5101e07\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Please try the following\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Please try the following\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<ul>\\r\\n\\t<li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\r\\n\\t<li>Return to the <a href=\\"http://food.gov.uk/\\">food.gov.uk home page.</a></li>\\r\\n\\t<li>Use our site search.</li>\\r\\n\\t<li>If you still encounter problems then try <a href=\\"http://food.gov.uk/about-us/aboutsite/\\">&#39;About this website&#39;</a>.</li>\\r\\n</ul>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<ul><li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\n\\t<li>Return to the <a href=\\"http://food.gov.uk/\\">food.gov.uk home page.</a></li>\\n\\t<li>Use our site search.</li>\\n\\t<li>If you still encounter problems then try <a href=\\"http://food.gov.uk/about-us/aboutsite/\\">\'About this website\'</a>.</li>\\n</ul>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
        ),
        \'field_fc_side_content_generic\' => array(
          array(
            \'item_id\' => \'96\',
            \'revision_id\' => \'273\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'2db50b4b-21bb-48e9-8889-6ed50e4db43e\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'This might be because\',
                  \'format\' => NULL,
                  \'safe_value\' => \'This might be because\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<ul>\\r\\n\\t<li>You may have typed the web address incorrectly.</li>\\r\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\r\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\r\\n</ul>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<ul><li>You may have typed the web address incorrectly.</li>\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\n</ul>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
          array(
            \'item_id\' => \'97\',
            \'revision_id\' => \'274\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'73f80dd0-8e3d-41d9-ab97-9b6ae5101e07\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Please try the following\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Please try the following\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<ul>\\r\\n\\t<li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\r\\n\\t<li>Return to the <a href=\\"http://food.gov.uk/\\">food.gov.uk home page.</a></li>\\r\\n\\t<li>Use our site search.</li>\\r\\n\\t<li>If you still encounter problems then try <a href=\\"http://food.gov.uk/about-us/aboutsite/\\">&#39;About this website&#39;</a>.</li>\\r\\n</ul>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<ul><li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\n\\t<li>Return to the <a href=\\"http://food.gov.uk/\\">food.gov.uk home page.</a></li>\\n\\t<li>Use our site search.</li>\\n\\t<li>If you still encounter problems then try <a href=\\"http://food.gov.uk/about-us/aboutsite/\\">\'About this website\'</a>.</li>\\n</ul>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
        ),
      ),
    ),
  (object) array(
      \'vid\' => \'199\',
      \'uid\' => \'1\',
      \'title\' => \'Business and industry\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'1e6136a9-ce29-476d-95ed-f2e8dfc1c3a1\',
      \'nid\' => \'4\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442166\',
      \'changed\' => \'1395490337\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'cd92ac88-8d94-4bbd-b4fe-5c1367140ab4\',
      \'revision_timestamp\' => \'1395490337\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>The Food Standards Agency is concerned with the whole food industry &ndash; from farming, food production and distribution, to retail and catering. It addresses food safety issues at every stage of the chain, providing information and guidance on best practice and legal requirements.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => \'<p>The Food Standards Agency is concerned with the whole food industry – from farming, food production and distribution, to retail and catering. It addresses food safety issues at every stage of the chain, providing information and guidance on best practice and legal requirements.</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => "Whether you\'re a café or restaurant owner, farmer or butcher, this section has all the advice and guidance you need to produce safe food.",
            \'format\' => NULL,
            \'safe_value\' => \'Whether you&#039;re a café or restaurant owner, farmer or butcher, this section has all the advice and guidance you need to produce safe food.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'4\',
            \'uid\' => \'1\',
            \'filename\' => \'business.jpg\',
            \'uri\' => \'public://banner-image/business.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'26705\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'bbfd5e7d-9172-4c47-b1a1-df6255258bc0\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Subtitle here\',
            \'format\' => NULL,
            \'safe_value\' => \'Subtitle here\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'business-and-industry\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_2\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'3\',
      \'current_revision_id\' => \'199\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Business & industry\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-47\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'4\',
        \'source\' => \'node/4\',
        \'alias\' => \'business-industry\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'165\',
      \'uid\' => \'1\',
      \'title\' => \'FSA in Wales\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'78102601-5519-4092-b8d9-eff46f8a02d3\',
      \'nid\' => \'49\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1395146378\',
      \'changed\' => \'1395255102\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'d9eb598f-2831-4c0a-93f9-3712ff23a9f9\',
      \'revision_timestamp\' => \'1395255102\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'wales\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'6\',
      \'current_revision_id\' => \'165\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Wales\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'48\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'FSA in Wales\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'53\',
        \'source\' => \'node/49\',
        \'alias\' => \'wales\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'73\',
      \'uid\' => \'1\',
      \'title\' => \'Search All\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'1976b9ee-0912-42b5-97ef-677967a38fae\',
      \'nid\' => \'45\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1394801456\',
      \'changed\' => \'1394801456\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'e3ab63c1-0bc1-4c39-8318-52119ec19140\',
      \'revision_timestamp\' => \'1394801456\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc faucibus nulla quis ligula consequat, vel vehicula lorem dapibus! Quisque facilisis vel tellus convallis placerat! Suspendisse at venenatis enim. Fusce ac massa porttitor, posuere sapien at, ornare diam. Integer mollis faucibus tempor. Etiam sit amet bibendum sem? Sed pellentesque magna vehicula ligula elementum placerat. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce a arcu lorem. Nam lorem tortor, luctus consequat ultrices semper, fringilla id augue. Suspendisse mollis quis nisl vel elementum. Ut tristique, lectus ac tincidunt mollis, massa diam dignissim massa, sed imperdiet nulla magna quis elit! Aenean id viverra enim. Curabitur dui ante, consectetur vel dui non, feugiat interdum lorem! Vivamus porttitor mattis lorem in rhoncus. Praesent dictum in urna et convallis. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin in leo nec enim volutpat scelerisque sit amet sed dolor. Fusce a elit sodales lacus condimentum placerat eget eget nisi. Quisque hendrerit est nec mattis vulputate. Suspendisse potenti. Ut aliquet elit eros. Sed dignissim diam ut vestibulum laoreet. Nulla varius tortor lacus, quis commodo eros dignissim vitae. Etiam ultrices in urna nec molestie. Mauris fringilla sodales hendrerit? Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Aenean non arcu in massa convallis commodo at ac sapien. Integer at risus accumsan, dignissim neque nec, pellentesque arcu. Quisque eu fringilla mauris. Cras ac elementum libero, vel pellentesque tellus.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => \'<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc faucibus nulla quis ligula consequat, vel vehicula lorem dapibus! Quisque facilisis vel tellus convallis placerat! Suspendisse at venenatis enim. Fusce ac massa porttitor, posuere sapien at, ornare diam. Integer mollis faucibus tempor. Etiam sit amet bibendum sem? Sed pellentesque magna vehicula ligula elementum placerat. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce a arcu lorem. Nam lorem tortor, luctus consequat ultrices semper, fringilla id augue. Suspendisse mollis quis nisl vel elementum. Ut tristique, lectus ac tincidunt mollis, massa diam dignissim massa, sed imperdiet nulla magna quis elit! Aenean id viverra enim. Curabitur dui ante, consectetur vel dui non, feugiat interdum lorem! Vivamus porttitor mattis lorem in rhoncus. Praesent dictum in urna et convallis. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin in leo nec enim volutpat scelerisque sit amet sed dolor. Fusce a elit sodales lacus condimentum placerat eget eget nisi. Quisque hendrerit est nec mattis vulputate. Suspendisse potenti. Ut aliquet elit eros. Sed dignissim diam ut vestibulum laoreet. Nulla varius tortor lacus, quis commodo eros dignissim vitae. Etiam ultrices in urna nec molestie. Mauris fringilla sodales hendrerit? Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Aenean non arcu in massa convallis commodo at ac sapien. Integer at risus accumsan, dignissim neque nec, pellentesque arcu. Quisque eu fringilla mauris. Cras ac elementum libero, vel pellentesque tellus.</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'search-all\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'73\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => NULL,
      \'path\' => array(
        \'pid\' => \'48\',
        \'source\' => \'node/45\',
        \'alias\' => \'search-all\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'201\',
      \'uid\' => \'1\',
      \'title\' => \'Science and research\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'1cce433c-fb81-4059-a614-fd5ffcaf7102\',
      \'nid\' => \'6\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442235\',
      \'changed\' => \'1395490504\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'f19767bf-03dc-4c10-880c-a0a4972a39a6\',
      \'revision_timestamp\' => \'1395490504\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>In this section you&#39;ll find details of the Agency&#39;s research projects and how to apply for research funding.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>In this section you\'ll find details of the Agency\'s research projects and how to apply for research funding.</p>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'The Agency commissions scientific research to ensure that our advice is based on the best and most up-to-date science. We also work with a number of independent scientific committees.\',
            \'format\' => NULL,
            \'safe_value\' => \'The Agency commissions scientific research to ensure that our advice is based on the best and most up-to-date science. We also work with a number of independent scientific committees.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => \'6\',
            \'uid\' => \'1\',
            \'filename\' => \'science.jpg\',
            \'uri\' => \'public://banner-image/science.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'13439\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'10b809b5-7267-40c8-8d5b-ff3a8f90223b\',
            \'field_file_image_alt_text\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'nice microscope\',
                  \'format\' => NULL,
                  \'safe_value\' => \'nice microscope\',
                ),
              ),
            ),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => \'nice microscope\',
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Subtitle here\',
            \'format\' => NULL,
            \'safe_value\' => \'Subtitle here\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'science-and-research\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_4\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'3\',
      \'current_revision_id\' => \'201\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Science & research\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-45\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'2\',
        \'source\' => \'node/6\',
        \'alias\' => \'science\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
