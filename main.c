#include <raylib.h>

const int renderWidth = 640;
const int renderHeight = 480;



int main(void)
{
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    InitWindow(800, 600, "Raylib Template");

    RenderTexture2D canvas = LoadRenderTexture(renderWidth, renderHeight);
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        int windowWidth = GetRenderWidth();
        int windowHeight = GetRenderHeight();




        BeginDrawing();
        ClearBackground(BLACK);
        BeginTextureMode(canvas);

        


        DrawText("HELLO RAYLIB", 0, 0, 20, WHITE);

        DrawCircleV((Vector2) {50, 50}, 20, WHITE);
        EndTextureMode();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
