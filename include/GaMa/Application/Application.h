#ifndef APPLICATION_H
#define APPLICATION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace GaMa{

    struct Window
    {
        GLFWwindow* window;
        int width;
        int height;
        const char* title;
    };
    

    class Application{
        
        public:
            Application();
            Application(int width, int height, const char* title);

            void Run();

        private:
            Window m_win;

            friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
            friend void processInput(GLFWwindow *window);

            int Init();

    };

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

#endif