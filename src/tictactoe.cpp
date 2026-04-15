#include "tictactoe.hpp"
#include <iostream>

TicTacToe::TicTacToe() {
    board = {"1","2","3","4","5","6","7","8","9"};

    player1Symbol = "X";
    player2Symbol = "O";
    currentPlayer = player1Symbol;

    player1Wins = 0;
    player2Wins = 0;
    draws = 0;
}

void TicTacToe::setPlayerSymbols(const std::string& p1, const std::string& p2) {
    player1Symbol = p1;
    player2Symbol = p2;
    currentPlayer = player1Symbol;
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

    if (board[position - 1] == player1Symbol || board[position - 1] == player2Symbol)
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
    for (const auto& c : board) {
        if (c != player1Symbol && c != player2Symbol)
            return false;
    }
    return true;
}

void TicTacToe::switchPlayer() {
    currentPlayer =
        (currentPlayer == player1Symbol) ? player2Symbol : player1Symbol;
}

std::string TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

void TicTacToe::resetGame() {
    board = {"1","2","3","4","5","6","7","8","9"};
    currentPlayer = player1Symbol;
}

// =====================
// 🏆 SCOREBOARD FIX
// =====================

void TicTacToe::addWin() {
    if (currentPlayer == player1Symbol)
        player1Wins++;
    else
        player2Wins++;
}

void TicTacToe::addDraw() {
    draws++;
}

int TicTacToe::getPlayer1Wins() const {
    return player1Wins;
}

int TicTacToe::getPlayer2Wins() const {
    return player2Wins;
}

int TicTacToe::getDraws() const {
    return draws;
}