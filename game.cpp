#include "raylib.h"
#include "game.h"

Game::Game() : counterBtn(balls, question), question(balls, counterBtn) {
    InitWindow(1024, 768, "Berapa KurangNya!");
    SetTargetFPS(60);
    srand(time(0));
}

Game::~Game() {
    CloseWindow();
}

void Game::Run() {
    while (!WindowShouldClose()) {
        Update();
        Draw();
    }
}

void Game::Update() {
    balls.Update();
    counterBtn.Update();
    question.Update();
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(WHITE);
        balls.Draw();
        counterBtn.Draw();
        question.Draw();
    EndDrawing();
}
