(function($) {

	Drupal.behaviors.studentCRMBlocks = {
	
		attach : function() {
			if(!$('.ajax-loader').length) {
				return;
			}
			var seperator = (window.location.href.search('[?]') == -1) ? '?' : '&';
			$.get(window.location + seperator + 'ajaxBlocks=1', function(data) {
				$('.ajax-loader').each(function() {
					$(this).html($($(this).attr('data-selector'), $(data)));
				});
			});
			
		},
	};

})(jQuery);