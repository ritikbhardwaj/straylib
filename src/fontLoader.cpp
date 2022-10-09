#include "fontLoader.hpp"
#include <iostream>

FontLoader::FontLoader(const std::string& fontDirPath, const std::vector<std::string>& fonts, int size) {
    _setFontDirPath(fontDirPath);
    loadFonts(fonts, size);
};

void FontLoader::loadFonts(const std::vector<std::string>& fonts, int size = 30) {
    if(_fontDirPath == "")
    {
        std::cout << "Error: FontLoader: Please set font directory first." << std::endl;
        return;
    }

    for(auto& font : fonts) {
        std::string fullFontPath = _fontDirPath + "/" + font;
        std::cout << "DEBUG: font full path: " << _fontDirPath + "/" + font << std::endl;

        if(!FileExists(fullFontPath.c_str()))
        {
            std::cout << "Error: FontLoader: Could not resolve font at: " << fullFontPath << std::endl;
            continue;
        }

        _fonts[font] = LoadFontEx((_fontDirPath + "/" +font).c_str(), size, nullptr, 0);
    }
}

/**
 * @note handle std::out_of_range exception when fontName is not found in the map.
 */
Font FontLoader::getFont(const std::string& fontName) const
{
    if(_fonts.find(fontName) == _fonts.end())
    {
        std::cout << "Error: FontLoader: Could not find font: " << fontName << std::endl;
    }
    return _fonts.at(fontName);
}

/**
 * @private
 */
void FontLoader::_setFontDirPath(const std::string& fontDirPath)
{
    if(!DirectoryExists(fontDirPath.c_str()))
    {
        std::cout << "Error: FontLoader: Invalid font directory." << std::endl;
        return;
    }

    _fontDirPath = fontDirPath;
}
