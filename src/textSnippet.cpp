#include "textSnippet.hpp"

TextSnippet::TextSnippet(const std::string& text, Font font) {
    _text = text;
    _font = font;
}

void TextSnippet::drawSnippet()
{
    // Vector2 snippetRectSize = { static_cast<float>(100 + 2*_padding), static_cast<float>(100 + 2*_padding) };
    // Rectangle snippetRectangle = { _position.x, _position.y, static_cast<float>(500), static_cast<float>(100) };
    // DrawRectangleV(_position, snippetRectSize, GRAY);
    Vector2 textSize = MeasureTextEx(_font, _text.c_str(), _font.baseSize, 0);
    DrawRectangleV((Vector2){ _position.x - _padding, _position.y - _padding }, (Vector2){ textSize.x + 2*_padding, textSize.y + 2*_padding }, (Color){ 0, 48, 73, 255 });
    // DrawRectangleRec(snippetRectangle, GRAY);
    DrawTextEx(_font, _text.c_str(), _position, _font.baseSize, 0, WHITE);
    DrawTextEx(_font, _title.c_str(), (Vector2){ _position.x - _padding, _position.y + 40 }, _font.baseSize, 0, GRAY);
}

void TextSnippet::setPosition(Vector2 position)
{
    _position = position;
}

void TextSnippet::setText(const std::string& text)
{
    _text = text;
}
