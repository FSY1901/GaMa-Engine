#include "Application.h"

#include <iostream>

namespace GaMa{

    Application::Application(){
        
    }

    Application::Application(int width, int height, const char* title){
        m_win.width = width;
        m_win.height = height;
        m_win.title = title;
    }

    int Application::Init(){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

        GLFWwindow* window = glfwCreateWindow(m_win.width, m_win.height, m_win.title, NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
        m_win.window = window;
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        return 0;
    }

    void Application::Run(){
        
        int err = Init();

        if(err == -1){
            std::cout << "ERROR HAPPENED WHEN TRYING TO RUN APPLICATION";
            return;
        }

        while (!glfwWindowShouldClose(m_win.window))
        {
            processInput(m_win.window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(m_win.window);
            glfwPollEvents();
        }

        glfwTerminate();
        
    }

}

//CALLBACKS
    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    void processInput(GLFWwindow *window)
    {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }