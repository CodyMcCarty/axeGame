#include "raylib.h"
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int viewWidth{1280};
    int viewHeight{720};
    const char *title = "Axe Game";
    int centerX{viewWidth / 2};
    int centerY{viewHeight / 2};
    bool collisionWithAxe{false};

    // Circle
    int circleX_pos{centerX};
    int circleY_pos{centerY};
    int circleRadius{25};
    int leftCircleX_collision{circleX_pos - circleRadius};
    int rightCircleX_collision{circleX_pos + circleRadius};
    int topCircleY_collision{circleY_pos - circleRadius};
    int bottomCircleY_collision{circleY_pos + circleRadius};

    // Axe
    int axeX_pos{viewWidth / 3};
    int axeY_pos{viewHeight / 3};
    int axeSize{50};
    int axeMove{10};
    int leftAxeX_collision{axeX_pos};
    int rightAxeX_collision{axeX_pos + axeSize};
    int topAxeY_collision{axeY_pos};
    int bottomAxeY_collision{axeY_pos + axeSize};

    InitWindow(viewWidth, viewHeight, title);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(axeX_pos, axeY_pos, axeSize, axeSize, RED);
        DrawCircle(circleX_pos, circleY_pos, circleRadius, BLUE);

        leftAxeX_collision = axeX_pos;
        rightAxeX_collision = axeX_pos + axeSize;
        topAxeY_collision = axeY_pos;
        bottomAxeY_collision = axeY_pos + axeSize;
        leftCircleX_collision = circleX_pos - circleRadius;
        rightCircleX_collision = circleX_pos + circleRadius;
        topCircleY_collision = circleY_pos - circleRadius;
        bottomCircleY_collision = circleY_pos + circleRadius;
        collisionWithAxe =
            (bottomAxeY_collision >= topCircleY_collision) &&
            (topAxeY_collision <= bottomCircleY_collision) &&
            (rightAxeX_collision >= leftCircleX_collision) &&
            (leftAxeX_collision <= rightCircleX_collision);

        if (collisionWithAxe)
        {
            DrawText("Game Over!", centerX, centerY, 20, RED);
        }
        else
        {

            if (bottomAxeY_collision > viewHeight || topAxeY_collision < 0)
            {
                axeMove = -axeMove;
            }
            axeY_pos += axeMove;

            if (IsKeyDown(KEY_D) && rightCircleX_collision < viewWidth)
            {
                circleX_pos += 10;
            }
            if (IsKeyDown(KEY_A) && leftCircleX_collision > 0)
            {
                circleX_pos -= 10;
            }
        }

        EndDrawing();
    }
}