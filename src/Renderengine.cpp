#include <iostream>

#include "Renderengine.hpp"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int RenderEngine::init() 
{
    // Init the GLFW library
    if (!glfwInit()) {
        return -1;
    }

    // Use core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    // Create a windowed mode window
    window = glfwCreateWindow(1280, 920, "TEST", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout << "Failed to create GLFW window\n";
        return -1;
    }

    // Sync animation with framerate
    glfwSwapInterval(1);

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cout << "Failed to init GLAD" << std::endl;
        return -1;
    }

    return 0;
}

void RenderEngine::loop() 
{
    // Main render loop
    while (!glfwWindowShouldClose(window)) 
    {
        processInput(window);

        glClearColor(0.5f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}