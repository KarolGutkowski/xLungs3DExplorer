#include "glad/glad.h"
#include "glfw_callbacks.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
    {
        // early return if mouse button is not clicked
        // meaning user isn't dragging currently
        return;
    }

}


void process_input(GLFWwindow* window, tumor_rotation& added_rotation, Camera& camera)
{
    static double xprev, yprev;
    static double xpos, ypos;

    xprev = xpos;
    yprev = ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        float xoffset = xpos - xprev;
        float yoffset = yprev - ypos;

        float unit_of_rotation_in_degrees = 2.0f;

        added_rotation.x = (-yoffset) * unit_of_rotation_in_degrees;
        added_rotation.y = (xoffset) * unit_of_rotation_in_degrees;
    }
    else if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
    {
        static bool firstMouseMovement = true;

        float xoffset = xpos - xprev;
        float yoffset = yprev - ypos; // reversed since opengls y-coordinates range from top to bottom

        camera.ProcessMouseMovement(xoffset, yoffset);
    }

    static float lastFrame = 0.0f;
    float currentFrame = glfwGetTime();

    float deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.ProcessKeyboard(Camera_Movement::FORWARD, deltaTime);
    }
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(Camera_Movement::BACKWARD, deltaTime);
    }
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(Camera_Movement::LEFT, deltaTime);
    }
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(Camera_Movement::RIGHT, deltaTime);
    }
}