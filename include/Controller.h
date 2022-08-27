#ifndef Controller_H
#define Controller_H

#include <SDL2/SDL.h>
#include "board.h"
#include "AI.h"

class Controller
{
public:
	enum GAME_STATE {STATE_RUNNING, STATE_STOPPED};
    Controller();
    void update(SDL_Event *event);
    void render();
    void checkWin();

private:
	GAME_STATE state;
    Board board;
    AIBot AiBot;
    bool humanTurn = true;
    void restartGame();
};

#endif