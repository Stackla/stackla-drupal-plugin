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
  <?php foreach ($filters as $delta => $filter): ?>
  <?php if(!empty($filter['title'])): ?>
  <div class="filter-<?php print $delta; ?> title">
    Filter: <?php print $filter['title']; ?>
  </div>
  <?php endif; ?>
  <?php endforeach; ?>
</div>

