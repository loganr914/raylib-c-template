#include <raylib.h>

// + CONSTANTS
const int renderWidth = 320;
const int renderHeight = 240;

// + PROGRAM MAIN ENTRY POINT
int main(void)
{
    // Initialization
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    InitWindow(960, 720, "Raylib Template");
    // SetExitKey(KEY_F4);

    // Load render texture
    RenderTexture2D canvas = LoadRenderTexture(renderWidth, renderHeight);

    // Camera
    Camera2D gameCamera = { 0 };
    gameCamera.zoom = 1.0f;

    // Player

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // + UPDATE LOOP

        // Render texture integer scaling
        int windowWidth = GetRenderWidth();
        int windowHeight = GetRenderHeight();

        int renderScale = windowHeight/renderHeight;

        int scaledWidth = renderWidth * renderScale;
        int scaledHeight = renderHeight * renderScale;

        float renderX = (windowWidth/2) - (scaledWidth/2);
        float renderY = (windowHeight/2) - (scaledHeight/2);

        Rectangle sourceRec = { 0.0f, 0.0f, (float)canvas.texture.width, -(float)canvas.texture.height };
        Rectangle destRec = { renderX, renderY, (float)scaledWidth, (float)scaledHeight };


        // Player input
        if (IsKeyDown(KEY_W))
        {

        }


        // Keybindings
        if (IsKeyPressed(KEY_F3))
        {
            ToggleFullscreen();
        }



        // + DRAW LOOP

        // Draw to render texture
        BeginTextureMode(canvas);
        ClearBackground(DARKGRAY);
        BeginMode2D(gameCamera);

            // 

            // Circle
            DrawCircleV((Vector2){renderWidth/2, renderHeight/2}, 20, WHITE);

        EndMode2D();
        EndTextureMode();

        // Drawing to native window resolution
        BeginDrawing();
            ClearBackground(BLACK);

            // Draw render texture
            DrawTexturePro(
                canvas.texture,
                sourceRec,
                destRec,
                (Vector2){},
                0.0f,
                WHITE
            );

            // Draw whatever you want to appear on top of the render texture

            // Stats display
            DrawFPS(0, 0);

            DrawText(TextFormat("Window size: %ix%i", windowWidth, windowHeight), 0, 20, 20, WHITE);

            DrawText(TextFormat("Scaled size: %ix%i", scaledWidth, scaledHeight), 0, 40, 20, WHITE);

            DrawText(TextFormat("Render scale: %ix", renderScale), 0, 60, 20, WHITE);

        EndDrawing();
    }

    UnloadRenderTexture(canvas);
    CloseWindow();

    return 0;
}