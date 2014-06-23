/*
 Copyright (c) 2003-2013, CKSource - Frederico Knabben. All rights reserved.
 For licensing, see LICENSE.html or http://ckeditor.com/license
 */

/*
 * This file is used/requested by the 'Styles' button.
 * The 'Styles' button is not enabled by default in DrupalFull and DrupalFiltered toolbars.
 */
if (typeof(CKEDITOR) !== 'undefined') {
  CKEDITOR.addStylesSet('drupal',
    [
      /* Block Styles */

      // These styles are already available in the "Format" drop-down list, so they are
      // not needed here by default. You may enable them to avoid placing the
      // "Format" drop-down list in the toolbar, maintaining the same features.

      //{ name : 'Paragraph'		, element : 'p' },
      

      /* Inline Styles */
			// { name: 'Text align: Left', element: 'p', attributes: { 'class': 'text-align-left' } },
      { name: 'Guidance: highlight', element: 'div', attributes: { 'class': 'guidance' } },
      { name: 'Section: heading', element: 'h2', attributes: { 'class': 'section-heading' } },
 

      /* Object Styles */
      // {
      //  name:       'Image: Left',
      //  element:    'img',
      //  attributes: {
      //    'style':  'padding: 0px; margin-right: 20px; margin-bottom: 15px; float: left;',
      //    'border': '0'
      //  }
      // },

       name:       'Row: apply grey background',
        element:    'tr',
        attributes: {
          'class': 'alt'
        }
      },
      name:       'Row: no left border',
        element:    'td',
        attributes: {
          'class': 'first'
        }
      },

    ]);
}
