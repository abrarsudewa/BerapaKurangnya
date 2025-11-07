#ifndef COUNTER_BUTTON_H
#define COUNTER_BUTTON_H

#include "raylib.h"
#include "balls.h"
class Question;
#include <cstdlib>
#include <ctime> 

class CounterButton {
public:
    int value;
    CounterButton(Balls& ballsRef, Question& questionRef);
    void Update();
    void Draw();
private:
    Rectangle IncreaseButtonPos;
    Rectangle DecreaseButtonPos;
    Rectangle EnterButtonPos;
    Vector2 ValueTextPos;
    void Increase();
    void Decrease();
    void Enter();

    Balls& balls;
    Question& question;
};

#endif