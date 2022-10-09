#include "grid.hpp"
#include <raylib.h>
#include <iostream>
#include <cmath>

Grid::Grid() {}

void Grid::_drawVertical() const
{
    for(int i = 0; i < _width; i+=_increment) {
        DrawLineEx((Vector2){ static_cast<float>(i), 0 }, (Vector2){ static_cast<float>(i), static_cast<float>(_height) }, 1, GRAY);
    }
}

void Grid::_drawHorizontal() const
{
    for(int i = 0; i < _height; i+=_increment) {
        DrawLineEx((Vector2){ 0, static_cast<float>(i) }, (Vector2){ static_cast<float>(_width), static_cast<float>(i) }, 1, GRAY);
    }
}

void Grid::drawHoverRect(Color color)
{
    if(!_showHoverRect) return;

    Rectangle hoverRect = {0, 0, static_cast<float>(_increment), static_cast<float>(_increment) };
    Vector2 mousePosVec = GetMousePosition();
    _hoverRectColor = color;
    hoverRect.x = getGridMousePosVec().x;
    hoverRect.y = getGridMousePosVec().y;
    DrawRectangleRec(hoverRect, _hoverRectColor);
}

Vector2 Grid::getGridMousePosVec() const
{
    Vector2 gridMousePosVec = {0, 0};
    Vector2 mousePosVec = GetMousePosition();
    gridMousePosVec.x = std::floor(mousePosVec.x/_increment)*_increment;
    gridMousePosVec.y = std::floor(mousePosVec.y/_increment)*_increment;
    return gridMousePosVec;
}

Grid* Grid::showHoverRect(bool show, Color color)
{
    _showHoverRect = show;
    _hoverRectColor = color;
    return this;
}

void Grid::resizeBy(int value)
{
    if(_increment + value == 0) {
        std::cout << "Increment cannot be set to 0." << std::endl;
        return;
    }

    _increment += value;
}

void Grid::draw() const
{
    if(_orientation == GridOrientation::VERTICAL) {
        _drawVertical();
    }

    if(_orientation == GridOrientation::HORIZONTAL) {
        _drawHorizontal();
    }

    if(_orientation == GridOrientation::COMPLETE) {
        _drawHorizontal();
        _drawVertical();
    }
}

Grid* Grid::orientation(GridOrientation orientation) {
    _orientation = orientation;
    return this;
}

Grid* Grid::color(Color color)
{
    _gridColor = color;
    return this;
}

Grid* Grid::width(int width)
{
    _width = width;
    return this;
}

Grid* Grid::height(int height)
{
    _height = height;
    return this;
}

Grid* Grid::increment(int value)
{
    _increment = value;
    return this;
}

int Grid::getIncrement()
{
    return _increment;
}
