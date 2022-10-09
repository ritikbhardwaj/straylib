#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <raylib.h>

class FontLoader
{
    public:
        FontLoader(const std::string& fontDirPath, const std::vector<std::string>& fonts, int size = 30);
        void loadFonts(const std::vector<std::string>& fonts, int size);
        Font getFont(const std::string& fontName) const;

    private:
        void _setFontDirPath(const std::string& fontDirPath);
        std::string _fontDirPath = "";
        std::unordered_map<std::string, Font> _fonts;


};
