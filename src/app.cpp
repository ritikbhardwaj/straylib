#include "app.hpp"
#include "grid.hpp"
#include <cmath>
#include <raylib.h>
#include <raymath.h>
#include "fontLoader.hpp"
#include <string>
#include <iostream>

App* App::_instance = nullptr;

App::App(const int& width, const int& height, const char* title) {
    _width = width;
    _height = height;
    _title = title;
}

App::~App() {
    delete _title;
}

App* App::getAppInstance(const int& width, const int& height, const char* title)
{
    if(_instance == nullptr) {
        _instance = new App(width, height, title);
    }
    return _instance;
}

void App::initApp()
{
    InitWindow(_width, _height, _title);
    Grid* msh1 = new Grid();
    FontLoader fontLoader(
        "assets/font",
        (std::vector<std::string>)
        {
            "RobotoCondensed-Bold.ttf",
            "RobotoCondensed-Regular.ttf"
        },
        30
    );
    Font myFont = fontLoader.getFont("RobotoCondensed-Bold.ttf");

    /** Configure mesh */
    msh1
        ->color(GRAY)
        ->increment(50)
        ->orientation(GridOrientation::COMPLETE)
        ->width(_width)
        ->height(_height)
        ->showHoverRect(true);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(WHITE);

            Vector2 gridMousePosVec = msh1->getGridMousePosVec();
            int incr = msh1->getIncrement();
            std::string str = std::to_string((int)(gridMousePosVec.x/incr)) + ", " + std::to_string((int)(gridMousePosVec.y/incr));
            DrawTextEx(myFont, str.c_str(), (Vector2){ 20, 20 }, 30, 0, BLACK);
            msh1->drawHoverRect(GREEN);
            /****************** Mesh ***********************/
            msh1->draw();
            /***********************************************/

            /** Mouse position vector */
            Vector2 mousePosVec = GetMousePosition();

            if(IsKeyPressed(KEY_UP)) {
                msh1->resizeBy(2);
            }

            if(IsKeyPressed(KEY_DOWN)) {
                msh1->resizeBy(-1);
            }


            // INCR = msh1.getIncrement();
            // crossHairRect.width = static_cast<float>(INCR);
            // crossHairRect.height = static_cast<float>(INCR);

            // crossHairRect.x = std::floor(mousePosVec.x/INCR)*INCR;
            // crossHairRect.y = std::floor(mousePosVec.y/INCR)*INCR;
            // DrawRectangleRec(crossHairRect, BLUE);

            // if((mousePosVec.x >= rec1.x && mousePosVec.x <= rec1.x + rec1.width) && (mousePosVec.y <= rec1.y + rec1.height && mousePosVec.y >= rec1.y)) {
            //     DrawRectangleRec(rec1, BLUE);
            // } else {
            //     DrawRectangleRec(rec1, RED);
            // }

            /** Crosshair lines */
            DrawLineEx((Vector2){ mousePosVec.x, 0 }, (Vector2){ mousePosVec.x, static_cast<float>(_height) }, 1, RED);
            DrawLineEx((Vector2){ 0, mousePosVec.y }, (Vector2){ static_cast<float>(_width), mousePosVec.y }, 1, RED);
        EndDrawing();
    }

    CloseWindow();
}

