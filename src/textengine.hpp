#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include "shader.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <map>

struct Character {
    unsigned int TextureID;     // Glyph ID
    glm::ivec2 size;       // Size of glyph
    glm::ivec2 bearing;    // Offset from baseline to left/top of glyph
    unsigned int advance;       // Offset to advance to next glyph
};

std::map<char, Character> Characters;

class TextEngine {
public:
    TextEngine() {};
    ~TextEngine();

    int init(const char* font, int charWidth=0, int charHeight=48);
    void setupMemory();
    void renderText(Shader& s, std::string text, float x, float y, float scale, glm::fvec3 color);

private:
    FT_Library ft;
    FT_Face face;
    unsigned int VAO, VBO;
};