# Stackla Drupal integration.

## Overview
Stackla is [stackla description here].
This module allows you to integrate Stackla Widgets into your Drupal site.
Currently a 'Stackla Widget' field type is supported, that can be added to any
fieldable entity. The widget options can be configured on the field, and the
resultant widget will be displayed.
More integrations are planned!

## Requirements
* Stackla Account
* php-cUrl
* Composer Manager API: https://www.drupal.org/project/composer_manager
* Encrypt project: https://www.drupal.org/project/encrypt
* PHP 5.3 or greater is required for the Stackla SDK library.

## Installation

### Install via drush
1. Read the "Installation and Usage For Site Builders" for https://drupal.org/project/composer_manager

2. Enable Stackla module
```
$ drush en stackla
```

3. Install/Update dependencies
```
$ drush composer-manager install / update
```

### Install manually
1. Download and extract this module to your Drupal installation. The usual
location is /sites/all/modules
2. Enable Stackla Core and Stackla Field modules
3. Navigate to Composer Manager's configuration page, click on "Rebuild composer.json file"
4. Install / update dependencies using drush
```
$ drush composer-manager install / update
```

### Create an app in Stackla

## Permissions
To use stackla widgets on your site, you must assign appropriate permissions to
your content managers. There are two permssions available:

### Administer Stackla
This allows a user to configure Stackla API settings, and to create and edit
stackla widgets on the site.

### Use Stackla
This allows a user to create and edit stackla widgets on the site, but not to
configure Stackla API settings.

## Authentication with Stackla

