#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <GaMa.h>

using namespace GaMa;

int main()
{

    Application app(800, 600, "Application");

    app.Run();

    return 0;
}

