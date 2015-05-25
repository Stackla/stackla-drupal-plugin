/**
 * @file JS for Stackla field widget form.
 * @returns {undefined}
 */
(function($) {
  Drupal.behaviors.stackla_field = {
    attach: function(context) {
      var lookDetails = $('.look-details');
      var lookSelected = $('input.look-options:checked').next().next();
      lookDetails.insertAfter(lookSelected);
    }
  };
})(jQuery);
