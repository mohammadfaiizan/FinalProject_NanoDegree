#include <SDL2/SDL.h>
#include "UI.h"
#include "Controller.h"
#include <ctime>

Controller::Controller()
{
    srand(time(NULL));
    restartGame();
}

void Controller::update(SDL_Event *event)
{
    if(state == STATE_STOPPED)
        restartGame();
    else
    {
        bool successfulPlay = false;
        if(!humanTurn)
        {
            AiBot.play(board);
            successfulPlay = true;
        }
        else
        {
            if(event->type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                int row = y/(Ui::SCR_H/3);
                int col = x/(Ui::SCR_W/3);

                if(board.isFieldEmpty(row,col))
                {
                    board.place(row,col);
                    successfulPlay = true;
                }
            }
        }

        // change turns
        if(successfulPlay)
        {
            humanTurn = !humanTurn;
            SDL_Delay(100); // delay between turns
        }
    }
}

void Controller::render()
{
    SDL_SetRenderDrawColor(Ui::getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(Ui::getRenderer());
    board.render();
    SDL_RenderPresent(Ui::getRenderer());
}

void Controller::checkWin()
{
    if(board.hasWinner() || board.isDraw())
        state = STATE_STOPPED;
}

void Controller::restartGame()
{
    
    SDL_Delay(1000);
    AiBot.restart();
    board.restart();
    humanTurn = true;
    state = STATE_RUNNING;
}
