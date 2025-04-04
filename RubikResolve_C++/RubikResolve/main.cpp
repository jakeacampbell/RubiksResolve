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

	rotate_row_right(active_cube_rep, grid_align_vertical::CENTER);

	std::cout << "Rotating right (CENTRE)\n";

	std::cout << visualize_cube(active_cube_rep);
	
	rotate_row_left(active_cube_rep, grid_align_vertical::TOP);

	std::cout << "Rotating Left (TOP) \n";

	std::cout << visualize_cube(active_cube_rep);

	std::cin.get();

	return EXIT_SUCCESS;
}