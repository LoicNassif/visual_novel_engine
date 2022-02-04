#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>

struct Character {
    unsigned int TextureID;
};

class TextEngine {
public:
    TextEngine() {};
    ~TextEngine();

    int init(const char* font, int charWidth=0, int charHeight=48);

private:
    FT_Library ft;
};