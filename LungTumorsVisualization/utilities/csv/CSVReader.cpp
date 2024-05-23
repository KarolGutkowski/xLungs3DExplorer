#include "CSVReader.h"
#include <iostream>
#include <fstream>


std::map<std::string, nodule_information> CSVReader::get_nodules_clustering_map(
    std::string path_to_file) {

  std::map<std::string, nodule_information> clustering;
  std::ifstream input_file;
  input_file.open(path_to_file, std::ios::in);

  std::string line;
  std::getline(input_file, line);
  uint8_t cluster_id = 0;

  while (std::getline(input_file, line)) {
    float params_from_csv[14];
    auto delimeter_position = line.find(delimeter);

    std::string nodule_id = line.substr(0, delimeter_position);
    for (int i = 0; i < 14; ++i) {
      auto next_delimeter = line.find(delimeter, delimeter_position + 1);
      auto string_length = next_delimeter - delimeter_position;
      params_from_csv[i] =
          std::stof(line.substr(delimeter_position + 1, string_length));
      delimeter_position = next_delimeter;
    }
    cluster_id = std::stoi(line.substr(delimeter_position + 1, 1));

    nodule_information current_nodule_information;
    current_nodule_information.cluster_id = cluster_id;
    std::copy(std::begin(params_from_csv), std::end(params_from_csv),
              std::begin(current_nodule_information.params));
    clustering.insert(std::make_pair(nodule_id, current_nodule_information));
  }

  return clustering;
}

