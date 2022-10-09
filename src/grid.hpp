#pragma once

#include <raylib.h>

enum class GridOrientation {
    VERTICAL = 0,
    HORIZONTAL,
    COMPLETE
};

class Grid
{
    public:
        Grid();
        // Grid(int width, int height, int increment, Color color, GridOrientation orientation);
        void draw() const;
        int getIncrement();
        void resizeBy(int value);
        Grid* color(Color color);
        Grid* increment(int value);
        Grid* orientation(GridOrientation orientation);
        Grid* width(int width);
        Grid* height(int height);
        Grid* showHoverRect(bool show, Color color = BLUE);
        void drawHoverRect(Color color = BLUE);
        Vector2 getGridMousePosVec() const;
    private:
        int _increment = 10;
        GridOrientation _orientation;
        int _width = 200;
        int _height = 200;
        Color _gridColor = BLACK;
        bool _showHoverRect = false;
        Color _hoverRectColor = BLUE;
        void _drawVertical() const;
        void _drawHorizontal() const;
};
