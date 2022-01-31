#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class RenderEngine
{
public:
    RenderEngine() {};
    ~RenderEngine() { glfwTerminate(); };
    int init();
    void loop();

private:
    GLFWwindow* window;
};