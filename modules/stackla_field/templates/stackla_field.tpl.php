<?php

/**
 * @file: Stackla Field template
 *
 * Available variables:
 *
 *
 */
?>
<div class="stackla-field">
  Stackla field template.
  <?php if(!empty($filters)) : ?>
  <div class="filter-label">Filters:</div>
  <?php print(render($filters)); ?>
  <?php endif; ?>
  <div class="stackla-widget">
    Widget output here.
  </div>
</div>

