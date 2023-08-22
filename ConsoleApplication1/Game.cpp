#include "Game.h"
#include <chrono>
#include <thread>
Game::Game(int h, int w, int startX, int startY):board(h, w),snake(startX, startY) {
	isRunning = false;
}

void Game::startGame() {
	isRunning = true;
    board.placeSnake(snake);
    board.update();
	while(isRunning) {
		if(snake.checkCollision()) isRunning = false;
        handleInput();
        snake.move();
        board.placeSnake(snake);
		board.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Game::handleInput() {
    char userInput = _getch();
    if (userInput == 0 || userInput == 224) {
        userInput = _getch(); // Get the extended key code
        switch (userInput) {
        case 72: // Up arrow
            snake.changeDirection(Direction::UP);
            break;
        case 80: // Down arrow
            snake.changeDirection(Direction::DOWN);
            break;
        case 75: // Left arrow
            snake.changeDirection(Direction::LEFT);
            break;
        case 77: // Right arrow
            snake.changeDirection(Direction::RIGHT);
            break;
        }
    }
}


