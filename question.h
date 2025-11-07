#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include "raylib.h"
#include "balls.h"
class CounterButton;


class Question {
public:
    Question(Balls& ballsRef, CounterButton& counterBtnRef);
    void Update();
    void Draw();
    void Answer();

    std::string Operator;
    std::string InfoText;
    Color ColorInfoText;
    Color ColorCorrectText;
    Color ColorIncorrectText;
    int answer;
    int correctPoint;
    int incorrectPoint;
    bool enableAnswer;  
    
private:
    void MakeQuestion();
    void ChangeQuestion();
    void UpdateTimer();
    void DrawInfoTxt(std::string infoTxt, Color ColorInfoTxt);

    int SecondNumber;
    float localTime;
    bool RevealSecondNumber;
    bool timerActive;

    Balls& balls;
    CounterButton& counterBtn;
};

#endif