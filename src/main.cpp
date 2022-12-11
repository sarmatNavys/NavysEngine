#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<iostream>

int g_WindowSizeX = 640;
int g_WindowSizeY = 480;

void WindowSizeCallback(GLFWwindow* window, int sizeX, int sizeY)
{
    g_WindowSizeX = sizeX;
    g_WindowSizeY = sizeY;
    glViewport(0, 0, g_WindowSizeX, g_WindowSizeY);
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

void InitializeOpenGL()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "glfwInit Failed" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(g_WindowSizeX, g_WindowSizeY, "Navys Engine", nullptr, nullptr);
    if (!window)
    {
        std::cout << "Window was not created. Error" << std::endl;
        glfwTerminate();
        return;
    }

    glfwSetWindowSizeCallback(window, WindowSizeCallback);
    glfwSetKeyCallback(window, KeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        std::cout << "Can't load GLAD" << std::endl;
        return;
    }

    std::cout << "Renderer" << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(0, 1, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return;
}

int main(void)
{
    InitializeOpenGL();
}