#include <raylib.h>

// + CONSTANTS
// Render dimensions
const int renderWidth = 480;
const int renderHeight = 270;

// Transparent color for window transparency effects
const Color noColor = { 0, 0, 0, 0 };

// Player constants
const int playerSpeed = 100;


// + PROGRAM MAIN ENTRY POINT
int main(void)
{

    // Initialization
    SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(960, 720, "Raylib Template");
    // SetExitKey(KEY_F4);

    // Load render texture
    RenderTexture2D canvas = LoadRenderTexture(renderWidth, renderHeight);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_BILINEAR);

    // Player variables
    Vector2 playerPosition = { renderWidth/2, renderHeight/2 }; 
    Vector2 playerDirection = { 0 };
    
    // Camera
    Camera2D camera = { 0 };
    camera.offset = (Vector2){ renderWidth/2, renderHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;


    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // + UPDATE LOOP
        // Delta time (framerate independence)
        float deltaTime = GetFrameTime();

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
        playerDirection = (Vector2){ (int)IsKeyDown(KEY_D) - (int)IsKeyDown(KEY_A), (int)IsKeyDown(KEY_S) - (int)IsKeyDown(KEY_W) };

        playerPosition.x += playerDirection.x * playerSpeed * deltaTime;
        playerPosition.y += playerDirection.y * playerSpeed * deltaTime;

        // Camera follows player
        camera.target = (Vector2){ playerPosition.x, playerPosition.y };


        // Keybindings
        if (IsKeyPressed(KEY_F3))
        {
            ToggleFullscreen();
        }


        // + DRAW LOOP
        // Draw to render texture
        BeginTextureMode(canvas);
        ClearBackground(BLACK);
        BeginMode2D(camera);

        // Draw player
        DrawCircleV(playerPosition, 20, RED);

        EndMode2D();
        EndTextureMode();

        // Drawing to native window resolution
        BeginDrawing();
        ClearBackground(noColor);

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


        // Rendering stats
        DrawFPS(0, 0);
        DrawText(TextFormat("Window size: %ix%i", windowWidth, windowHeight), 2, 20, 20, WHITE);
        DrawText(TextFormat("Render scale: %ix", renderScale), 2, 40, 20, WHITE);
        DrawText(TextFormat("Scaled size: %ix%i", scaledWidth, scaledHeight), 2, 60, 20, WHITE);

        // Player stats
        DrawText(TextFormat("Player position: %ix%i", (int)playerPosition.x, (int)playerPosition.y), 2, 80, 20, WHITE);

        if (playerDirection.x == 1)
        {
            DrawText("Player direction: E", 2, 100, 20, WHITE);
        }

        else if (playerDirection.x == -1)
        {
            DrawText("Player direction: W", 2, 100, 20, WHITE);
        }



        EndDrawing();
    }

    UnloadRenderTexture(canvas);
    CloseWindow();

    return 0;
}