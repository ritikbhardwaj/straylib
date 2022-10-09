#pragma once

#include <string>
#include <raylib.h>

class TextSnippet
{
    public:
        TextSnippet(const std::string& text, Font font);
        void setPosition(Vector2 position);
        void setText(const std::string& text);
        void drawSnippet();
    private:
        std::string _text = "";
        std::string _title = "SNIPPET TITLE";
        int _padding = 5;
        Font _font;
        Vector2 _position = (Vector2){ 0, 0 };
};
