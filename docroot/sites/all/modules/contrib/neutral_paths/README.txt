*** Summary ***

A tiny module for localized web sites. Frequently different users
have different language preferences. Not anyone, for example, is satisfied
with administration pages translation.

This creates an inconvenience, namely, all automatically generated path aliases
are invisible to such users, they see regular /node/xxx.

This module solves this by fixing all the aliases to be language neutral.

*** Installation & configuration ***

Install module as usual. After installation go to configuration
page (admin/config/search/path/language_settings).

There statistics for path alias languages is displayed. You can reset
all the aliases referring to nodes, taxonomy terms and users to be language
neutral. There is also a possibility to set a language of node path aliases
to match that of node. No such functionality for other entity types yet.

Also you can configure the module to automatically reset language settings
for newly created nodes, terms and users.
