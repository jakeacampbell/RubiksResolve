#include "pch.h"

#include "cube_operations.h"
#include <algorithm>

#pragma region cube_transformations
void rotate_face(CubeFace& face_to_rotate, const FaceRotationDirection direction)
{
	// Copy of the original face, so we don�t overwrite elements prematurely.
	CubeFace temp = face_to_rotate;

	// We treat the face as a 3�3 grid in row-major order: index = row*3 + col
	// row = index / 3, col = index % 3

	for (int index = 0; index < 9; ++index)
	{
		int row = index / 3;
		int col = index % 3;

		if (direction == FaceRotationDirection::CLOCK)
		{
			// Standard 2D clockwise rotation formula:
			//   new_row = col,  new_col = (2 - row)
			int new_row = col;
			int new_col = 2 - row;
			int new_index = new_row * 3 + new_col;

			face_to_rotate[new_index] = temp[index];
		}
		else // FaceRotationDirection::COUNTER_CLOCK
		{
			// Standard 2D counterclockwise rotation formula:
			//   new_row = (2 - col), new_col = row
			int new_row = 2 - col;
			int new_col = row;
			int new_index = new_row * 3 + new_col;

			face_to_rotate[new_index] = temp[index];
		}
	}
}

void rotate_row_right(Cube& cube_to_rotate, const GridAlignVertical pos_v)
{
	const int grid_offset = static_cast<int>(pos_v) * 3;
	TileColor tmp[3];

	// temporary storage for 1 row
	std::copy_n(&cube_to_rotate[FRONT][grid_offset], 3, tmp);

	// copy contents of one row to the adjacent face
	std::copy_n(&cube_to_rotate[LEFT][grid_offset], 3, &cube_to_rotate[FRONT][grid_offset]);
	//std::copy_n(&cube_to_rotate[BACK][grid_offset], 3, &cube_to_rotate[LEFT][grid_offset]);
	std::reverse_copy(cube_to_rotate[BACK].begin() + grid_offset, cube_to_rotate[BACK].begin() + grid_offset + 3, &cube_to_rotate[LEFT][grid_offset]);
	std::reverse_copy(cube_to_rotate[RIGHT].begin() + grid_offset, cube_to_rotate[RIGHT].begin() + grid_offset + 3, &cube_to_rotate[BACK][grid_offset]);
	//std::copy_n(&cube_to_rotate[RIGHT][grid_offset], 3, &cube_to_rotate[BACK][grid_offset]);
	std::copy_n(tmp, 3, &cube_to_rotate[RIGHT][grid_offset]);

	if (pos_v == GridAlignVertical::TOP || pos_v == GridAlignVertical::BOTTOM) { 
		const FaceIndex face_to_rotate = pos_v == GridAlignVertical::TOP ? FaceIndex::TOP : FaceIndex::BOTTOM;
		const FaceRotationDirection direction = face_to_rotate == FaceIndex::TOP ? FaceRotationDirection::COUNTER_CLOCK : FaceRotationDirection::CLOCK;

		rotate_face(cube_to_rotate[face_to_rotate], direction);
	}
}

void rotate_row_left(Cube& cube_to_rotate, const GridAlignVertical pos_v)
{
	const int grid_offset = static_cast<int>(pos_v) * 3;
	TileColor tmp[3];

	// temporary storage for 1 row
	std::copy_n(&cube_to_rotate[FRONT][grid_offset], 3, tmp);

	// copy contents of one row to the adjacent face
	std::copy_n(&cube_to_rotate[RIGHT][grid_offset],3, &cube_to_rotate[FRONT][grid_offset]);
	std::reverse_copy(cube_to_rotate[BACK].begin() + grid_offset, cube_to_rotate[BACK].begin() + grid_offset + 3, &cube_to_rotate[RIGHT][grid_offset]);
	std::reverse_copy(cube_to_rotate[LEFT].begin() + grid_offset, cube_to_rotate[LEFT].begin() + grid_offset + 3, &cube_to_rotate[BACK][grid_offset]);

	std::copy_n(tmp, 3, &cube_to_rotate[LEFT][grid_offset]);

	if (pos_v == GridAlignVertical::TOP || pos_v == GridAlignVertical::BOTTOM) {
		const FaceIndex face_to_rotate = pos_v == GridAlignVertical::TOP ? FaceIndex::TOP : FaceIndex::BOTTOM;
		const FaceRotationDirection direction = face_to_rotate == FaceIndex::TOP ? FaceRotationDirection::CLOCK : FaceRotationDirection::COUNTER_CLOCK;

		rotate_face(cube_to_rotate[face_to_rotate], direction);
	}
}

