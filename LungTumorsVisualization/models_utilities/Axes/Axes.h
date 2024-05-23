#include "models_utilities/Line/Line.h"

class Axes
{
private:
	Line zLine = Line(glm::vec3(0.0f, 0.0f, -100.0f),
        glm::vec3(0.0f, 0.0f, 100.0f),
        "./shaders/line_shader.glsl",
        glm::vec3(1.0f, 0.0f, 0.0f));

    Line xLine = Line(glm::vec3(100.0f, 0.0f, 0.0f),
        glm::vec3(-100.0f, 0.0f, 0.0f),
        "./shaders/line_shader.glsl",
        glm::vec3(0.0f, 1.0f, 0.0f));

    Line yLine = Line(glm::vec3(0.0f, -100.0f, 0.0f),
        glm::vec3(0.0f, 100.0f, 0.0f),
        "./shaders/line_shader.glsl",
        glm::vec3(0.0f, 0.0f, 1.0f));

    void display_in_front()
    {
        glClear(GL_DEPTH_BUFFER_BIT);
    }

public:
    // display_in_front - will cause whatever was rendered before (meaning in order in which we called drawing on other element) 
    // to be rendered behind
    // this doesn't allow to freely control positioning relative to items being rendered after this function
    void Draw(Camera camera, int screen_width, int screen_height, bool display_in_front = false)
    {
        if (display_in_front)
            this->display_in_front();

        xLine.Draw(camera, screen_width, screen_height);
        yLine.Draw(camera, screen_width, screen_height);
        zLine.Draw(camera, screen_width, screen_height);

    }
};