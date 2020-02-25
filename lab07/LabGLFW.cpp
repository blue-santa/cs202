#include <GLFW/glfw3.h>
#include <cmath>

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "OpenGL32.lib")

int not_main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Clear color
        glClearColor(0.5, 0.4, 0.3, 1);

        // Draw a triangle
        glBegin(GL_TRIANGLES);
        glVertex3f(-1.0f, -1.0f, 0.0f); // bottom left
        glVertex3f(1.0f, -1.0f, 0.0f); // bottom right
        glVertex3f(0.0f, 1.0f, 0.0f); // middle top
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

