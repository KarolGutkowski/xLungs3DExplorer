#ifndef TUMOR_H
#define TUMOR_H

#include "models_utilities/Model/Model.h"
#include "tumor_rotation.h"
#include <nodule_information.h>

class Tumor : public Model
{
private:
	Shader shader;
	glm::vec3 color = glm::vec3(0.0f);
	glm::vec3 position = glm::vec3(0.0f);
	nodule_information metrics;
	float theta = 0.0f; // accumulated rotation around X axis
	float phi = 0.0f; // accumulated rotation around Y axis;
	void add_X_rotation(float rotation_degrees);
	void add_Y_rotation(float rotation_degrees);
public:
	Tumor(std::string path, std::string shader_path);
	Tumor(std::string path, Shader& shader, glm::vec3 color, nodule_information& _metrics);
	void Draw(glm::vec3 position, Camera camera,
		int screen_width, int screen_height, glm::vec3 color, 
		float near, float far, float model_scaling_factor);
	void Draw(Camera camera, int distance_scaling_factor,
		int screen_width, int screen_height, float near, float far, 
		int current_x, int current_y, int current_z, float model_scaling_factor);
	void add_rotation(tumor_rotation rotation);
};


#endif // !TUMOR_H
