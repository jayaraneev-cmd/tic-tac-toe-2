#include "tictactoe.hpp"
#include <iostream>

TicTacToe::TicTacToe(int size) {

    boardSize = size;

    for (int i = 1; i <= boardSize * boardSize; i++) {
        board.push_back(std::to_string(i));
    }

    player1Symbol = "X";
    player2Symbol = "O";
    currentPlayer = player1Symbol;
}

void TicTacToe::setPlayerSymbols(const std::string& p1,
                                  const std::string& p2) {

    player1Symbol = p1;
    player2Symbol = p2;
    currentPlayer = player1Symbol;
}

void TicTacToe::printBoard() const {

    std::cout << "\n";

    for (int row = 0; row < boardSize; row++) {

        for (int col = 0; col < boardSize; col++) {

            int index = row * boardSize + col;

            std::cout << " ";

            if (board[index].length() == 1)
                std::cout << " ";

            std::cout << board[index] << " ";

            if (col < boardSize - 1)
                std::cout << "|";
        }

        std::cout << "\n";

        if (row < boardSize - 1) {

            for (int i = 0; i < boardSize; i++) {

                std::cout << "-----";

                if (i < boardSize - 1)
                    std::cout << "+";
            }

            std::cout << "\n";
        }
    }

    std::cout << "\n";
}

bool TicTacToe::makeMove(int position) {

    if (position < 1 || position > boardSize * boardSize)
        return false;

    if (board[position - 1] == player1Symbol ||
        board[position - 1] == player2Symbol)
        return false;

    board[position - 1] = currentPlayer;
    return true;
}

bool TicTacToe::checkWin() const {

    // ROWS
    for (int r = 0; r < boardSize; r++) {

        bool win = true;

        for (int c = 0; c < boardSize; c++) {

            if (board[r * boardSize + c] != currentPlayer) {
                win = false;
                break;
            }
        }

        if (win) return true;
    }

    // COLUMNS
    for (int c = 0; c < boardSize; c++) {

        bool win = true;

        for (int r = 0; r < boardSize; r++) {

            if (board[r * boardSize + c] != currentPlayer) {
                win = false;
                break;
            }
        }

        if (win) return true;
    }

    // DIAGONAL 1
    bool win = true;

    for (int i = 0; i < boardSize; i++) {

        if (board[i * boardSize + i] != currentPlayer) {
            win = false;
            break;
        }
    }

    if (win) return true;

    // DIAGONAL 2
    win = true;

    for (int i = 0; i < boardSize; i++) {

        if (board[i * boardSize + (boardSize - 1 - i)] != currentPlayer) {
            win = false;
            break;
        }
    }

    return win;
}

bool TicTacToe::checkDraw() const {

    for (auto &cell : board) {
        if (cell != player1Symbol &&
            cell != player2Symbol)
            return false;
    }

    return true;
}

void TicTacToe::switchPlayer() {

    currentPlayer =
        (currentPlayer == player1Symbol)
        ? player2Symbol
        : player1Symbol;
}

std::string TicTacToe::getCurrentPlayer() const {
    return currentPlayer;
}

void TicTacToe::resetGame() {

    board.clear();

    for (int i = 1; i <= boardSize * boardSize; i++) {
        board.push_back(std::to_string(i));
    }

    currentPlayer = player1Symbol;
}