#include "cube_operations.h"

#pragma region cube_transformations
void rotate_row_right(Cube& cube_to_rotate, const GridAlignVertical pos_v)
{
	const int grid_offset = static_cast<int>(pos_v) * 3;
	TileColor tmp[3];

	// temporary storage for 1 row
	std::copy(&cube_to_rotate[FRONT][grid_offset], &cube_to_rotate[FRONT][grid_offset + 3], tmp);

	// copy contents of one row to the adjacent face
	std::copy(&cube_to_rotate[LEFT][grid_offset], &cube_to_rotate[LEFT][grid_offset + 3], &cube_to_rotate[FRONT][grid_offset]);
	std::copy(&cube_to_rotate[BACK][grid_offset], &cube_to_rotate[BACK][grid_offset + 3], &cube_to_rotate[LEFT][grid_offset]);
	std::copy(&cube_to_rotate[RIGHT][grid_offset], &cube_to_rotate[RIGHT][grid_offset + 3], &cube_to_rotate[BACK][grid_offset]);
	std::copy(tmp, tmp + 3, &cube_to_rotate[RIGHT][grid_offset]);
}

void rotate_row_left(Cube& cube_to_rotate, const GridAlignVertical pos_v)
{
	const int grid_offset = static_cast<int>(pos_v) * 3;
	TileColor tmp[3];

	// temporary storage for 1 row
	std::copy(&cube_to_rotate[FRONT][grid_offset], &cube_to_rotate[FRONT][grid_offset + 3], tmp);

	// copy contents of one row to the adjacent face
	std::copy(&cube_to_rotate[RIGHT][grid_offset], &cube_to_rotate[RIGHT][grid_offset + 3], &cube_to_rotate[FRONT][grid_offset]);
	std::copy(&cube_to_rotate[BACK][grid_offset], &cube_to_rotate[BACK][grid_offset + 3], &cube_to_rotate[RIGHT][grid_offset]);
	std::copy(&cube_to_rotate[RIGHT][grid_offset], &cube_to_rotate[RIGHT][grid_offset + 3], &cube_to_rotate[LEFT][grid_offset]);
	std::copy(tmp, tmp + 3, &cube_to_rotate[LEFT][grid_offset]);
}

// 0 1 2
// 3 4 5
// 6 7 8

// left:   0, 3, 6
// centre: 1, 4, 7
// right:  2, 5, 8

void rotate_col_up(Cube& cube_to_rotate, const GridAlignHorizontal pos_h)
{
	const int col_offset = static_cast<int>(pos_h);
	TileColor temp[3];

	// temporary storage for front column
	for (int i = 0; i < 3; ++i) {
		temp[i] = cube_to_rotate[FRONT][i * 3 + col_offset];
	}

	for (int i = 0; i < 3; ++i) {
		// Bottom to Front
		cube_to_rotate[FRONT][i * 3 + col_offset] = cube_to_rotate[BOTTOM][i * 3 + col_offset];

		// Back to Bottom
		cube_to_rotate[BOTTOM][i * 3 + col_offset] = cube_to_rotate[BACK][(2 - i) * 3 + (2 - col_offset)];

		// Top to Back
		cube_to_rotate[BACK][(2 - i) * 3 + (2 - col_offset)] = cube_to_rotate[TOP][i * 3 + col_offset];

		// Move elements from temp (original front) to top
		cube_to_rotate[TOP][i * 3 + col_offset] = temp[i];
	}
}

void rotate_col_down(Cube& cube_to_rotate, GridAlignHorizontal pos_h) {
	const int col_offset = static_cast<int>(pos_h);
	TileColor temp[3];

	// temporary storage for front column
	for (int i = 0; i < 3; ++i) {
		temp[i] = cube_to_rotate[FRONT][i * 3 + col_offset];
	}

	for (int i = 0; i < 3; ++i) {
		// Top to Front
		cube_to_rotate[FRONT][i * 3 + col_offset] = cube_to_rotate[TOP][i * 3 + col_offset];

		// Back to Top
		cube_to_rotate[TOP][i * 3 + col_offset] = cube_to_rotate[BACK][(2 - i) * 3 + (2 - col_offset)];

		// Bottom to Back
		cube_to_rotate[BACK][(2 - i) * 3 + (2 - col_offset)] = cube_to_rotate[BOTTOM][i * 3 + col_offset];

		// Move elements from temp (original front) to bottom (inverted)
		cube_to_rotate[BOTTOM][i * 3 + col_offset] = temp[i];
	}
}

void roll_col_left(Cube& cube_to_rotate, const GridAlignHorizontal pos_h)
{
}

void roll_col_right(Cube& cube_to_rotate, const GridAlignHorizontal pos_h)
{
}
#pragma endregion

#pragma region cube_visualization
char grid_to_char(const TileColor& grid)
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

std::string visualize_cube(const Cube& cube_to_visualize)
{
	std::string cube_visualization;

	{
		std::string top_viz = visualize_grid(cube_to_visualize[FaceIndex::TOP]) + "\n"; // Top face above the front
		for (int i = 0; i < 3; ++i) {  // Each face is 3 lines
			cube_visualization += "    ";
			cube_visualization += top_viz.substr(i * 3, 3) + "\n";  // Each line of face has 6 chars
		}
	}

	{
		std::string left_viz = visualize_grid(cube_to_visualize[FaceIndex::LEFT]);
		std::string front_viz = visualize_grid(cube_to_visualize[FaceIndex::FRONT]);
		std::string right_viz = visualize_grid(cube_to_visualize[FaceIndex::RIGHT]);
		std::string back_viz = visualize_grid(cube_to_visualize[FaceIndex::BACK]);

		for (int i = 0; i < 3; ++i) {  // Each face is 3 lines
			cube_visualization += left_viz.substr(i * 3, 3) + " ";
			cube_visualization += front_viz.substr(i * 3, 3) + " ";
			cube_visualization += right_viz.substr(i * 3, 3) + " ";
			cube_visualization += back_viz.substr(i * 3, 3) + "\n";
		}
	}

	{
		std::string bottom_viz = visualize_grid(cube_to_visualize[FaceIndex::BOTTOM]) + "\n"; // Top face above the front
		for (int i = 0; i < 3; ++i) {  // Each face is 3 lines
			cube_visualization += "    ";
			cube_visualization += bottom_viz.substr(i * 3, 3) + "\n";  // Each line of face has 6 chars
		}
	}

	return cube_visualization;
}

std::string visualize_grid(const CubeFace& grid_to_visualize)
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
#pragma endregion