void roll_col_up(Cube& cube_to_rotate, const GridAlignHorizontal pos_h)
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

	if (pos_h == GridAlignHorizontal::LEFT || pos_h == GridAlignHorizontal::RIGHT) {
		const FaceIndex face_to_rotate = pos_h == GridAlignHorizontal::LEFT ? FaceIndex::LEFT : FaceIndex::RIGHT;
		const FaceRotationDirection direction = face_to_rotate == FaceIndex::LEFT ? FaceRotationDirection::COUNTER_CLOCK : FaceRotationDirection::CLOCK;

		rotate_face(cube_to_rotate[face_to_rotate], direction);
	}
}

void roll_col_down(Cube& cube_to_rotate, GridAlignHorizontal pos_h) {
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

	if (pos_h == GridAlignHorizontal::LEFT || pos_h == GridAlignHorizontal::RIGHT) {
		const FaceIndex face_to_rotate = pos_h == GridAlignHorizontal::LEFT ? FaceIndex::LEFT : FaceIndex::RIGHT;
		const FaceRotationDirection direction = face_to_rotate == FaceIndex::LEFT ? FaceRotationDirection::CLOCK : FaceRotationDirection::COUNTER_CLOCK;

		rotate_face(cube_to_rotate[face_to_rotate], direction);
	}
}

void roll_col_left(Cube& cube_to_rotate, const GridLayerDepth pos_d)
{
	if (pos_d == GridLayerDepth::FRONT) rotate_face(cube_to_rotate[FRONT], COUNTER_CLOCK);
	if (pos_d == GridLayerDepth::BACK) rotate_face(cube_to_rotate[BACK], COUNTER_CLOCK);

	// 1) Save TOP row [6,7,8]
	TileColor temp_top[3];
	temp_top[0] = cube_to_rotate[TOP][6];
	temp_top[1] = cube_to_rotate[TOP][7];
	temp_top[2] = cube_to_rotate[TOP][8];

	// 2) Move LEFT col [8,5,2] into temp_left
	TileColor temp_left[3];
	temp_left[0] = cube_to_rotate[LEFT][8];
	temp_left[1] = cube_to_rotate[LEFT][5];
	temp_left[2] = cube_to_rotate[LEFT][2];

	// 3) Move BOTTOM row [0,1,2] into temp_bottom
	TileColor temp_bottom[3];
	temp_bottom[0] = cube_to_rotate[BOTTOM][0];
	temp_bottom[1] = cube_to_rotate[BOTTOM][1];
	temp_bottom[2] = cube_to_rotate[BOTTOM][2];

	// 4) Move RIGHT col [6,3,0] into temp_right
	TileColor temp_right[3];
	temp_right[0] = cube_to_rotate[RIGHT][6];
	temp_right[1] = cube_to_rotate[RIGHT][3];
	temp_right[2] = cube_to_rotate[RIGHT][0];

	// SHIFT them in �left� direction:
	// (A) top -> left
	cube_to_rotate[LEFT][8] = temp_top[0];
	cube_to_rotate[LEFT][5] = temp_top[1];
	cube_to_rotate[LEFT][2] = temp_top[2];

	// (B) left -> bottom
	cube_to_rotate[BOTTOM][0] = temp_left[0];
	cube_to_rotate[BOTTOM][1] = temp_left[1];
	cube_to_rotate[BOTTOM][2] = temp_left[2];

	// (C) bottom -> right
	cube_to_rotate[RIGHT][6] = temp_bottom[0];
	cube_to_rotate[RIGHT][3] = temp_bottom[1];
	cube_to_rotate[RIGHT][0] = temp_bottom[2];

	// (D) right -> top
	cube_to_rotate[TOP][6] = temp_right[0];
	cube_to_rotate[TOP][7] = temp_right[1];
	cube_to_rotate[TOP][8] = temp_right[2];
}

void roll_col_right(Cube& cube_to_rotate, const GridLayerDepth pos_d)
{
	if (pos_d == GridLayerDepth::FRONT) rotate_face(cube_to_rotate[FRONT], CLOCK);
	if (pos_d == GridLayerDepth::BACK) rotate_face(cube_to_rotate[BACK], CLOCK);
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