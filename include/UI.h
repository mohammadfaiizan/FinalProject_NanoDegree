#ifndef UI_H
#define UI_H

#include<SDL2/SDL.h>
#include<Controller.h>

class Ui
{
public:
	static const int SCR_W = 600;
    static const int SCR_H = 600;
    
    ~Ui();
    
    void init();
    void start();
    
    static SDL_Window *getWindow();
    static SDL_Renderer *getRenderer();
    
private:	
	Controller ctrl;
    static SDL_Window *gWindow;
    static SDL_Renderer *gRenderer;
    SDL_Event event;
};

#endif