#pragma once

#include <array>
#include "../Headers/constants.hpp"

// type custom :
using HallOfFame = std::array<int, SCORES_TO_DISPLAY_NUMBER>;

//Prototypes :
void makeProposition(int& proposition);
int playJustePrix(int priceToGuess);
void displayHallOfFame(HallOfFame& scores);