<?php

/**
 * @file: Stackla Field template
 *
 * Available variables:
 *  $data: array of all unserialised data from the field.
 *  $filters : render array of filters, or empty array if not present.
 *
 */
?>
<div class="stackla">
  <?php if(!empty($filters)) : ?>
  <div class="filters">
  <?php print(render($filters)); ?>
    </div>
  <?php endif; ?>
  <?php if (!empty($data['look_and_feel']['embed_code'])): ?>
  <div class="stackla-widget-wrapper">
    <?php print $data['look_and_feel']['embed_code'];?>
  </div>
  <?php endif; ?>
</div>

