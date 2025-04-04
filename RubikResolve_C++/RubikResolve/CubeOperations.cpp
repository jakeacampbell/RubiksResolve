#include "CubeOperations.h"

char grid_to_char(const grid_t& grid)
{
	switch (grid) {
		case WHITE: return 'W';
		case YELLOW: return 'Y';
		case RED: return 'R';
		case GREEN: return 'G';
		case ORANGE: return 'O';
		case BLUE: return 'B';
		default: return 'X';
	}
}

void rotate_row_right(const cube& cube_to_rotate, const grid_align_vertical pos_v)
{
}

void rotate_row_left(const cube& cube_to_rotate, const grid_align_vertical pos_v)
{
}

void rotate_col_up(const cube& cube_to_rotate, const grid_align_horizontal pos_h)
{
}

void rotate_col_down(const cube& cube_to_rotate, const grid_align_horizontal pos_h)
{
}

std::string visualize_cube(const cube& cube_to_visualize)
{
	std::string cube_visualization;

	return cube_visualization;
}

std::string visualize_grid(const cube_face& grid_to_visualize)
{
	std::string grid_visualization;

	for (int row = 0; row < 3; row++) {
		const int r_idx = row * 3;
		
		for (int col = 0; col < 3; col++) {
			grid_visualization += "|";
			grid_visualization += grid_to_char(grid_to_visualize[r_idx + col]);
		}

		grid_visualization += "\n";
	}

	return grid_visualization;
}
