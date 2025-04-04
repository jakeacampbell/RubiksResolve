#pragma once

#include <iostream>

#include "CubeTypes.h"
#include "CubeOperations.h"

cube active_cube_rep = DEFAULT_CUBE_CONTENT;

int main(int argc, char* argv[]) {
	char face_index;
	std::cout << "Enter to end..";
	std::cin >> face_index;

	std::cout << visualize_cube(active_cube_rep);

	std::cin.get();

	return EXIT_SUCCESS;
}