#ifndef CSVReader_H
#define CSVReader_H

#include <string>
#include <map>
#include <nodule_information.h>

class CSVReader
{
	static const char delimeter = ',';
public:
	static std::map<std::string, nodule_information> get_nodules_clustering_map(
		std::string path_to_file);
};


#endif // !CSVReader_H
