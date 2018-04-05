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


      /* Inline Styles */
      // { name: 'Section', element: 'h2', attributes: { 'class': 'inline-section-heading' } },
			{ name : 'Paragraph', element : 'p' },
      { name : 'Heading 3', element : 'h3' },
      { name : 'Heading 4', element : 'h4' },
      { name : 'Heading 5', element : 'h5' },
      { name : 'Heading 6', element : 'h6' },
      { name: 'Guidance', element: 'div', attributes: { 'class': 'guidance' } },
      { name: 'Training', element: 'div', attributes: { 'class': 'training' } },
      { name: 'Science', element: 'div', attributes: { 'class': 'science moreInfo' } },

      /* Object Styles */
      // {
      //  name:       'Image: Left',
      //  element:    'img',
      //  attributes: {
      //    'class':  'image-left'
      //  }
      // },
      // {
      //  name:       'Table: Pricing',
      //  element:    'table',
      //  attributes: {
      //    'class': 'table-pricing'
      //  }
      // }

      {
        name:       'Image: Left',
        element:    'img',
        attributes: {
          'style':  'padding: 0px; margin-right: 17px; margin-bottom: 10px; float: left;',
          'border': '0'
        }
      },

      {
        name:       'Image: Right',
        element:    'img',
        attributes: {
          'style':  'padding: 0px; margin-left: 17px; margin-bottom: 10px; float: right;',
          'border': '0'
        }
      }

    ]);
}
