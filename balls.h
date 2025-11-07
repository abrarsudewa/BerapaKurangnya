#ifndef BALLS_H
#define BALLS_H

#include "raylib.h"
#include <vector>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()

class Balls {
public:
    Balls();
    void Update();
    void Draw();
    
    void ChangeValue();
    int RandomValue;
private:
    std::vector<Vector2> ballList;
    float radius;
    
    void Spawn();
};

#endif
