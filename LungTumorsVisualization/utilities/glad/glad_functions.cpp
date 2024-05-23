#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include <iostream>
#include "utilities/report_error/report_error.h"

void loadGlad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        err("failed to load GL functions with glad");
}