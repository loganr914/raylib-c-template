#include <raylib.h>

// + CONSTANTS + //
const int renderWidth = 640;
const int renderHeight = 480;

// + PROGRAM MAIN ENTRY POINT + //
int main(void)
{
    // Initialization
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    InitWindow(800, 600, "Raylib Template");
    // SetExitKey(KEY_F4);

    // Load render texture
    RenderTexture2D canvas = LoadRenderTexture(renderWidth, renderHeight);

    Camera2D gameCamera = { 0 };
    gameCamera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // + UPDATE LOOP + //

        // Render texture integer scaling
        float windowWidth = GetRenderWidth();
        float windowHeight = GetRenderHeight();

        int scale = windowWidth/renderWidth;

        float scaledWidth = renderWidth * scale;
        float scaledHeight = renderHeight * scale;

        float renderX = (windowWidth - scaledWidth) * 0.5f;
        float renderY = (windowHeight - scaledHeight) * 0.5f;

        Rectangle sourceRec = { 0.0f, 0.0f, (float)canvas.texture.width, -(float)canvas.texture.height };
        Rectangle destRec = { renderX, renderY, scaledWidth, scaledHeight };

        if (IsKeyPressed(KEY_F3))
        {
            ToggleFullscreen();
        }

        // + DRAW LOOP + //
        
        // Draw to render texture
        BeginTextureMode(canvas);
        BeginMode2D(gameCamera);
            ClearBackground(DARKGRAY);

            // Circle
            DrawCircleV((Vector2){50, 50}, 20, WHITE);

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

            // Draw whatever you want to appear on top of the render texture at native window resolution

            // Stats display
            DrawFPS(0, 0);

        EndDrawing();
    }

    UnloadRenderTexture(canvas);
    CloseWindow();

    return 0;
}