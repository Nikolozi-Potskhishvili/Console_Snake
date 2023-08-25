#include "Game.h"
#include <chrono>
#include <thread>
Game::Game(int h, int w, int startX, int startY):board(h, w),snake(startX, startY),food() {
	isRunning = false;
}

void Game::startGame() {
	isRunning = true;
    board.placeSnake(snake,food);
    board.update();
    int counter = 0;
    Direction nextDirection = Direction::UP;
	while(isRunning) {
        if (snake.checkCollision()) {
            isRunning = false;
        }
        if (snake.checkFood(food)) {
            snake.eatFood(food);
            board.removeGameObject(food);
            food.setSatus(false);
        }
        if (counter % 101 == 0) {
            chooseRandomPosForGameObject(food);
            food.setSatus(true);
            board.placeGameObject(food);
        }
        handleInput(nextDirection);
        snake.changeDirection(nextDirection);
        snake.move();
        board.placeSnake(snake,food);
		board.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        counter++;
	}
    std::cout << "You LOST!!!!";
}

void Game::handleInput(Direction& nextDirection) {
    if (_kbhit()) {
        char userInput = _getch();
        switch (userInput) {
        case 72: // Up arrow
            nextDirection = Direction::UP;
            break;
        case 80: // Down arrow
            nextDirection = Direction::DOWN;
            break;
        case 75: // Left arrow
            nextDirection = Direction::LEFT;
            break;
        case 77: // Right arrow
            nextDirection = Direction::RIGHT;
            break;
        }
    }
}

void Game::chooseRandomPosForGameObject(GameObject& obj) {
    int x = (rand() % (board.getWidtht() - 2)) + 1;
    int y = (rand() % (board.getHeight() - 2)) + 1;
    //std::cout << x << " " << y<<'\n';
    obj.setPosition(x, y);
    //std::cout << obj.getPos().first<< " " << obj.getPos().second << '\n';
}


