#include "textengine.hpp"
#include <iostream>

int TextEngine::init(const char* font, int charWidth, int charHeight) 
{
    if (FT_Init_FreeType(&ft)) 
    {
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        return -1;
    }

    FT_Face face;
    if (FT_New_Face(ft, font, 0, &face)) 
    {
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
        return -1;
    }

    FT_Set_Pixel_Sizes(face, charWidth, charHeight);
}

TextEngine::~TextEngine() {}