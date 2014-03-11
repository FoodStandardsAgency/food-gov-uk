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
      \'vid\' => \'3\',
      \'uid\' => \'1\',
      \'title\' => \'Policy and advice\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'82152aa3-9ced-4f77-af40-a82e6b0fe875\',
      \'nid\' => \'3\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1391442141\',
      \'changed\' => \'1393377239\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'347a84d6-9e63-48bc-a5ef-3e7861750fe4\',
      \'revision_timestamp\' => \'1393377239\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Landing page</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => \'<p>Landing page</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Landing page summary\',
            \'format\' => NULL,
            \'safe_value\' => \'Landing page summary\',
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
      \'field_subtitle\' => array(),
      \'field_path\' => array(),
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1391442141\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'3\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'path\' => array(
        \'pid\' => \'5\',
        \'source\' => \'node/3\',
        \'alias\' => \'policy-advice\',
        \'language\' => \'und\',
      ),
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
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'5\',
      \'uid\' => \'1\',
      \'title\' => \'Enforcement and regulation\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'299c8247-3c1e-4a6b-808c-9285c4f924e0\',
      \'nid\' => \'5\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1391442205\',
      \'changed\' => \'1393377301\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'35faa675-ba52-4be4-9a85-66356897d121\',
      \'revision_timestamp\' => \'1393377301\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Landing page</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => \'<p>Landing page</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Landing page summary\',
            \'format\' => NULL,
            \'safe_value\' => \'Landing page summary\',
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
      \'field_path\' => array(),
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1391442205\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'5\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'path\' => array(
        \'pid\' => \'3\',
        \'source\' => \'node/5\',
        \'alias\' => \'enforcement\',
        \'language\' => \'und\',
      ),
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
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'2\',
      \'uid\' => \'1\',
      \'title\' => \'News and Updates\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'f5863bd6-662a-4fb9-823c-f8a5c02f8655\',
      \'nid\' => \'2\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1391442104\',
      \'changed\' => \'1393401345\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'6dd92932-f132-4138-8e61-ea7f947389e7\',
      \'revision_timestamp\' => \'1393401345\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Landing page.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => \'<p>Landing page.</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Landing page summary\',
            \'format\' => NULL,
            \'safe_value\' => \'Landing page summary\',
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
            \'value\' => \'Subtitle for news and updates is similar to comment field on old site\',
            \'format\' => NULL,
            \'safe_value\' => \'Subtitle for news and updates is similar to comment field on old site\',
          ),
        ),
      ),
      \'field_path\' => array(),
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1391442104\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'2\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'path\' => array(
        \'pid\' => \'6\',
        \'source\' => \'node/2\',
        \'alias\' => \'news-updates\',
        \'language\' => \'und\',
      ),
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
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'7\',
      \'uid\' => \'1\',
      \'title\' => \'About us\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'0e075023-6803-4090-88db-59622b3faeeb\',
      \'nid\' => \'7\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1391442261\',
      \'changed\' => \'1392978432\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'8502d102-914b-44f9-b355-29f3c237035b\',
      \'revision_timestamp\' => \'1392978432\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Landing page</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => \'<p>Landing page</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Landing page summary\',
            \'format\' => NULL,
            \'safe_value\' => \'Landing page summary\',
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
      \'field_subtitle\' => array(),
      \'field_path\' => array(),
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1391442261\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'7\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'path\' => array(
        \'pid\' => \'1\',
        \'source\' => \'node/7\',
        \'alias\' => \'about-us\',
        \'language\' => \'und\',
      ),
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1391441873\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'1\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'path\' => FALSE,
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
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'4\',
      \'uid\' => \'1\',
      \'title\' => \'Business and industry\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'8eb4d603-4ef2-4d38-b0fe-3d9771680471\',
      \'nid\' => \'4\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1391442166\',
      \'changed\' => \'1393377271\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'cd92ac88-8d94-4bbd-b4fe-5c1367140ab4\',
      \'revision_timestamp\' => \'1393377271\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Landing page</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => \'<p>Landing page</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Landing page summary\',
            \'format\' => NULL,
            \'safe_value\' => \'Landing page summary\',
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
      \'field_subtitle\' => array(),
      \'field_path\' => array(),
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1391442166\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'4\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'path\' => array(
        \'pid\' => \'4\',
        \'source\' => \'node/4\',
        \'alias\' => \'business-industry\',
        \'language\' => \'und\',
      ),
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
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'6\',
      \'uid\' => \'1\',
      \'title\' => \'Science and research\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'57da9b4d-8824-41b2-bdd4-2e6c88c9e01d\',
      \'nid\' => \'6\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1391442235\',
      \'changed\' => \'1393377332\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'f19767bf-03dc-4c10-880c-a0a4972a39a6\',
      \'revision_timestamp\' => \'1393377332\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Landing page</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => \'<p>Landing page</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Landing page summary\',
            \'format\' => NULL,
            \'safe_value\' => \'Landing page summary\',
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
      \'field_subtitle\' => array(),
      \'field_path\' => array(),
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
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1391442235\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'6\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'path\' => array(
        \'pid\' => \'2\',
        \'source\' => \'node/6\',
        \'alias\' => \'science\',
        \'language\' => \'und\',
      ),
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
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
