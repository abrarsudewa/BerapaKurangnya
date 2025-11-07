#include "raylib.h"
#include "balls.h"
#include <iostream>

Balls::Balls() {
    radius = 20.0f;
    RandomValue = 5;
}

void Balls::Update() {
    Spawn();
}

void Balls::Draw() {
    for (int i = 0; i < ballList.size(); i++) {
        auto bl = ballList[i];
        DrawCircleV({bl.x, bl.y}, radius, BLUE);
    }
}

void Balls::Spawn() {
    int ballCount = RandomValue;
    // std::cout << ballCount << " ballCount ahhh" << std::endl;
    // std::cout << RandomValue << " Random Value 911 ahhh" << std::endl;
    float MiddleScreenWidth = GetScreenWidth()/2;
    for (int i = 0; i < ballCount; i++) {
        float ballSpaces = 100;
        float xFirst = MiddleScreenWidth+(0*ballSpaces);
        float xLast = MiddleScreenWidth+(ballCount*ballSpaces);
        float center = (xLast - xFirst)/2;
        // std::cout << "xFirst :" << xFirst << std::endl;
        // std::cout << "xLast :" << xLast << std::endl;
        // std::cout << "center :" << center << std::endl;

        ballList.push_back({(float)MiddleScreenWidth+(i*ballSpaces)-center+ballSpaces/2, 200});
    }
}

void Balls::ChangeValue() {
    // std::cout << "ChangeValue() CALLED! Sebelum: " << RandomValue << std::endl;
    // if (IsKeyPressed(KEY_SPACE)) {
        ballList.clear();
        RandomValue = 1 + rand() % 5;
        // RandomValue = 10;
    // }
    // std::cout << "Damn son did you just click the enter button?" << std::endl;
}

