#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "balls.h"
#include "counter_button.h"
#include "question.h"

class Game {
public:
    Game();
    ~Game();
    void Run();

private:
    void Update();
    void Draw();
    
    Balls balls;
    CounterButton counterBtn;
    Question question;
};

#endif
