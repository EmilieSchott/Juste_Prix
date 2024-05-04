#include <iostream>
#include <array>
#include <random>
#include "Headers/constants.h"
#include "Headers/menu.h"
#include "Headers/game.h"

using namespace std;

int main() {
    cout << "Bienvenue au juste prix !" << endl;
    cout << "C'est parti pour un jeu qu'il est sympa (bon ok...c'est discutable) !" << endl;
    MenuChoices choice;
    auto scores = HallOfFame{0}; // custom type : cf game.h
    int hallOfFameIndex{0};

    auto generator = mt19937{ std::random_device{}()};
    auto distribution = std::uniform_int_distribution<int>{ MIN_PRICE, MAX_PRICE };
    auto continuer = true;

    while (continuer == true) {
        choice = chooseGame();
        switch (choice) {
        case MenuChoices::PLAY:
            scores[hallOfFameIndex] = playJustePrix(distribution(generator));
            hallOfFameIndex = (hallOfFameIndex + 1) % SCORES_TO_DISPLAY_NUMBER;

            break;

        case MenuChoices::DISPLAY_HALL_OF_FAME:
            cout << "Les derniers scores : " << endl;
            displayHallOfFame(scores);

            break;

        case MenuChoices::QUIT:
            cout << "Au revoir !";
            continuer = false;

            break;

        case MenuChoices::INCORRECT:
        default:
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;

}