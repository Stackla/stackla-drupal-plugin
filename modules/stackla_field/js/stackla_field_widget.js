/**
 * @file
 * JS for Stackla field widget form.
 *
 * @returns {undefined}
 */

(function ($) {
  'use strict';

  Drupal.behaviors.stackla_field = {
    attach: function (context) {
      $('.look-options input[value=new]')
        .parent().addClass('st-widgetType st-widgetType-new' + ($('.look-options input[value=new]').is(':checked') ? ' on' : ''));
      $('.look-options input[value=derive]')
        .parent().addClass('st-widgetType st-widgetType-derive' + ($('.look-options input[value=derive]').is(':checked') ? ' on' : ''));
      $('.look-options input[value=clone]')
        .parent().addClass('st-widgetType st-widgetType-clone' + ($('.look-options input[value=clone]').is(':checked') ? ' on' : ''));

      $('.look-options input[type=radio]')
        .change(function (e) {
          $(this).parent().parent().find('.on').removeClass('on');
          if ($(this).is(':checked')) {
            $(this).parent().addClass('on');
          }
        });
      $('.look-details input[value=base_waterfall]').parent().addClass('st-widgetStyle st-widgetStyle-base_waterfall');
      $('.look-details input[value=base_carousel]').parent().addClass('st-widgetStyle st-widgetStyle-base_carousel');
      $('.look-details input[value=base_billboard]').parent().addClass('st-widgetStyle st-widgetStyle-base_billboard');
      $('.look-details input[value=base_feed]').parent().addClass('st-widgetStyle st-widgetStyle-base_feed');
      $('.look-details input[value=base_slideshow]').parent().addClass('st-widgetStyle st-widgetStyle-base_slideshow');
      $('.look-details input[type=radio]')
        .change(function (e) {
          $('.st-delete-old-widget').closest('.delete-options').removeClass('st-hide');
        });
    }
  };
})(jQuery);
