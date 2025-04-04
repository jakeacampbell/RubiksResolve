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

/**
 * @brief 
 * @param cube_to_visualize 
 * @return
 * @TODO: Not my best attempt at text visualisation maybe rework
 */
std::string visualize_cube(const cube& cube_to_visualize)
{
	std::string cube_visualization;

	{
		std::string top_viz = visualize_grid(cube_to_visualize[face_index::TOP]) + "\n"; // Top face above the front
		for (int i = 0; i < 3; ++i) {  // Each face is 3 lines
			cube_visualization += "    ";
			cube_visualization += top_viz.substr(i * 3, 3) + "\n";  // Each line of face has 6 chars
		}
	}

	{
		std::string left_viz = visualize_grid(cube_to_visualize[face_index::LEFT]);
		std::string front_viz = visualize_grid(cube_to_visualize[face_index::FRONT]);
		std::string right_viz = visualize_grid(cube_to_visualize[face_index::RIGHT]);
		std::string back_viz = visualize_grid(cube_to_visualize[face_index::BACK]);

		for (int i = 0; i < 3; ++i) {  // Each face is 3 lines
			cube_visualization += left_viz.substr(i * 3, 3) + " ";
			cube_visualization += front_viz.substr(i * 3, 3) + " ";
			cube_visualization += right_viz.substr(i * 3, 3) + " ";
			cube_visualization += back_viz.substr(i * 3, 3) + "\n";
		}
	}

	{
		std::string bottom_viz = visualize_grid(cube_to_visualize[face_index::BOTTOM]) + "\n"; // Top face above the front
		for (int i = 0; i < 3; ++i) {  // Each face is 3 lines
			cube_visualization += "    ";
			cube_visualization += bottom_viz.substr(i * 3, 3) + "\n";  // Each line of face has 6 chars
		}
	}

	return cube_visualization;
}

std::string visualize_grid(const cube_face& grid_to_visualize)
{
	std::string grid_visualization;

	for (int row = 0; row < 3; row++) {
		const int r_idx = row * 3;
		
		for (int col = 0; col < 3; col++) {
			grid_visualization += grid_to_char(grid_to_visualize[r_idx + col]);
		}
	}

	return grid_visualization;
}
