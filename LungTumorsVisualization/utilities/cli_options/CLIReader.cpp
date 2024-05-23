#include "CLIReader.h"

CLIReader::CLIReader(int argc, char** argv)
{
	std::string key, value;
	for (int i = 1; i < argc; i++)
	{
		std::string current_arg(argv[i]);
		if (current_arg.length() >= 1 && current_arg.at(0) == '-')
		{
			key = current_arg.substr(1, current_arg.length() - 1);
		}
		else
		{
			value = current_arg;
			if (i % 2 == 0)
			{
				options.insert(make_pair(key, value));
			}
		}
	}
}


std::optional<std::string> CLIReader::get_option_value(std::string option_key)
{
	auto found = options.find(option_key);

	if (found == options.end())
		return {};

	return found->second;
}
