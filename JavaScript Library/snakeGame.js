// Game Constants and Variables
let direction = {
    x: 0,
    y: 0,
};
const foodSound = new Audio('food.mp3');
const gameOver = new Audio('gameover.mp3');
const moveSound = new Audio('move.mp3');
const musicSound = new Audio('music.mp3');
let board = document.getElementById('board');
let Score = document.getElementById('score')
let speed = 5;
let lastPaintTime = 0;
let snakeArray = [
    { x: 13, y: 15 }
];
let food = { x: 6, y: 7 };
let inputDirection = { x: 0, y: 0 };
let score = 0;
// Game Functions
function main(currentTime) {
    window.requestAnimationFrame(main);
    if ((currentTime - lastPaintTime) / 1000 < 1 / speed) {
        return
    }
    lastPaintTime = currentTime;
    gameEngine();
}
function isCollide(snakeArray) {
    // if you bump into yourself
    for (let i = 1; i < snakeArray.length; i++) {
        if (snakeArray[i].x === snakeArray[0].x && snakeArray[i].y === snakeArray[0].y) {
            return true;
        }
    }
    if (snakeArray[0].x >= 18 || snakeArray[0].x <= 0 || snakeArray[0].y >= 18 || snakeArray[0].y <= 0) {
        return true;
    }
}
function gameEngine() {
    // Part 1: Updating the snake variable (Array)
    if (isCollide(snakeArray)) {
        gameOver.play();
        musicSound.pause();
        inputDirection = { x: 0, y: 0 };
        alert("Game Over. Press any key to play again!");
        snakeArray = [{ x: 13, y: 15 }];
        musicSound.play();
        score = 0;

    }
    // If you have eaten the food, Increment the score and regenerate food
    if (snakeArray[0].y === food.y && snakeArray[0].x === food.x) {
        foodSound.play();
        score += 1;
        Score.innerHTML = `Score : ${score}`;
        snakeArray.unshift({ x: snakeArray[0].x + inputDirection.x, y: snakeArray[0].y + inputDirection.y })
        let a = 2;
        let b = 16;
        food = { x: Math.round(a + (b - a) * Math.random()), y: Math.round(a + (b - a) * Math.random()) }
    }
    // Moving the snake
    for (let i = snakeArray.length - 2; i >= 0; i--) {
        snakeArray[i + 1] = { ...snakeArray[i] };
    }
    snakeArray[0].x += inputDirection.x;
    snakeArray[0].y += inputDirection.y;
    // Part 2: Render the snake and food
    // Display the Snake
    board.innerHTML = "";
    snakeArray.forEach((e, index) => {
        snakeElement = document.createElement('div');
        snakeElement.style.gridRowStart = e.y;
        snakeElement.style.gridColumnStart = e.x;
        if (index === 0) {
            snakeElement.classList.add('head');
        }
        else {
            snakeElement.classList.add('snake');

        }
        board.appendChild(snakeElement);
    })
    // Display the food
    foodElement = document.createElement('div');
    foodElement.style.gridRowStart = food.y;
    foodElement.style.gridColumnStart = food.x;
    foodElement.classList.add('food');
    board.appendChild(foodElement);


}





//Main Login
window.requestAnimationFrame(main);
window.addEventListener('keydown', e => {
    inputDirection = { x: 0, y: 1 }//Start the game
    moveSound.play();
    switch (e.key) {
        case 'ArrowUp':
            inputDirection.x = 0;
            inputDirection.y = -1;
            break;
        case 'ArrowDown':
            inputDirection.x = 0;
            inputDirection.y = 1;

            break;
        case 'ArrowLeft':
            inputDirection.x = -1;
            inputDirection.y = 0;

            break;
        case 'ArrowRight':
            inputDirection.x = 1;
            inputDirection.y = 0;

            break;
        default:
            break;
    }
    console.log(snakeArray[0])
})