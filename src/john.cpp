#include "john.h"

John::John(float startx, float starty, float dir, float speed) {
    john = LoadImage("res/john.png");
    johntexture = LoadTextureFromImage(john);
    UnloadImage(john);

    John::position = {startx, starty};
    John::direction = float(dir);
    John::speed = float(speed);
}

void John::Update() {
    if ((position.x > GetScreenWidth() - johntexture.width) || (position.y > GetScreenHeight() - johntexture.height) || (position.x < 0) || (position.y < 0)) {
            direction = direction + 90.0f;
        }
    position = Vector2Add(position, Vector2(cosf(direction * DEG2RAD) * speed, sinf(direction * DEG2RAD) * speed));
}

void John::Draw() {
    DrawTexture(johntexture, position.x, position.y, WHITE);
}

void John::Destroy() {
    UnloadTexture(johntexture);
}