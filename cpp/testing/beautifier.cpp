#include <jsonlite2.hpp>

#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		std::cerr << "Filename not given!\n";
		return 1;
	}
	
	std::ifstream inp(argv[1]);
	if (!inp.good())
	{
		std::cerr << "File error!\n";
		return 1;
	}

	std::stringstream ss;
	ss << inp.rdbuf();
	inp.close();

	std::cout << jsonlite2::json::parse(ss.str()).dump() << std::flush;
	
	return 0;
}
