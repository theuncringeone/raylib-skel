#ifndef JOHN_H
#define JOHN_H

#include <raylib.h>
#include <raymath.h>

class John {
    private:
        Image john;
        Texture2D johntexture;
        Vector2 position;
        float direction;
        float speed;

    public:
        John(float startx, float starty, float dir, float speed);

        void Update();
        void Draw();
        void Destroy();
};

#endif