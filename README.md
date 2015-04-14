# Stackla Drupal integration.

## Overview
Stackla is [stackla description here].
This module allows you to integrate Stackla Widgets into your Drupal site.
Currently a 'Stackla Widget' field type is supported, that can be added to any
fieldable entity. The widget options can be configured on the field, and the
resultant widget will be displayed.
More integrations are planned!

## Requirements
* Libraries API: https://www.drupal.org/project/libraries
* PHP xxx or greater is required for the Stackla SDK library.

## Installation

### Install via drush
1. Download the module
> drush dl stackla
2. Enable the module:
> drush en stackla
3. Download the SDK Library:
> drush stackla-sdk [optional: the path to your libraries folder, defaults to
/sites/all/libraries]

### Install manually
1. Download and extract this module to your Drupal installation. The usual
location is /sites/all/modules
2. Download and install the Stackla SDK Library to your libraries folder. The
usual location is /sites/all/libraries [download URL, drush instructions]
3. Download and install the libraries module if required:
https://www.drupal.org/project/libraries

## Usage