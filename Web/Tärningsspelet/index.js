window.hasNotLostYet = true;
window.completeTotal = 0;
window.numberOfJumps = 0;

$(document).ready(function(){  
    // Empty
});

$(".diceButton").click(function() {        
    ResetGameValues();    

    let mymap = { oneDice: 1, twoDice: 2, treeDice: 3, fourDice: 4, fiveDice: 5 }
    ThrowTheDice(mymap[this.id]);
})

$("#startButton").click(function() {
    ToggleDiceButtons();  
    $("#startButton").hide();
})

$("#restartButton").click(function() {
    $("#numberContainer").text("Hej, välkommen till Tärningsspelet\!" + 
    " Du får välja hur många tärningar du vill kasta med och om du lyckas få en 6:a så kommer du att automatiskt få rulla två tärningar till\." + 
    " När du inte får nummer 6 från någon tärning så får du starta om eller stänga programmet - Lycka till !");   

    HideDiceButtons(); 
    ResetGameInterface();    
    ResetValuesToStart();
})

$("#quitButton").click(function(){
    $("body").hide();
})

function ThrowTheDice(amount) {
    var a = [];
    var b = [];

    for (let i = 0; i < amount; i++) {
        a.push(getRandom(6));
        b.push(a[i] != 6 ? a[i] : 0);
    }

    IncrementJumpsBy(amount);
    thereIsASix = SearchForSix(a, amount);
    sumOfAllNumbers = AddUpNumbers(b, amount);
    $("#numberContainer").text("This is your number:" + AddExtraText(a, amount))

    HideDiceButtons();

    // Show sum of all numbers
    $("#sumOfNumbers").text(sumOfAllNumbers)

    // Add up to total sum
    window.completeTotal += sumOfAllNumbers;

    HandleOutcome(a, b);

    return a;
}

function AddExtraText(array, reach) {
    var additionalText = "";
    for (let i = 0; i < reach; i++) {
        additionalText += " " + array[i];
    }
    return additionalText;
}

function AddUpNumbers(array, reach) {
    var sum = 0;
    for (let i = 0; i < reach; i++) {
        sum += array[i];
    }
    return sum;
}

function SearchForSix(array, reach) {
    for(let i = 0; i < reach; i++) {
        if (array[i] == 6) return true;
    }
    return false;
}

function HandleOutcome(array, newArray) {
    if (thereIsASix) { 
        array[2] = 0;
        array[3] = 0;
        array[4] = 0;

        console.log(array[2])
        console.log(array[3])
        console.log(array[4])

        $("#congratulatoryText").toggle();

        timeout(array, newArray);            
    } else {            
        HideDiceButtons();

        $(".endingButtons").toggle();

        ShowEndResult();
    }
}

function ShowEndResult() {
    var completeTotalText = "Summan av de nummer du har fått är: " + window.completeTotal;
    var totalJumpsText = "Den totala antal gånger du lyckades rulla dina tärningar: " + window.numberOfJumps;

    $("#endSum").text(completeTotalText + "\n" + totalJumpsText);
}

function twoDiceRollFixed() {
    if (!SearchForSix(ThrowTheDice(2), 2)) {
        window.hasNotLostYet = false;
        $("#congratulatoryText").hide();
        ShowEndResult();
    } 
}

function getRandom(upper) {
    let randomNumber = Math.floor(Math.random() * upper ) + 1;
    return randomNumber;
}

function timeout() {
    if (window.hasNotLostYet) {
        setTimeout(function () {
            twoDiceRollFixed()            
            timeout();
        }, 3000);
        $("#congratulatoryText").show();
    } else {
        HideDiceButtons();
        $(".endingButtons").show();
    }
}  

function ToggleDiceButtons () {
    $("#oneDice").toggle();
    $("#twoDice").toggle();
    $("#threeDice").toggle();
    $("#fourDice").toggle();
    $("#fiveDice").toggle();
}

function HideDiceButtons () {  
    $("#oneDice").hide();
    $("#twoDice").hide();
    $("#threeDice").hide();
    $("#fourDice").hide();
    $("#fiveDice").hide();
}

function ResetGameInterface () {
    $("#sumOfNumbers").text("-------------")     
    $(".endingButtons").hide();
    $("#congratulatoryText").hide();
    $("#startButton").show();  
    $("#endSum").text(" ");
}

function ResetValuesToStart () {    
    ResetGameValues();
    ResetGameGlobalValues();
}

function ResetGameGlobalValues () {
    window.hasNotLostYet = true;
    window.completeTotal = 0;
    window.numberOfJumps = 0;
}

function ResetGameValues () {
    sumOfAllNumbers = 0;
    thereIsASix = false;
}

function IncrementJumpsBy (value) {
    window.numberOfJumps = window.numberOfJumps + value;
}