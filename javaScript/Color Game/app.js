/*Functions */
//init
function init() {
    //Event listerners for Stripe Buttons
    butReset.addEventListener("click", newGame);
    //sets up mode buttons
    setupModeButtons();
    //display correct number of squares
    toggleSquares();
    //sets up even listeners for squares
    setupSquares();
    //begin game
    newGame();
}

//setup Mode Buttons
function setupModeButtons() {
    //loops through modebuttons array and adds event listeners to each
    for (var i = 0; i < modeButtons.length; i++) {
        modeButtons[i].addEventListener("click", function () {
            //sets css depending on which mode button selected
            modeButtons[0].classList.remove("selected");
            modeButtons[1].classList.remove("selected");
            modeButtons[2].classList.remove("selected");
            this.classList.add("selected");
            //sets num sqaures based on mode selected
            this.textContent === "Easy" ? numSquares = 3 : this.textContent === "Hard" ? numSquares = 6 : numSquares = 9;
            //generate new game
            newGame();
        });
    }
}

//adds event listeners and styling based on colors array to squares
function setupSquares() {
    //adds event listeners to squares
    for (var i = 0; i < squares.length; i++) {
        //add colors to squares based on colors array
        squares[i].style.backgroundColor = colors[i];
        //add click listeners to squares
        squares[i].addEventListener("click", function () {
            //grab color of clicked square
            var clickedColor = this.style.backgroundColor;
            //compare clickedColor to pickedColor
            if (clickedColor === pickedColor) {
                messageDisplay.textContent = "Correct!";
                changeColors(clickedColor);
                h1.style.backgroundColor = clickedColor;
                butReset.textContent = "Play Again?";
            } else {
                this.style.backgroundColor = "#232323";
                messageDisplay.textContent = "Try Again!";
            }
        });
    }
}

//reset/starts game
function newGame() {
    //define variables
    //generate random colors array with numSquares setting the number of colors to generate
    colors = generateRandomColors(numSquares);
    //choose winning color string (format is "rbg(000, 000, 000")
    pickedColor = pickColor();
    //display rbg value of picked color
    colorDisplay.textContent = pickedColor;
    //change background color of h1 to match body
    h1.style.backgroundColor = "steelblue";
    //change button text to default 
    butReset.textContent = "New Colors";
    //change message text to default
    messageDisplay.textContent = "";
    //displays squares based on numsquares
    toggleSquares();
    //sets up even listeners for squares
    setupSquares();
}

//changes all squares to passed color
function changeColors(color) {
    //loop all squares
    for (var i = 0; i < squares.length; i++) {
        //change each color to match given color
        squares[i].style.backgroundColor = color;
    }
}

//selects random color from colors array to be winning color
function pickColor() {
    //generate random number
    var random = Math.floor(Math.random() * colors.length);
    return colors[random];
}

//generates random colors and adds to array arr, returns arr
function generateRandomColors(amount) {
    //make array
    var arr = [];
    //add amount colors to array
    for (var i = 0; i < amount; i++) {
        //get random color
        //push into array
        arr.push(randomColor());
    }
    //return array
    return arr;
}

//generate random color in rgb format
function randomColor() {
    //pick a red from 0 - 255
    var red = Math.floor(Math.random() * 256);
    //pick a green from 0 - 255
    var green = Math.floor(Math.random() * 256);
    //pick a blue from 0 - 255
    var blue = Math.floor(Math.random() * 256);
    var colorString = "rgb(" + red + ", " + green + ", " + blue + ")";

    return colorString;
}

//toggles class "notDisplayed" depending on which mode is selected and which mode is currently active
function toggleSquares() {
    //set all squares to not display
    for (var i = 0; i < squares.length; i++) {
        squares[i].classList.add("notDisplayed");
    }
    //set display based on num squares
    if (numSquares === 3) {
        for (var i = 0; i < 3; i++) {
            squares[i].classList.remove("notDisplayed");
        }
    } else if (numSquares === 6) {
        for (var i = 0; i < 6; i++) {
            squares[i].classList.remove("notDisplayed");
        }
    } else if (numSquares === 9){
        for (var i = 0; i < squares.length; i++) {
            squares[i].classList.remove("notDisplayed");
        }
    }
}

//Code Beings


//globals
var colors = [];
var pickedColor;
var numSquares = 6;

//DOM selectors
var squares = document.querySelectorAll(".square");
var colorDisplay = document.getElementById("colorDisplay");
var messageDisplay = document.querySelector("#message");
var h1 = document.querySelector("h1");
var butReset = document.querySelector("#new");
var modeButtons = document.querySelectorAll(".mode");

//Initial Game Load
init();