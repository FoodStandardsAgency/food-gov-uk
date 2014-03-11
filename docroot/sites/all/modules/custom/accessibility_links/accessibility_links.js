jQuery(document).ready(function($) {
	
	$("#fontScale0").click(function(){
		$("body").removeClass("font-plus-1");
		$("body").removeClass("font-plus-2");
	});
	
	$("#fontScale1").click(function(){
	  $("body").addClass("font-plus-1");
		$("body").removeClass("font-plus-2");
	});
	
	$("#fontScale2").click(function(){
	  $("body").addClass("font-plus-2");
		$("body").removeClass("font-plus-1");
	});
	
});

