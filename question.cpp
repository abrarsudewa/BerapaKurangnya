#include "question.h"
#include "counter_button.h"
#include <iostream>

Question::Question(Balls& ballsRef, CounterButton& counterBtnRef) : balls(ballsRef), counterBtn(counterBtnRef) {
    Operator = '+';
    InfoText = "Berapa Kurangnya!";
    ColorInfoText = BLACK;
    SecondNumber = 5;
    RevealSecondNumber = false;
    timerActive = false;
    localTime = 0.0f;
    correctPoint = 0;
    incorrectPoint = 0;
    ColorCorrectText = GREEN;
    ColorIncorrectText = RED;
    enableAnswer = true;  
}

void Question::Update() {
    MakeQuestion();
    UpdateTimer();
    ChangeQuestion();
}

void Question::Draw() {
    DrawText(std::to_string(correctPoint).c_str(), 35, GetScreenHeight()/2-350, 50, ColorCorrectText); // Draw correctPoint
    DrawText(std::to_string(incorrectPoint).c_str(), GetScreenWidth()-45, GetScreenHeight()/2-350, 50, ColorIncorrectText); // Draw incorrectPoint
    DrawText(InfoText.c_str(), GetScreenWidth()/2-150, GetScreenHeight()/2-300, 50, ColorInfoText); // Draw InfoText
    DrawText(std::to_string(answer).c_str(), GetScreenWidth()/2+250, GetScreenHeight()/2-100, 100, BLACK); // Answer Text
    DrawText(Operator.c_str(), GetScreenWidth()/2-25, GetScreenHeight()/2-100, 100, BLACK); // Operator (+, -) Text
    DrawText("=", GetScreenWidth()/2+120, GetScreenHeight()/2-100, 100, BLACK); // "=" Text
    // Second Number Text
    if (RevealSecondNumber == true) {
        DrawText(std::to_string(SecondNumber).c_str(), GetScreenWidth()/2-25, GetScreenHeight()/2+50, 100, BLACK);
    } else {
        DrawText("?", GetScreenWidth()/2-25, GetScreenHeight()/2+50, 100, BLACK);
    }

}

void Question::MakeQuestion() {
    answer = balls.RandomValue + SecondNumber;
}

void Question::Answer() {
    if (enableAnswer) {
        if (balls.RandomValue + counterBtn.value == answer) {
            std::cout << "True!" <<  std::endl;
            DrawInfoTxt("Correct", GREEN);
            enableAnswer = false;
            RevealSecondNumber = true;
            correctPoint += 1;
            ColorCorrectText = GREEN;
            ChangeQuestion();
        } else {
            DrawInfoTxt("Incorrect!", RED);
            incorrectPoint += 1;
            ColorIncorrectText = RED;
            std::cout << "False!" <<  std::endl;
        }
    }
}

void Question::UpdateTimer() {
    float deltaTime = GetFrameTime();   
    if (timerActive) {
        localTime += deltaTime;
    }
}


void Question::ChangeQuestion() {
    if (RevealSecondNumber == true) {
        timerActive = true;
    }

    if (localTime >= 1.0f) {

        enableAnswer = true;
        DrawInfoTxt("Berapa Kurangnya!", BLACK);
        SecondNumber = 1 + rand() % 5;
        balls.ChangeValue();
        RevealSecondNumber = false;
        timerActive = false;
        localTime = 0.0f;
    }
}

void Question::DrawInfoTxt(std::string infoTxt, Color ColorInfoTxt) {
    InfoText = infoTxt;
    ColorInfoText = ColorInfoTxt;
}


