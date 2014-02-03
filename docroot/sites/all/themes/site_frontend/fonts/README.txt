NOTE: The fonts in this directory are only here as a backup reference.
Please see notes below on how the custom fonts were implemented.


===================================================
How to setup custom fonts with fontyourface module
===================================================

* Install fontyourface module and enable fontyourface, fontyourface ui and local fonts modules.

* Hop over to http:www.fontsquirrel.com/tools/webfont-generator and convert your fonts to multiple formats (select "normal" option when converting - and the formats we need are ttf, eot, woff and svg). You will then receive a download kit.

* Open the downloaded font kit - we will only need the files matching the above mentioned extensions - you can ignore everything else)

* Go to admin/config/user-interface/fontyourface/local_fonts and upload your fonts. Give your font a name (same name as your font - of course), select a font style and a font weight to associate your font with. Click confirm. Repeat this process for each different kind of font you have. Example: I called the first font "Foco" and uploaded foco_bd.ttf, foco_bd.eot, foco_bd.woff and foco_bd.svg and selected font style normal and font weight bold/ I then repeated the same process, using the same font name "Foco" and uploaded foco_rg.ttf, foco_rg.eot, foco_rg.woff and foco_rg.svg. Note: Important to name same font but different weight with exactly the same name. PS. Fontyourface module will then apen the selected style and selected weight to your font name.

* Now go to appearance/fontyourface/browse/local_fonts and enable your fonts (there is a link for this under each font).

* Then go to admin/appearance/fontyourface and set default css selectors if need be. I just set them for h-tags and left the rest up to our style sheet. Then click "save applied CSS selectors)

* Now clear that damn cache!

* To use the fonts, add the font to style sheet like any other font. Font-family: Foco; font-weight: bold; or font-weight: normal; PS. Do not add in src files to fonts in the CSS files - fontyourface module will take care of all of this.