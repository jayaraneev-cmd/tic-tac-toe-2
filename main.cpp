#include <iostream>
#include <cstdlib>
#include <ctime>
#include "src/tictactoe.hpp"

int main() {

    srand(time(0));

    int size;
    int gameMode;
    int choice1, choice2;

    int player1Wins = 0;
    int player2Wins = 0;
    int draws = 0;

    std::string player1, player2;
    std::string playAgain = "yes";

    std::vector<std::string> symbols = {"X", "O", "$", "%"};

    // ======================
    // INITIAL SETUP
    // ======================
    std::cout << "Choose board size (3, 4, or 5): ";
    std::cin >> size;

    while (size < 3 || size > 5) {
        std::cout << "Invalid size. Choose 3, 4, or 5: ";
        std::cin >> size;
    }

    std::cout << "\nChoose Game Mode:\n";
    std::cout << "1. Human vs Human\n";
    std::cout << "2. Human vs Computer\n";
    std::cin >> gameMode;

    while (gameMode < 1 || gameMode > 2) {
        std::cout << "Invalid choice. Choose 1 or 2: ";
        std::cin >> gameMode;
    }

    std::cout << "\nEnter Player 1 name: ";
    std::cin >> player1;

    if (gameMode == 1) {
        std::cout << "Enter Player 2 name: ";
        std::cin >> player2;
    } else {
        player2 = "Computer";
    }

    // ======================
    // SYMBOL SELECTION
    // ======================
    std::cout << "\nChoose Player 1 symbol:\n1. X\n2. O\n3. $\n4. %\n";
    std::cin >> choice1;

    while (choice1 < 1 || choice1 > 4) {
        std::cout << "Invalid choice. Choose 1-4: ";
        std::cin >> choice1;
    }

    std::string p1Symbol = symbols[choice1 - 1];
    std::string p2Symbol;

    if (gameMode == 1) {

        std::cout << "\nChoose Player 2 symbol:\n1. X\n2. O\n3. $\n4. %\n";
        std::cin >> choice2;

        while (choice2 < 1 || choice2 > 4 ||
               symbols[choice2 - 1] == p1Symbol) {

            std::cout << "Invalid or duplicate symbol. Try again: ";
            std::cin >> choice2;
        }

        p2Symbol = symbols[choice2 - 1];
    }
    else {

        do {
            p2Symbol = symbols[rand() % 4];
        } while (p2Symbol == p1Symbol);
    }

    TicTacToe game(size);
    game.setPlayerSymbols(p1Symbol, p2Symbol);

    // ======================
    // MAIN LOOP
    // ======================
    while (playAgain == "yes") {

        game.resetGame();
        bool gameOver = false;

        while (!gameOver) {

            game.printBoard();

            std::string currentName =
                (game.getCurrentPlayer() == p1Symbol)
                ? player1
                : player2;

            int move;

            // COMPUTER MOVE
            if (gameMode == 2 && currentName == "Computer") {

                do {
                    move = rand() % (size * size) + 1;
                } while (!game.makeMove(move));

                std::cout << "Computer chose: " << move << "\n";
            }

            // HUMAN MOVE
            else {

                std::cout << currentName
                          << " ("
                          << game.getCurrentPlayer()
                          << "), enter move: ";

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
            }

            // WIN / DRAW
            if (game.checkWin()) {

                game.printBoard();
                std::cout << currentName << " wins!\n";

                if (currentName == player1)
                    player1Wins++;
                else
                    player2Wins++;

                gameOver = true;
            }
            else if (game.checkDraw()) {

                game.printBoard();
                std::cout << "It's a draw!\n";

                draws++;
                gameOver = true;
            }
            else {
                game.switchPlayer();
            }
        }

        // ======================
        // SCOREBOARD
        // ======================
        std::cout << "\n===== SCOREBOARD =====\n";
        std::cout << player1 << " wins: " << player1Wins << "\n";
        std::cout << player2 << " wins: " << player2Wins << "\n";
        std::cout << "Draws: " << draws << "\n";
        std::cout << "======================\n";

        // ======================
        // MENU
        // ======================
        std::cout << "\n1. Play Again\n";
        std::cout << "2. Change Board + Mode\n";
        std::cout << "3. Quit\n";

        int option;
        std::cin >> option;

        while (option < 1 || option > 3) {
            std::cout << "Invalid option. Choose 1-3: ";
            std::cin >> option;
        }

        if (option == 1) {

            playAgain = "yes";
        }

        else if (option == 2) {

            std::cout << "\nChoose board size (3, 4, 5): ";
            std::cin >> size;

            while (size < 3 || size > 5) {
                std::cout << "Invalid size: ";
                std::cin >> size;
            }

            std::cout << "\nChoose Game Mode:\n";
            std::cout << "1. Human vs Human\n";
            std::cout << "2. Human vs Computer\n";
            std::cin >> gameMode;

            std::cout << "\nEnter Player 1 name: ";
            std::cin >> player1;

            if (gameMode == 1) {
                std::cout << "Enter Player 2 name: ";
                std::cin >> player2;
            } else {
                player2 = "Computer";
            }

            std::cout << "\nChoose Player 1 symbol (1-4): ";
            std::cin >> choice1;

            p1Symbol = symbols[choice1 - 1];

            if (gameMode == 1) {

                std::cout << "\nChoose Player 2 symbol (1-4): ";
                std::cin >> choice2;

                while (symbols[choice2 - 1] == p1Symbol) {
                    std::cout << "Duplicate symbol. Try again: ";
                    std::cin >> choice2;
                }

                p2Symbol = symbols[choice2 - 1];
            }
            else {

                do {
                    p2Symbol = symbols[rand() % 4];
                } while (p2Symbol == p1Symbol);
            }

            game = TicTacToe(size);
            game.setPlayerSymbols(p1Symbol, p2Symbol);

            playAgain = "yes";
        }

        else {
            playAgain = "no";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}