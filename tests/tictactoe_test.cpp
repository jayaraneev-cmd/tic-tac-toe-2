#include "tictactoe.hpp"
#include <cassert>
#include <iostream>

int main() {

    // TEST GAME CREATION
    TicTacToe game;

    // TEST VALID MOVE
    assert(game.makeMove(1) == true);

    // TEST SAME SPOT INVALID
    assert(game.makeMove(1) == false);

    // TEST INVALID POSITION
    assert(game.makeMove(10) == false);

    // TEST PLAYER SWITCH
    std::string firstPlayer = game.getCurrentPlayer();

    game.switchPlayer();

    std::string secondPlayer = game.getCurrentPlayer();

    assert(firstPlayer != secondPlayer);

    // TEST WIN
    TicTacToe winGame;

    winGame.makeMove(1);
    winGame.makeMove(2);
    winGame.makeMove(3);

    assert(winGame.checkWin() == true);

    // TEST DRAW
    TicTacToe drawGame;

    drawGame.makeMove(1);
    drawGame.switchPlayer();

    drawGame.makeMove(2);
    drawGame.switchPlayer();

    drawGame.makeMove(3);
    drawGame.switchPlayer();

    drawGame.makeMove(5);
    drawGame.switchPlayer();

    drawGame.makeMove(4);
    drawGame.switchPlayer();

    drawGame.makeMove(6);
    drawGame.switchPlayer();

    drawGame.makeMove(8);
    drawGame.switchPlayer();

    drawGame.makeMove(7);
    drawGame.switchPlayer();

    drawGame.makeMove(9);

    assert(drawGame.checkDraw() == true);

    std::cout << "All tests passed!\n";

    return 0;
}