#include "MeshesLoader.h"
#include <filesystem>
#include <iostream>

const std::string MeshesLoader::meshes_file_extension = ".stl";

const std::vector<glm::vec3> MeshesLoader::clusters_colors = {
		glm::vec3(0.56f, 0.77f, 0.85f),
		glm::vec3(0.96f, 0.67f, 0.24f),
		glm::vec3(0.22f, 0.68f, 0.29f),
		glm::vec3(0.859f, 0.235f, 0.063f),
		glm::vec3(0.624f, 0.271f, 0.949f),
		glm::vec3(0.561f, 0.424f, 0.282f),
		glm::vec3(0.929f, 0.702f, 0.886f),
		glm::vec3(0.561f, 0.561f, 0.561f),
		glm::vec3(0.984f, 0.988f, 0.514f),
		glm::vec3(0.639f, 0.925f, 0.98f)
};


std::vector<Tumor> MeshesLoader::load_clustering_data(std::string meshes_folder_path, std::map<std::string, nodule_information> clustering, Shader& shared_shader)
{
	std::vector<Tumor> meshes;

	for (const auto& dir_entry : std::filesystem::recursive_directory_iterator(meshes_folder_path))
	{
		if (!dir_entry.is_regular_file())
			continue;
		
		std::filesystem::path file_path(dir_entry.path());

		if (!file_path.has_extension() || file_path.extension() != meshes_file_extension)
			continue;

		auto filename = file_path.filename().string();
		filename = filename.substr(0, filename.find("_aligned"));

		auto search_result = clustering.find(filename);
		if (search_result != clustering.end())
		{
			auto mesh_data = search_result->second;
			uint8_t cluster_index = mesh_data.cluster_id;

			glm::vec3 position = { 
                            mesh_data.params[0], mesh_data.params[1],
                            mesh_data.params[10]
			};

			meshes.push_back(Tumor(file_path.string(), 
				shared_shader, 
				clusters_colors.at(cluster_index), 
				mesh_data));
		}
	}

	return meshes;
}