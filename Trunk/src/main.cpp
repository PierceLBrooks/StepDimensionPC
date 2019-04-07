
// Author: Pierce Brooks

#include <IDC/IDC.hpp>
#include <IDC/Game.hpp>
#include <vector>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
	idc::Game* game = new idc::Game();
	std::vector<std::string> arguments;
	for (int i = 0; i != argc; ++i)
	{
		arguments.push_back(std::string(argv[i]));
		std::cout << i << " = " << arguments.back() << std::endl;
	}
	return 0;
}

