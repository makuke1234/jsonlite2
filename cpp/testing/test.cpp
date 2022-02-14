#include <jsonlite2.hpp>
#include "json.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

#include <cstring>
#include <ctime>

template<typename T, typename Func>
void test(const std::string & contents, const std::string & what, std::size_t maxIter, T, Func function)
{
	T obj;
	auto start = std::clock();
	for (std::size_t i = 0; i < maxIter; ++i)
	{
		obj = function(contents);
	}
	auto stop = std::clock();
	std::cout << "Time elapsed (" << what << "):\t" << double(stop - start) / double(CLOCKS_PER_SEC) << " seconds.\n";
}

int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		std::cerr << "Filename not given!\n";
		return 1;
	}
	else if (argc < 3)
	{
		std::cerr << "Iteration count not given!\n";
		return 1;
	}

	std::vector<const char *> filenames;
	for (int i = 1; i < (argc - 1); ++i)
	{
		filenames.emplace_back(argv[i]);
	}

	auto MAX_ITER = std::strtoul(argv[argc - 1], nullptr, 10);
	
	for (auto i : filenames)
	{
		std::cout << "Testing file \"" << i << "\":\n";
		std::ifstream inp(i);
		if (!inp.good())
		{
			std::cerr << "Error opening file!" << std::endl;
			return 1;
		}

		std::stringstream ss;
		ss << inp.rdbuf();

		inp.close();

		std::string contents = ss.str();

		std::cout << "Contents length: " << contents.length() << " bytes\n";

		test(contents, "jsonlite2", MAX_ITER, jsonlite2::json(), [](const std::string & cont){ return jsonlite2::json::parse(cont); });
		test(contents, "nlohmann::json", MAX_ITER, nlohmann::json(), [](const std::string & cont){ return nlohmann::json::parse(cont); });

		std::cout << '\n';
	}

	return 0;
}
