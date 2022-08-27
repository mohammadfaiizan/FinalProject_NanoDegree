#ifndef AI_H
#define AI_H

#include "board.h"

class AIBot
{
public:
    enum BOT_LEVEL
    {
        LEVEL_EASY,
        LEVEL_MEDIUM, 
        LEVEL_HARD, 
        LEVEL_COUNT
    };

    AIBot();

    void play(Board &board);
    void restart();

private:
    BOT_LEVEL level = LEVEL_HARD;

    void easy(Board &board);
    bool medium(Board &board);
    bool hard(Board &board);
};

#endif