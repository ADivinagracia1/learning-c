#include <stdio.h>
#include <GLFW/glfw3.h>
#include <leif/leif.h>

int main(){
    printf("Hello todo!\n:");

    /* GLFW: Initialize the library */
    if (!glfwInit())
        return -1;

    /* GLFW: Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Todo", NULL, NULL);
    if (!window){
        glfwTerminate();
        return -1;
    }

    /* GLFW: make the window's context current */
    glfwMakeContextCurrent(window);

    lf_init_glfw(1280, 720, window);

    /* GLFW: Loop until the user closes the window */
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        lf_begin();
        lf_end();


        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}