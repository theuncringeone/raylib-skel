#include <raylib.h>
#include <raymath.h>
#include "stdio.h"
#include "john.h"

int main(int argc, char* argv[]) {

    /*setup window*/

    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "John");
    SetTargetFPS(60);

    /*setup sprite*/

    John john(0, 0, 45, 5);
    John john2(screenWidth / 2, screenHeight / 2, 36, 2.5);
    John john3(535, 321, 60, 10);

    John john4(535, 321, 45, 5);
    John john5(screenWidth / 2 + 413, screenHeight / + 413, 36, 2.5);
    John john6(0, 0, 60, 10);

    while(!WindowShouldClose()) {

        /* update logics */
        john.Update();
        john2.Update();
        john3.Update();

        john4.Update();
        john5.Update();
        john6.Update();

        /*start drawing*/

        BeginDrawing();

            /*code goes here*/
    
            ClearBackground((Color(255, 255, 255, 255)));
            john.Draw();
            john2.Draw();
            john3.Draw();
            john4.Draw();
            john5.Draw();
            john6.Draw();

        /*end drawing*/

        EndDrawing();
    }

    /*unload and close*/

    john.Destroy();
    john2.Destroy();
    john3.Destroy();

    john4.Destroy();
    john5.Destroy();
    john6.Destroy();

    CloseWindow();
    return 0;
}