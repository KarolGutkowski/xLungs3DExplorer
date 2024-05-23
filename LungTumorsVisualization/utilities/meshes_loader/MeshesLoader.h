#ifndef MESHES_LOADER_H
#define MESHES_LOADER_H

#include "models_utilities/Tumor/Tumor.h"
#include <map>
#include <vector>
#include <nodule_information.h>

class MeshesLoader
{
	static const std::string meshes_file_extension;
	static const std::vector<glm::vec3> clusters_colors;
public:
	static std::vector<Tumor> load_clustering_data(std::string meshes_folder_path, std::map<std::string, nodule_information> clustering, Shader& shared_shader);
};


#endif // !MESHES_LOADER_H
