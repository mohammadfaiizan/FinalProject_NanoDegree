#include "UI.h"

SDL_Window* Ui::gWindow = NULL;
SDL_Renderer* Ui::gRenderer = NULL;

Ui::~Ui()
{
  if(gRenderer != NULL)
    {
        SDL_DestroyRenderer(gRenderer);
        gRenderer = NULL;
    }

    if(gWindow != NULL)
    {
        SDL_DestroyWindow(gWindow);
        gWindow = NULL;
    }
}


void Ui::init()
{

    gWindow = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Ui::start(){
	bool quit = false;
  	while(!quit)
    {  
    while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                quit = true;
       	}
    ctrl.update(&event);
    ctrl.render();
    ctrl.checkWin();
	}
}  

SDL_Window* Ui::getWindow()
{
    return gWindow;
}

SDL_Renderer* Ui::getRenderer()
{
    return gRenderer;
}