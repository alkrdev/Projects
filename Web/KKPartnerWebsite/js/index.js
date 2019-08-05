$(document).ready(function(){
	SetInitialRotatedObjects(-20, "51deg", "70deg")
});

function SetInitialRotatedObjects(rotation, gapModifier, rotateDegrees) {
	$(".csstransforms .nav li").css(
		"-webkit-transform", "skew(" + gapModifier + ")",
		"-moz-transform", "skew(" + gapModifier + ")",
		"-ms-transform", "skew(" + gapModifier + ")",
		"transform", "skew(" + gapModifier + ")"
	);

	$(".csstransforms .nav li a").css(
		"-webkit-transform", " skew(-" + gapModifier + ") rotate(-" + rotateDegrees + ") scale(1)",
		"-moz-transform", "skew(-" + gapModifier + ") rotate(-" + rotateDegrees + ") scale(1)",
		"-ms-transform", "skew(-" + gapModifier + ") rotate(-" + rotateDegrees + ") scale(1)",
		"transform", "skew(-" + gapModifier + ") rotate(-" + rotateDegrees + ") scale(1)"
	);

	for (let i = 1; i <= 9; i++) {
		$(".csstransforms .nav li:nth-child(" + i + ")").css(
			"-webkit-transform", "rotate(" + rotation + "deg) skew(" + gapModifier + ")",
			"-moz-transform", "rotate(" + rotation + "deg) skew(" + gapModifier + ")",
			"-ms-transform", "rotate(" + rotation + "deg) skew(" + gapModifier + ")",
			"transform", "rotate(" + rotation + "deg) skew(" + gapModifier + ")"
		);
		rotation += 40;
	};
};

$( "li" ).hover(
	function() {
		$(".content").text(
			$( this ).text()
		)
	}, 
	function() {
		$(".content").text(
			"KK-Partner"
		)
	}
);
