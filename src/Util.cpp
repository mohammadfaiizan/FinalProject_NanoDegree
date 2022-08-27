#include "Util.h"
#include "UI.h"
#include <cmath>


void Util::drawCross(int row, int col)
{
    int fieldW = Ui::SCR_W/3;
    int fieldH = Ui::SCR_H/3;

    
    SDL_RenderDrawLine(Ui::getRenderer(),
        col*fieldW, row*fieldH,
        col*fieldW+fieldW, row*fieldH+fieldH);

    
    SDL_RenderDrawLine(Ui::getRenderer(),
        col*fieldW, row*fieldH+fieldH,
        col*fieldW+fieldW, row*fieldH);
}


void Util::drawCircle(int row, int col)
{
    int fieldW = Ui::SCR_W/3;
    int fieldH = Ui::SCR_H/3;

    // calculate circle center
    int centerX = col*fieldW+(fieldW/2);
    int centerY = row*fieldH+(fieldH/2);

    int r = fieldW/2;

    double step = 2*M_PI/30;
    int endX = centerX + r;
    int endY = centerY;

  
    for(double angle=0; angle<2*M_PI; angle+=step)
    {
        int startX = endX;
        int startY = endY;
        endX = r * cos(angle) + centerX;
        endY = r * sin(angle) + centerY;
        SDL_RenderDrawLine(Ui::getRenderer(), startX, startY, endX, endY);
    }
}
