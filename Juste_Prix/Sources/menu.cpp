#include "iostream"
#include "../Headers/menu.h"

using namespace std;

MenuChoices chooseGame() {
	cout << "Que souhaitez vous faire ? " << endl;
	cout << static_cast<char>(MenuChoices::PLAY) << " pour jouer" << endl;
	cout << static_cast<char>(MenuChoices::DISPLAY_HALL_OF_FAME) << " pour afficher les scores" << endl;
	cout << static_cast<char>(MenuChoices::QUIT) << " pour quitter" << endl;
	cout << "Votre choix : ";
	char ChoiceSelected;
	cin >> ChoiceSelected;
	if (ChoiceSelected == static_cast<char>(MenuChoices::PLAY) || ChoiceSelected == static_cast<char>(MenuChoices::QUIT) || ChoiceSelected == static_cast<char>(MenuChoices::DISPLAY_HALL_OF_FAME)) {
		return static_cast<MenuChoices>(ChoiceSelected);
	}
	else {
		return MenuChoices::INCORRECT; // No need to cast here because there is no value associated with this constant.
	}
}
