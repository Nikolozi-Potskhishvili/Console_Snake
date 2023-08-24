#include "Game.h"
#include <chrono>
#include <thread>
Game::Game(int h, int w, int startX, int startY):board(h, w),snake(startX, startY),food() {
	isRunning = false;
}

void Game::startGame() {
	isRunning = true;
    board.placeSnake(snake);
    board.update();
    int counter = 0;
	while(isRunning) {
		if(snake.checkCollision()) isRunning = false;
        if (counter == 0 || counter % 10 == 0) {
            chooseRandomPosForGameObject(food);
            board.placeGameObject(food);
        }
        handleInput();
        snake.move();
        board.placeSnake(snake);
		board.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        counter++;
	}
    std::cout << "You LOST!!!!";
}

void Game::handleInput() {
        char userInput = _getch(); // Get the extended key code
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

void Game::chooseRandomPosForGameObject(GameObject& obj) {
    int x = rand() % (board.getWidtht()) + 1;
    int y = rand() % (board.getHeight()) + 1;
    obj.setPosition(x, y);
}


