#pragma once

#include <iostream>

#include "CubeTypes.h"
#include "CubeOperations.h"

cube active_cube_rep = DEFAULT_CUBE_CONTENT;

int main(int argc, char* argv[]) {
	int face_index;
	std::cout << "Select face: ";
	std::cin >> face_index;

	std::cout << visualize_grid(active_cube_rep[face_index]);

	std::cin.get();

	return EXIT_SUCCESS;
}