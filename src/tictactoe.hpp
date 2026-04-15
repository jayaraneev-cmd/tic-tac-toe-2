#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <vector>
#include <string>

class TicTacToe {
private:
    std::vector<std::string> board;

    std::string currentPlayer;
    std::string player1Symbol;
    std::string player2Symbol;

    int player1Wins;
    int player2Wins;
    int draws;

public:
    TicTacToe();

    void printBoard() const;
    bool makeMove(int position);
    bool checkWin() const;
    bool checkDraw() const;
    void switchPlayer();
    std::string getCurrentPlayer() const;
    void resetGame();

    void setPlayerSymbols(const std::string& p1, const std::string& p2);

    void addWin();
    void addDraw();

    int getPlayer1Wins() const;
    int getPlayer2Wins() const;
    int getDraws() const;
};

#endif