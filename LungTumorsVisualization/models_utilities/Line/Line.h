#include <vector>
#include "GLM/glm.hpp"
#include "shaders/Shader.h"
#include "camera/camera.h"

class Line
{
private:
	std::vector<float> vertices;
	glm::vec3 start = glm::vec3(0.0f);
	glm::vec3 end = glm::vec3(0.0f);
	glm::mat4 model = glm::mat4(1.0f);
	Shader line_shader;

	glm::vec3 color = glm::vec3(1.0f);

	GLuint vao = 0, vbo =0;
public:
	Line(glm::vec3 start, glm::vec3 end, std::string shader_path, glm::vec3 color):
		start(start), end(end), line_shader(shader_path.c_str()), color(color)
	{
		vertices = {
			start.x, start.y, start.z,
			end.x, end.y, end.z
		};

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices.size(), vertices.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}


	void Draw(Camera camera, int screen_width, int screen_height)
	{
		line_shader.use();
		line_shader.set4Matrix("model", model);

		auto view = camera.GetViewMatrix();
		line_shader.set4Matrix("view", view);

		auto projection = glm::perspective(glm::radians(camera.Zoom), (float)screen_width / (float)screen_height, 0.1f, 100.0f);
		line_shader.set4Matrix("projection", projection);


		line_shader.setVec3("color", color);

		glBindVertexArray(vao);
		glDrawArrays(GL_LINES, 0, 2);
	}

	~Line()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
	}

};