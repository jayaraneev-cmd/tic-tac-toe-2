#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <vector>
#include <string>

class TicTacToe {
private:
    std::vector<std::string> board;
    int boardSize;

    std::string currentPlayer;
    std::string player1Symbol;
    std::string player2Symbol;

public:
    TicTacToe(int size = 3);

    void printBoard() const;
    bool makeMove(int position);
    bool checkWin() const;
    bool checkDraw() const;
    void switchPlayer();
    std::string getCurrentPlayer() const;
    void resetGame();

    void setPlayerSymbols(const std::string& p1, const std::string& p2);
};

#endif