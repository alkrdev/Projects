$(document).ready(function(){
    
    var rows = [
        $("#topRowFirst"),    $("#topRowSecond"),    $("#topRowThird"), 
        $("#middleRowFirst"), $("#middleRowSecond"), $("#middleRowThird"), 
        $("#bottomRowFirst"), $("#bottomRowSecond"), $("#bottomRowThird")
    ];
    
    var rowGrid = [
        [1, 2, 3,  4, 5, 6,  7, 8, 9],
        [4, 5, 6,  7, 8, 9,  1, 2, 3],
        [7, 8, 9,  1, 2, 3,  4, 5, 6],

        [2, 3, 4,  5, 6, 7,  8, 9, 1],
        [5, 6, 7,  8, 9, 1,  2, 3, 4],
        [8, 9, 1,  2, 3, 4,  5, 6, 7],

        [3, 4, 5,  6, 7, 8,  9, 1, 2],
        [6, 7, 8,  9, 1, 2,  3, 4, 5],
        [9, 1, 2,  3, 4, 5,  6, 7, 8]
    ];

    window.currentlySelected = "";
    
    UnselectAndSelect(".selectorButton", rows);
    //for (var x = 0; x < 9; x++) console.log(rowGrid[x]); 
    GeneratePuzzle(rowGrid, rows);

    // Decremental generation
    // Go through all quadrants randomly, 
    // Remove a number
    // until enough numbers have been removed.
    
    PlaceNewNumber(rows);
})

function FillVisibleBoard (rows, rowGrid) {
    for (var x = 0; x < 9; x++) {
        for (var y = 0; y < 9; y++) {
            var elements = rows[x].children();
            //console.log((x+1) + ":" + (y+1))
            elements[y].innerHTML = rowGrid[x][y];
        }
    }
}

function GeneratePuzzle (rowGrid, rows) {    
    var repeats = 100;
    for (var x = 0; x < repeats; x++) SwapRandomNumberPairs(rowGrid, rows);
    for (var x = 0; x < repeats; x++) SwapRandomVerticalLines(rowGrid, rows);
    for (var x = 0; x < repeats; x++) SwapRandomVerticalSections(rowGrid, rows); 
    for (var x = 0; x < repeats; x++) SwapRandomHorizontalLines(rowGrid, rows); 
    for (var x = 0; x < repeats; x++) SwapRandomHorizontalSections(rowGrid, rows); 
}

function SwapRandomHorizontalSections(rowGrid, rows) {
    FillVisibleBoard(rows, rowGrid);
    alert("SwapRandomHorizontalSections");     
    var random = Math.floor((Math.random() * 3) + 1);
    var s1 = Math.floor((Math.random() * 3) + 1);
    var s2 = s1 == 1 ? (random == 0 ? 2 : 3) : s1 == 2 ? (random == 0 ? 1 : 3) : (random == 0 ? 1 : 2);    
    var tmpBoard = copyBoard(rowGrid);

    for (var x = 0; x < 9; x++) {
        for (var y = 3; y > 0; y--) {            
            rowGrid[(s1 * 3) - y] = tmpBoard[(s2 * 3) - y];
            rowGrid[(s2 * 3) - y] = tmpBoard[(s1 * 3) - y];
        }
    }
}

function SwapRandomHorizontalLines(rowGrid, rows) {
    FillVisibleBoard(rows, rowGrid);
    alert("SwapRandomHorizontalLines"); 
    var random = Math.floor((Math.random() * 3) + 1);
    var s1 = Math.floor((Math.random() * 3) + 1);
    var s2 = s1 == 1 ? (random == 0 ? 2 : 3) : s1 == 2 ? (random == 0 ? 1 : 3) : (random == 0 ? 1 : 2);    
    var tmpBoard = copyBoard(rowGrid);

    for (var x = 0; x < 9; x++) {
        rowGrid[(s1 * 3) - 1] = tmpBoard[(s2 * 3) - 1];
        rowGrid[(s2 * 3) - 1] = tmpBoard[(s1 * 3) - 1];
    }
}

function SwapRandomVerticalSections(rowGrid, rows) {
    FillVisibleBoard(rows, rowGrid);
    alert("SwapRandomVerticalSections");       
    var random = Math.floor((Math.random() * 3) + 1);
    var s1 = Math.floor((Math.random() * 3) + 1);
    var s2 = s1 == 1 ? (random == 0 ? 2 : 3) : s1 == 2 ? (random == 0 ? 1 : 3) : (random == 0 ? 1 : 2);    
    var tmpBoard = copyBoard(rowGrid);

    for (var x = 0; x < 9; x++) {
        for (var y = 3; y > 0; y--) {
            rowGrid[x][(s1 * 3) - y] = tmpBoard[x][(s2 * 3) - y];
            rowGrid[x][(s2 * 3) - y] = tmpBoard[x][(s1 * 3) - y];
        }
    }
}

