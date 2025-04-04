#pragma once

#include <iostream>

#include "CubeTypes.h"
#include "CubeOperations.h"

cube active_cube_rep = DEFAULT_CUBE_CONTENT;

int main(int argc, char* argv[]) {
	std::cout << "Hello World\n";

	std::cout << grid_to_str(active_cube_rep[5][3]);
	
	int n;
	std::cin >> n;

	return EXIT_SUCCESS;
}