#include <iostream>
#include <array>
#include <chrono>
#include "../Headers/game.hpp"
#include "../Headers/constants.hpp"

using namespace std;

void makeProposition(int& proposition) {
    do {
        cout << "Faites une proposition de prix (entre " << MIN_PRICE << " et " << MAX_PRICE << " euros) : ";
        cin >> proposition;
    } while (proposition > MAX_PRICE || proposition < MIN_PRICE);
}

int playJustePrix(int priceToGuess) {
    auto proposition{ 0 };
    auto attemptsNumber{ 0 };

    using Duration = std::chrono::duration<double>;
    auto duration = Duration{ 0 };

    auto beginningGameAt = std::chrono::system_clock::now();

    do {
        makeProposition(proposition);
        attemptsNumber++;

        if (priceToGuess == proposition) {
            cout << "Bravo ! Vous avez gagne en " << attemptsNumber << " tentatives !" << endl;
            auto endingGameAt = std::chrono::system_clock::now();
            duration = std::chrono::duration_cast<Duration>(endingGameAt - beginningGameAt);
            cout << "et en " << duration.count() << " secondes." << endl;
        }
        else if (priceToGuess > proposition) {
            cout << "C'est plus !" << endl;
        }
        else {
            cout << "C'est moins !" << endl;
        }

        if (attemptsNumber >= MAX_ATTEMPTS_NUMBER && priceToGuess != proposition) cout << "Vous avez perdu ! Le juste prix etait de " << priceToGuess << " euros !" << endl;

    } while (priceToGuess != proposition && attemptsNumber < MAX_ATTEMPTS_NUMBER);


    return attemptsNumber;
}

void displayHallOfFame(HallOfFame& scores) {
    for (auto score : scores) {
        if (score == 0) {
            cout << "-" << endl;
        }
        else {
            cout << score << " tentative(s)" << endl;
        }
    }
}