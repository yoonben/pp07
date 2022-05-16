#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>

#pragma comment(lib,"OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{

    float h1 = 0.0f;
    float h2 = -0.04f;

    float x1 = 0.8f;
    float x2 = 0.84f;

    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);



    while (!glfwWindowShouldClose(window))
    {

        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;




        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);


        if (GetAsyncKeyState(VK_SPACE) && -0x8000 || GetAsyncKeyState(VK_SPACE) && -0x8001)
        {
            h1 = 0.05f;
            h2 = 0.10f;
        }
        else
        {
            h1 = -0.1f;
            h2 = -0.15f;
        }




        glPointSize(5);
        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, h1);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.83f, h1);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.83f, h2);

        glEnd();

        glPointSize(5);

        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, h1);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, h2);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.83f, h2);

        glEnd();

        glPointSize(5);

        glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x1, -0.18f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x2, -0.18f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x1, 0.01f);

        glEnd();


        x1 = x1 - 0.01f;
        x2 = x2 - 0.01f;


        if (x1 <= -1.2f && x2 <= -1.17f)
        {
            x1 = 0.8f;
            x2 = 0.84f;
        }


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}