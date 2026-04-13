#include "tictactoe.hpp"
#include <iostream>

TicTacToe::TicTacToe() {
    board = {'1','2','3','4','5','6','7','8','9'};
    currentPlayer = 'X';
}

void TicTacToe::printBoard() const {
    std::cout << "\n";
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    std::cout << "-----+-----+-----\n";
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    std::cout << "-----+-----+-----\n";
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n\n";
}

bool TicTacToe::makeMove(int position) {
    if (position < 1 || position > 9) return false;

    if (board[position - 1] == 'X' || board[position - 1] == 'O')
        return false;

    board[position - 1] = currentPlayer;
    return true;
}

bool TicTacToe::checkWin() const {
    const int wins[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for (auto &w : wins) {
        if (board[w[0]] == currentPlayer &&
            board[w[1]] == currentPlayer &&
            board[w[2]] == currentPlayer)
            return true;
    }
    return false;
}

bool TicTacToe::checkDraw() const {
    for (char c : board) {
        if (c != 'X' && c != 'O')
            return false;
    }
    return true;
}

void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

char TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

void TicTacToe::resetGame() {
    board = {'1','2','3','4','5','6','7','8','9'};
    currentPlayer = 'X';
}
