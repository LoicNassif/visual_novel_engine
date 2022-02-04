#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifdef _MSC_VER
#define DEBUG_BREAK __debugbreak()
#else
#define DEBUG_BREAK raise(SIGTRAP)
#endif

#define ASSERT(x) \
    if (!(x))     \
        DEBUG_BREAK;
#define GLCall(x)   \
    GLClearError(); \
    x;              \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);

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