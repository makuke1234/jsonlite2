#include <jsonlite2.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		std::cerr << "File name not given!\n";
		return 1;
	}
	
	jsonlite2::json obj;
	{
		std::ifstream inp(argv[1]);
		if (!inp.good())
		{
			std::cerr << "Error opening file!\n";
			return 1;
		}

		std::stringstream ss;
		ss << inp.rdbuf();

		inp.close();

		std::string contents = ss.str();

		std::cout << "Loaded contents of JSON:\n" << contents << '\n';
		std::cout << "Contents length: " << contents.length() << " bytes\n";

		obj = jsonlite2::json::parse(contents);
	}

	std::cout << "Parsed contents of JSON file:\n" << obj.dump() << '\n';

	return 0;
}
