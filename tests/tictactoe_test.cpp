#include "../src/tictactoe.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Player starts as X") {
    TicTacToe game;
    REQUIRE(game.getCurrentPlayer() == 'X');
}

TEST_CASE("Valid move works") {
    TicTacToe game;
    REQUIRE(game.makeMove(1) == true);
}

TEST_CASE("Invalid move rejected (same spot)") {
    TicTacToe game;
    game.makeMove(1);
    REQUIRE(game.makeMove(1) == false);
}

TEST_CASE("Switch player works") {
    TicTacToe game;
    game.switchPlayer();
    REQUIRE(game.getCurrentPlayer() == 'O');
}

TEST_CASE("Row win detected") {
    TicTacToe game;

    game.makeMove(1); // X
    game.switchPlayer();
    game.makeMove(4); // O
    game.switchPlayer();
    game.makeMove(2); // X
    game.switchPlayer();
    game.makeMove(5); // O
    game.switchPlayer();
    game.makeMove(3); // X wins

    REQUIRE(game.checkWin() == true);
}

TEST_CASE("Draw detected") {
    TicTacToe game;

    game.makeMove(1); game.switchPlayer();
    game.makeMove(2); game.switchPlayer();
    game.makeMove(3); game.switchPlayer();
    game.makeMove(5); game.switchPlayer();
    game.makeMove(4); game.switchPlayer();
    game.makeMove(6); game.switchPlayer();
    game.makeMove(8); game.switchPlayer();
    game.makeMove(7); game.switchPlayer();
    game.makeMove(9);

    REQUIRE(game.checkDraw() == true);
}