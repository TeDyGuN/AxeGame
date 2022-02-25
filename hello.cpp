#include <raylib.h>
int main() {

    const int screenWidth{800};
    const int screenHeight{450};
    const float velocity{5.0f};
    int circleRadius{50};
    int axeLength{150};
    Vector2 ballPosition = { 50, 50 };
    Vector2 axePosition = {((float) screenWidth / 2), 0};
    // Circle Edges
    int l_circle_x{(int)ballPosition.x - circleRadius};
    int r_circle_x{(int)ballPosition.x + circleRadius};
    int u_circle_y{(int)ballPosition.y - circleRadius};
    int b_circle_y{(int)ballPosition.y + circleRadius};
    // Axe edges
    int l_axe_x{(int)axePosition.x};
    int r_axe_x{(int)axePosition.x + axeLength};
    int u_axe_y{(int)axePosition.y};
    int b_axe_y{(int)axePosition.y + axeLength};
    InitWindow(screenWidth, screenHeight, "Mi first game");
    SetTargetFPS(60);
    int i{2};
    bool collision_with_axe = (b_axe_y >= u_circle_y) && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x;
    while (!WindowShouldClose())   
    {
        if ( IsKeyDown(KEY_RIGHT) && ballPosition.x < screenWidth ) ballPosition.x += velocity;
        if ( IsKeyDown(KEY_DOWN) && ballPosition.y < screenHeight ) ballPosition.y += velocity;
        if ( IsKeyDown(KEY_LEFT) && ballPosition.x > 0 ) ballPosition.x -= velocity;
        if ( IsKeyDown(KEY_UP) && ballPosition.y > 0 ) ballPosition.y -= velocity;
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if ( collision_with_axe ) {
                DrawText("Game Over!", 350, 200, 20, LIGHTGRAY);
            } else {
                // Update the Edges
                l_circle_x = ballPosition.x - circleRadius;
                r_circle_x = ballPosition.x + circleRadius;
                u_circle_y = ballPosition.y - circleRadius;
                b_circle_y = ballPosition.y + circleRadius;
                l_axe_x = axePosition.x;
                r_axe_x = axePosition.x + axeLength;
                u_axe_y = axePosition.y;
                b_axe_y = axePosition.y + axeLength;

                collision_with_axe = (b_axe_y >= u_circle_y) && u_axe_y <= b_circle_y && l_axe_x <= r_circle_x && r_axe_x >= l_circle_x;

                DrawCircle(ballPosition.x, ballPosition.y, circleRadius, BLUE);
                DrawRectangle(axePosition.x, axePosition.y, axeLength, 100, RED);
                axePosition.y += i;
                if (axePosition.y == screenHeight - 100 || axePosition.y == 0) i = -i;

            }
            DrawFPS(10, 10);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}