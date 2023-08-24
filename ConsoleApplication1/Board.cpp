#include "Board.h"
#include <iostream>

Board::Board(int h, int w) {
    height = h;
    width = w;
    board.resize(height, std::vector<char>(width));
    init(board);
}

void Board::init(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < height; i++) {
        if (i == 0 || i == height - 1) {
            for (int k = 0; k < width; k++) board[i].push_back('@');
        }
        else {
            board[i].push_back('@');
            for (int k = 0; k < width - 2; k++)  board[i].push_back(' ');
            board[i].push_back('@');
        }
    }
}

void Board::update() {
    for (int i = 0; i < height; i++) {
        for (int k = 0; k < width; k++) {
            std::cout << board[i][k];
        }
        if (i != board.size() - 1) {
            std::cout << '\n';
        }
    }
}



void Board::placeSnake(Snake& snake) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                board[y][x] = '@';
            }
            else {
                board[y][x] = ' ';
            }
        }
    }
    std::deque<std::pair<int, int>>& body = snake.getBody();
    for (size_t i = 0; i < body.size(); i++) {
        int x = body[i].first;
        int y = body[i].second;
        board[y][x] = ' ';
        if (x <= 1) {
            x = width - 2;
            board[y][x] = '@';
        }
        else if (x >= width - 1) {
            x = 1;
            board[y][x] = '@';
        }
        else if (y <= 1) {
            y = height - 2;
            board[y][x] = '@';
        }
        else if (y >= height - 1) {
            y = 1;
            board[y][x] = '@';
        }
        body[i].first = x;
        body[i].second = y;
        if (i != 0) {
            board[y][x] = '#';
        }
        else {
            board[y][x] = '*';
        }
    }
}



void Board::placeGameObject(GameObject& obj) {
    std::pair<int,int> curPos = obj.getPos();
    board[curPos.second][curPos.first] = 'O';
}

void Board::removeGameObject(GameObject& obj) {
    int x = obj.getPos().first;
    int y = obj.getPos().second;
    board[y][x] = ' ';
}

int Board::getHeight() {
    return height;
}

int Board::getWidtht() {
    return width;
}
