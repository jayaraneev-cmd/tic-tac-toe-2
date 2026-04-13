#include <iostream>
#include "src/tictactoe.hpp"

int main() {
    TicTacToe game;

    std::string player1, player2, playAgain = "yes";

    std::cout << "Welcome to Tic-Tac-Toe!\n\n";

    std::cout << "Enter Player 1 name (X): ";
    std::cin >> player1;

    std::cout << "Enter Player 2 name (O): ";
    std::cin >> player2;

    while (playAgain == "yes") {
        game.resetGame();
        bool gameOver = false;

        while (!gameOver) {
            game.printBoard();

            std::string currentName =
                (game.getCurrentPlayer() == 'X') ? player1 : player2;

            std::cout << currentName << " (" << game.getCurrentPlayer()
                      << "), enter move (1-9): ";

            int move;
            if (!(std::cin >> move)) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid input!\n";
                continue;
            }

            if (!game.makeMove(move)) {
                std::cout << "Invalid move!\n";
                continue;
            }

            if (game.checkWin()) {
                game.printBoard();
                std::cout << currentName << " wins!\n";
                gameOver = true;
            }
            else if (game.checkDraw()) {
                game.printBoard();
                std::cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                game.switchPlayer();
            }
        }

        std::cout << "Play again? (yes/no): ";
        std::cin >> playAgain;
    }

    std::cout << "Goodbye!\n";
    return 0;
}