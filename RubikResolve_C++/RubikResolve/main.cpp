#pragma once

#include <iostream>

#include "cube_types.h"
#include "cube_operations.h"

int main(int argc, char* argv[]) {
	Cube active_cube_rep = DEFAULT_CUBE_CONTENT;

	std::cout << visualize_cube(active_cube_rep);

	rotate_row_right(active_cube_rep, GridAlignVertical::BOTTOM);
	std::cout << "\n";
	std::cout << "Rotating right (CENTRE)\n";
	std::cout << "\n";
	std::cout << visualize_cube(active_cube_rep);
	
	/*rotate_row_left(active_cube_rep, GridAlignVertical::TOP);
	std::cout << "\n";
	std::cout << "Rotating Left (TOP) \n";
	std::cout << "\n";
	std::cout << visualize_cube(active_cube_rep);

	rotate_col_down(active_cube_rep, GridAlignHorizontal::RIGHT);
	std::cout << "\n";
	std::cout << "Rotating DOWN (RIGHT) \n";
	std::cout << "\n";
	std::cout << visualize_cube(active_cube_rep);

	rotate_col_up(active_cube_rep, GridAlignHorizontal::LEFT);
	std::cout << "\n";
	std::cout << "Rotating UP (LEFT) \n";
	std::cout << "\n";
	std::cout << visualize_cube(active_cube_rep);*/

	std::cin.get();

	return EXIT_SUCCESS;
}