#include "Tumor.h"
#include "GLM/glm.hpp"
#include "GLM/gtx/quaternion.hpp"
#include "GLM/gtc/quaternion.hpp"

Tumor::Tumor(std::string path, std::string shader_path): shader(shader_path.c_str())
{
	loadModel(path);
}

void Tumor::Draw(glm::vec3 position, Camera camera,
    int screen_width, int screen_height, glm::vec3 color, float near, float far,
    float model_scaling_factor)
{
    shader.use();

    auto quat = glm::quat(glm::vec3(glm::radians(theta), glm::radians(phi), 0));
    auto rotation_mat = glm::toMat4(quat);

    auto model = glm::mat4(1.0f);

    model = glm::translate(model, position);
    model *= rotation_mat;
    model = glm::scale(model, glm::vec3(model_scaling_factor));

    shader.set4Matrix("model", model);

    auto view = camera.GetViewMatrix();
    shader.set4Matrix("view", view);

    auto projection = glm::perspective(glm::radians(camera.Zoom), (float)screen_width / (float)screen_height, near, far);
    shader.set4Matrix("projection", projection);

    shader.setVec3("viewPos", camera.Position);

    shader.setVec3("color", color);

	for (const auto& mesh : meshes)
		mesh.Draw(shader);
}

void Tumor::Draw(Camera camera, int distance_scaling_factor,
    int screen_width, int screen_height, float near, float far,
    int current_x, int current_y, int current_z, float model_scaling_factor)
{
    position.x = metrics.params[current_x];
    position.y = metrics.params[current_y];
    position.z = metrics.params[current_z];

    position *= distance_scaling_factor;

    Draw(position, camera, screen_width, screen_height, color, near, far, model_scaling_factor);
}

void Tumor::add_X_rotation(float rotation_degrees)
{
    theta += rotation_degrees;

    int whole_rotations = (int)(theta / 360);
    if (whole_rotations > 0)
        theta -= whole_rotations * 360.0f;
}

void Tumor::add_Y_rotation(float rotation_degrees)
{
    phi += rotation_degrees;

    int whole_rotations = (int)(phi / 360);
    if (whole_rotations > 0)
        phi -= whole_rotations * 360.0f;
}

void Tumor::add_rotation(tumor_rotation rotation)
{
    add_X_rotation(rotation.x);
    add_Y_rotation(rotation.y);
}

Tumor::Tumor(std::string path, Shader& shader, glm::vec3 color, nodule_information& _metrics)
    :shader(shader), color(color), metrics(_metrics)
{
    loadModel(path);
}