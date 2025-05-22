#include <stdio.h>
#include "Window.h"

namespace {
    GLFWwindow* window = nullptr;
}

GLFWwindow* GetGLFWWindow() {
    return window;
}

void InitializeWindow(int width, int height, const char* name) {
    //glfwInit() initialize GLFW library
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    if (!glfwVulkanSupported()){
        fprintf(stderr, "Vulkan not supported\n");
        exit(EXIT_FAILURE);
    }

    //glfw最初目的是创建OpenGL context，所以要告诉它不要在后续
    //调用中创建OpenGL context。
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //create window
    window = glfwCreateWindow(width, height, name, nullptr, nullptr);

    if (!window) {
        fprintf(stderr, "Failed to initialize GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

bool ShouldQuit() {
    return !!glfwWindowShouldClose(window);
}

void DestroyWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