function SwapRandomVerticalLines(rowGrid, rows) { 
    FillVisibleBoard(rows, rowGrid);   
    alert("SwapRandomVerticalLines");
    var random = Math.floor((Math.random() * 3) + 1);
    var s1 = Math.floor((Math.random() * 3) + 1);
    var s2 = s1 == 1 ? (random == 0 ? 2 : 3) : s1 == 2 ? (random == 0 ? 1 : 3) : (random == 0 ? 1 : 2);
    var tmpBoard = copyBoard(rowGrid);

    var firstIndexPosition = Math.floor(s1 * 3) - random;
    var secondIndexPosition = Math.floor(s2 * 3) - random;

    for (var x = 0; x < 9; x++) {
        rowGrid[x][firstIndexPosition] = tmpBoard[x][secondIndexPosition];
        rowGrid[x][secondIndexPosition] = tmpBoard[x][firstIndexPosition];
    }
}

function SwapRandomNumberPairs(rowGrid, rows) {
    FillVisibleBoard(rows, rowGrid);    
    alert("SwapRandomNumberPairs");
    for (var _ = 0; _ < 48; _++) {
        var n1 = Math.ceil(Math.random() * 9);
        var n2;
        do {
            n2 = Math.ceil(Math.random() * 9);
        } while (n1 == n2);
        for (var row = 0; row < 9; row++) {
            for (var col = 0; col < 9; col++) {
                if (rowGrid[row][col] == n1) {
                    rowGrid[row][col] = n2;
                }
                else if (rowGrid[row][col] == n2) {
                    rowGrid[row][col] = n1;
                }
            }
        }
    }
}

function copyBoard(board) {
    var newBoard = new Array();
    for(var i = 0; i < board.length; i++) {
        newBoard[i] = new Array();
        for(var j = 0; j < board[i].length; j++) {
            newBoard[i][j] = board[i][j];
        }
    }
    return newBoard;
}

function isNumberLegal(x, y, board, n) {
    for(var _x = 0; _x < 9; _x++) {
        if(_x == x) continue;
        if(board[_x][y] == n) return false;
    }

    for(var _y = 0; _y < 9; _y++) {
        if(_y == y) continue;
        if(board[x][_y] == n) return false;
    }

    const sectionX = Math.floor(x/3);
    const sectionY = Math.floor(y/3);

    for(var _x = 0; _x < 3; _x++) {
        for(var _y = 0; _y < 3; _y++) {
            const __x = sectionX * 3 + _x;
            const __y = sectionY * 3 + _y;
            if(__x == x) continue;
            if(__y == y) continue;
            if(board[__x][__y] == n) return false;
        }
    }

    return true;
}

class CrossInspector {
    constructor(className, parent, index, rows) {
        this.className = className;
        this.parent = parent;
        this.index = index;
        this.rows = rows;
    }

    ExamineSection() {
        // We're examining on section of elements
        var sectionOfElements = document.getElementsByClassName(this.className);

        // Every single one of the elements
        for (var i = 0; i < 9; i++) {
            var boxNumber = sectionOfElements[i].innerHTML;
            if (boxNumber == window.currentlySelected) return true;
        }
        return false;
    }

    ExamineHorizontal() {
        // We're examining one row
        var children = this.parent.children();

        // Every single column
        for (var i = 0; i < 9; i++) {
            var boxNumber = children[i].innerHTML;
            if (boxNumber == window.currentlySelected) return true;
        } 
        return false;
    }

    ExamineVertical() {        
        // One time each
        for (var i = 0; i < 9; i++) {
            var boxNumber = this.rows[i].children()[this.index].innerHTML;
            if (boxNumber == window.currentlySelected) return true;
        } 
        return false;
    }    
}

function PlaceNewNumber(rows) {
    alert("PlaceNewNumber");
    $("td").click(function () {
        var className = $(this).attr('class');
        var parent = $(this).parent();
        var index = $(this).index();

        const CI = new CrossInspector(className, parent, index, rows);

        var intersects = CI.ExamineHorizontal() || CI.ExamineVertical() || CI.ExamineSection();
        var isNotSelector = className != "selectorButton";

        if (intersects && isNotSelector) {
            console.log("You are not allowed to put this number here");
        }
        else {
            $(this).html(window.currentlySelected);
        }
    });
}

function UnselectAndSelect(element) {
    alert("UnselectAndSelect");
    $(element).click(function(){
        // Set all other boxes to non-lit
        $(element).css("box-shadow", "inset 0px 0px 0px 1px");
        // Highlight the clicked box
        $(this).css("box-shadow", "inset 0px 0px 0px 3px");
        // Take value of clicked box
        window.currentlySelected = $(this).html();
    });
}