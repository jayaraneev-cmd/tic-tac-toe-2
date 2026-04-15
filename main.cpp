#include <iostream>
#include <windows.h>
#include "src/tictactoe.hpp"

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    TicTacToe game;

    std::string player1, player2;
    std::string playAgain = "yes";

    std::cout << "Welcome to Tic-Tac-Toe!\n\n";

    std::cout << "Enter Player 1 name: ";
    std::cin >> player1;

    std::cout << "Enter Player 2 name: ";
    std::cin >> player2;

    std::vector<std::string> symbols = {"X", "O", "😊", "😠"};

    int choice1, choice2;

    std::cout << "\nChoose Player 1 symbol:\n1. X\n2. O\n3. 😊\n4. 😠\n";
    std::cin >> choice1;

    std::cout << "\nChoose Player 2 symbol:\n1. X\n2. O\n3. 😊\n4. 😠\n";
    std::cin >> choice2;

    while (symbols[choice1 - 1] == symbols[choice2 - 1]) {
        std::cout << "Symbols must be different!\n";
        std::cin >> choice2;
    }

    game.setPlayerSymbols(symbols[choice1 - 1], symbols[choice2 - 1]);

    while (playAgain == "yes") {

        game.resetGame();
        bool gameOver = false;

        while (!gameOver) {

            game.printBoard();

            std::string currentName =
                (game.getCurrentPlayer() == symbols[choice1 - 1])
                ? player1
                : player2;

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

                game.addWin();
                gameOver = true;
            }
            else if (game.checkDraw()) {
                game.printBoard();
                std::cout << "It's a draw!\n";

                game.addDraw();
                gameOver = true;
            }
            else {
                game.switchPlayer();
            }
        }

        std::cout << "\n===== SCOREBOARD =====\n";
        std::cout << player1 << " wins: " << game.getPlayer1Wins() << "\n";
        std::cout << player2 << " wins: " << game.getPlayer2Wins() << "\n";
        std::cout << "Draws: " << game.getDraws() << "\n";
        std::cout << "======================\n";

        std::cout << "Play again? (yes/no): ";
        std::cin >> playAgain;
    }

    std::cout << "Goodbye!\n";
    return 0;
}