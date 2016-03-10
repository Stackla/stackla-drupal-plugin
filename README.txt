CONTENTS OF THIS FILE
---------------------

* Introduction
* Requirements
* Installation
* Configuration
* FAQ
* Maintainers


INTRODUCTION
------------

Stackla (https://stackla.com) is a social content marketing platform used by
hundreds of global brands, agencies, media companies, and nonprofits to
discover, curate and publish the best content from the social web.

This module allows you to integrate Stackla Widgets into your Drupal site.
Currently a 'Stackla Widget' field type is supported, that can be added to any
fieldable entity. The widget options can be configured on the field, and the
resultant widget will be displayed.


REQUIREMENTS
------------

This module requires the following modules:

* Stackla Account (https://stackla.com)
* PHP-cURL (http://php.net/manual/en/book.curl.php)
* Composer Manager (https://www.drupal.org/project/composer_manager)
* Encrypt (https://www.drupal.org/project/encrypt)
* PHP 5.3 or greater is required for the Stackla SDK library.


INSTALLATION
------------

 * Follow the standard Drupal module installation
   (https://drupal.org/documentation/install/modules-themes) process

 * Install via Drush (Recommended)
    * `drush en stackla` to enable Stackla module

 * Install manually
    * Download (http://drupal.org/project/stackla) and extract this module to
      your Drupal installation. The usual location is `/sites/all/modules`
    * Enable Stackla Core and Stackla Field modules
    * Navigate to Composer Manager's configuration page, click on "Rebuild
      composer.json file"

 * Maintaining Dependencies
   Install/Update dependencies `drush composer-manager install` or
   `drush composer-manager update`.
   For more information please refer to Composer Manager documentation
   (https://www.drupal.org/node/2405807)


CONFIGURATION
-------------

 * Authentication
   Before continue with the configuration or use thie module integration, you
   need to have 'Drupal Plugin' installed in Stackla admin portal. This step
   will allow you to get the information that is needed for configure and
   authenticate with Stackla.

 * Permission
   To use Stackla widgets on your site, you must assign appropriate permissions
   to your content managers. There are two permssions available:

 * Administer Stackla
   This allows a user to configure Stackla API settings, and to create and edit
   Stackla widgets on the site.

 * Use Stackla
   This allows a user to create and edit stackla widgets on the site, but not
   to configure Stackla API settings.


FAQ
---
Q: Do I need a Stackla account?

A: Yes. A Stackla account is required to display social content using this
   plugin. More information is available at https://stackla.com


Q: Which social networks are supported?

A: Twitter, Facebook, Instagram, YouTube and Google+


MAINTAINERS
-----------

Current maintainers:
 * Helman Budianto (helman) - https://drupal.org/user/2808213
