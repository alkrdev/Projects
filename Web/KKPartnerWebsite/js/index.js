$(document).ready(function(){
	SetInitialRotatedObjects(-20, "51deg", "70deg")
});

function SetInitialRotatedObjects(rotation, gapModifier, rotateDegrees) {
	$("li.circleContent").css(
		"-webkit-transform", "skew(" + gapModifier + ")",
		"-moz-transform", "skew(" + gapModifier + ")",
		"-ms-transform", "skew(" + gapModifier + ")",
		"transform", "skew(" + gapModifier + ")"
	);

	$("li.circleContent a").css(
		"-webkit-transform", " skew(-" + gapModifier + ") rotate(-" + rotateDegrees + ")",
		"-moz-transform", "skew(-" + gapModifier + ") rotate(-" + rotateDegrees + ")",
		"-ms-transform", "skew(-" + gapModifier + ") rotate(-" + rotateDegrees + ")",
		"transform", "skew(-" + gapModifier + ") rotate(-" + rotateDegrees + ")"
	);

	for (let i = 1; i <= 9; i++) {
		$("li.circleContent:nth-child(" + i + ")").css(
			"-webkit-transform", "rotate(" + rotation + "deg) skew(" + gapModifier + ")",
			"-moz-transform", "rotate(" + rotation + "deg) skew(" + gapModifier + ")",
			"-ms-transform", "rotate(" + rotation + "deg) skew(" + gapModifier + ")",
			"transform", "rotate(" + rotation + "deg) skew(" + gapModifier + ")"
		);
		rotation += 40;
	};
};

$(".circleContent").hover(
    
    function () {
        console.log("HOVERED")
		$("#content").text(
			$( this ).text()
		)
	}, 
    function () {
        console.log("HOVERED")
		$("#content").text(
			"KK-Partner"
		)
	}
);
