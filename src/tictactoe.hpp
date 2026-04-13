#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <vector>

class TicTacToe {
private:
    std::vector<char> board;
    char currentPlayer;

public:
    TicTacToe();

    void printBoard() const;
    bool makeMove(int position);
    bool checkWin() const;
    bool checkDraw() const;
    void switchPlayer();
    char getCurrentPlayer() const;
    void resetGame();
};

#endif