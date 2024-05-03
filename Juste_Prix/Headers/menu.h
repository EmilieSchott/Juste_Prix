#pragma once

enum class MenuChoices {
    PLAY = 'j',
    DISPLAY_HALL_OF_FAME = 'a',
    QUIT = 'q',
    INCORRECT
};

MenuChoices chooseGame();
