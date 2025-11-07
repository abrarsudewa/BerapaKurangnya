#include "counter_button.h"
#include "question.h"
#include <iostream>

CounterButton::CounterButton(Balls& ballsRef, Question& questionRef) : balls(ballsRef), question(questionRef) {
    value = 0;
}

void CounterButton::Update() {
    Increase();
    Decrease();
    Enter();    
}

void CounterButton::Draw() {
    // Drawing all the buttons
    ValueTextPos = {(float)GetScreenWidth()/2, (float)GetScreenHeight()-100};
    DecreaseButtonPos = {ValueTextPos.x - 100, ValueTextPos.y, 50, 50};
    IncreaseButtonPos = {ValueTextPos.x + 100-25, ValueTextPos.y, 50, 50};
    EnterButtonPos = {ValueTextPos.x-100, ValueTextPos.y+65, 225, 25};
    
    DrawRectangleRec(IncreaseButtonPos, LIGHTGRAY);
    DrawRectangleRec(DecreaseButtonPos, LIGHTGRAY);
    DrawRectangleRec(EnterButtonPos, LIGHTGRAY);
    
    DrawText(TextFormat("%d", value), (int)ValueTextPos.x, (int)ValueTextPos.y, 50, BLACK);
    DrawText("+", (int)IncreaseButtonPos.x+15, (int)IncreaseButtonPos.y+2, 50, BLACK); 
    DrawText("-", (int)DecreaseButtonPos.x+15, (int)DecreaseButtonPos.y+2, 50, BLACK);
    DrawText("ENTER", (int)EnterButtonPos.x+75, (int)EnterButtonPos.y+3, 20, BLACK);
}

void CounterButton::Increase() {
    if (CheckCollisionPointRec(GetMousePosition(), IncreaseButtonPos) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        value++;
    }
}

void CounterButton::Decrease() {
    if (CheckCollisionPointRec(GetMousePosition(), DecreaseButtonPos) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        value--;
    }    
}

void CounterButton::Enter() {
    if (CheckCollisionPointRec(GetMousePosition(), EnterButtonPos) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        // std::cout << "Enter ahhh" << std::endl;
        question.Answer();
        // balls.ChangeValue();
    }
}

