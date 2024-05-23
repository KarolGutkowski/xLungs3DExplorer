#ifndef CLI_READER_H
#define CLI_READER_H

#include <optional>
#include <string>
#include <map>


class CLIReader
{
private:
	std::map<std::string, std::string> options;
public:
	CLIReader(int argc, char** argv);
	std::optional<std::string> get_option_value(std::string option_key);
};



#endif // !CLI_READER_H
