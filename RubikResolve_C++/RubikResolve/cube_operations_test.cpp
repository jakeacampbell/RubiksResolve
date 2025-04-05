#include "pch.h"

#include "gtest/gtest.h"
#include "cube_operations.h"

namespace TransformationTests
{
	constexpr Cube scrambled_test_cube_default = {{
		// FRONT face
		{
			WHITE,  YELLOW, RED,
			GREEN,  ORANGE, BLUE,
			WHITE,  YELLOW, RED
		},
		// BACK face
		{
			RED,    RED,    BLUE,
			YELLOW, GREEN,  WHITE,
			ORANGE, BLUE,   GREEN
		},
		// LEFT face
		{
			YELLOW, WHITE,  GREEN,
			BLUE,   RED,    ORANGE,
			YELLOW, GREEN,  WHITE
		},
		// RIGHT face
		{
			BLUE,   ORANGE, RED,
			WHITE,  YELLOW, GREEN,
			BLUE,   ORANGE, RED
		},
		// TOP face
		{
			ORANGE, GREEN,  BLUE,
			RED,    WHITE,  YELLOW,
			ORANGE, GREEN,  BLUE
		},
		// BOTTOM face
		{
			GREEN,  RED,    WHITE,
			ORANGE, BLUE,   YELLOW,
			GREEN,  RED,    WHITE
		}
	}};

	TEST(Rotate_Face, CLOCKWISE) {
		// Arrange: Create a cube to test using the default scrambled state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_face(scrambled_test_cube[FRONT], FaceRotationDirection::CLOCK);

		// Assert: Check the edge rows and columns have rotated 90 degrees clockwise

		EXPECT_EQ(scrambled_test_cube[FRONT][0], scrambled_test_cube_default[FRONT][6]); // Top Left == old Bottom Left
		EXPECT_EQ(scrambled_test_cube[FRONT][1], scrambled_test_cube_default[FRONT][3]); // Top Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[FRONT][2], scrambled_test_cube_default[FRONT][0]); // Top right == old Top left

		EXPECT_EQ(scrambled_test_cube[FRONT][3], scrambled_test_cube_default[FRONT][7]); // Middle Left == old Bottom Middle
		EXPECT_EQ(scrambled_test_cube[FRONT][5], scrambled_test_cube_default[FRONT][1]); // Middle right == old Top Middle
		
		EXPECT_EQ(scrambled_test_cube[FRONT][6], scrambled_test_cube_default[FRONT][8]); // Bottom Left == old Bottom Right
		EXPECT_EQ(scrambled_test_cube[FRONT][7], scrambled_test_cube_default[FRONT][5]); // Bottom Middle == old Right Middle
		EXPECT_EQ(scrambled_test_cube[FRONT][8], scrambled_test_cube_default[FRONT][2]); // Bottom right == old Top Right
		
		EXPECT_EQ(scrambled_test_cube[FRONT][4], scrambled_test_cube_default[FRONT][4]); // Center does not change in inplace rotation
	}

	TEST(Rotate_Face, COUNTER_CLOCKWISE) {
		// Arrange: Create a cube to test using the default scrambled state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_face(scrambled_test_cube[FRONT], FaceRotationDirection::COUNTER_CLOCK);

		// Assert: Check the edge rows and columns have rotated 90 degrees clockwise

		EXPECT_EQ(scrambled_test_cube[FRONT][0], scrambled_test_cube_default[FRONT][2]); // Top Left == old Top Right
		EXPECT_EQ(scrambled_test_cube[FRONT][1], scrambled_test_cube_default[FRONT][5]); // Top Middle == old Right Middle 
		EXPECT_EQ(scrambled_test_cube[FRONT][2], scrambled_test_cube_default[FRONT][8]); // Top Right == old Bottom Right

		EXPECT_EQ(scrambled_test_cube[FRONT][3], scrambled_test_cube_default[FRONT][1]); // Middle Left == old Top Middle
		EXPECT_EQ(scrambled_test_cube[FRONT][5], scrambled_test_cube_default[FRONT][7]); // Middle Right == old Bottom Middle
		
		EXPECT_EQ(scrambled_test_cube[FRONT][6], scrambled_test_cube_default[FRONT][0]); // Bottom Left == old Top Left
		EXPECT_EQ(scrambled_test_cube[FRONT][7], scrambled_test_cube_default[FRONT][3]); // Bottom Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[FRONT][8], scrambled_test_cube_default[FRONT][6]); // Bottom Right == Bottom Top Left

		// Center stays same in an inplace rotation
		EXPECT_EQ(scrambled_test_cube[FRONT][4], scrambled_test_cube_default[FRONT][4]);
	}

	TEST(Rotate_Right, TOP) {
		// Arrange: Create a cube to test using the default solved state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_row_right(scrambled_test_cube, GridAlignVertical::TOP);

		// Assert: Check the top row of each face contains the left adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][0], scrambled_test_cube_default[LEFT][0]);
		EXPECT_EQ(scrambled_test_cube[FRONT][1], scrambled_test_cube_default[LEFT][1]);
		EXPECT_EQ(scrambled_test_cube[FRONT][2], scrambled_test_cube_default[LEFT][2]);

		EXPECT_EQ(scrambled_test_cube[LEFT][0], scrambled_test_cube_default[BACK][2]);
		EXPECT_EQ(scrambled_test_cube[LEFT][1], scrambled_test_cube_default[BACK][1]);
		EXPECT_EQ(scrambled_test_cube[LEFT][2], scrambled_test_cube_default[BACK][0]);

		EXPECT_EQ(scrambled_test_cube[BACK][0], scrambled_test_cube_default[RIGHT][2]);
		EXPECT_EQ(scrambled_test_cube[BACK][1], scrambled_test_cube_default[RIGHT][1]);
		EXPECT_EQ(scrambled_test_cube[BACK][2], scrambled_test_cube_default[RIGHT][0]);

		EXPECT_EQ(scrambled_test_cube[RIGHT][0], scrambled_test_cube_default[FRONT][0]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][1], scrambled_test_cube_default[FRONT][1]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][2], scrambled_test_cube_default[FRONT][2]);

		// Verify top face has been rotated
		EXPECT_EQ(scrambled_test_cube[TOP][0], scrambled_test_cube_default[TOP][2]); // Top Left == old Top Right
		EXPECT_EQ(scrambled_test_cube[TOP][1], scrambled_test_cube_default[TOP][5]); // Top Middle == old Right Middle 
		EXPECT_EQ(scrambled_test_cube[TOP][2], scrambled_test_cube_default[TOP][8]); // Top Right == old Bottom Right

		EXPECT_EQ(scrambled_test_cube[TOP][3], scrambled_test_cube_default[TOP][1]); // Middle Left == old Top Middle
		EXPECT_EQ(scrambled_test_cube[TOP][5], scrambled_test_cube_default[TOP][7]); // Middle Right == old Bottom Middle

		EXPECT_EQ(scrambled_test_cube[TOP][6], scrambled_test_cube_default[TOP][0]); // Bottom Left == old Top Left
		EXPECT_EQ(scrambled_test_cube[TOP][7], scrambled_test_cube_default[TOP][3]); // Bottom Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[TOP][8], scrambled_test_cube_default[TOP][6]); // Bottom Right == Bottom Top Left

		EXPECT_EQ(scrambled_test_cube[TOP][4], scrambled_test_cube_default[TOP][4]); // Center stays same in an inplace rotation

		EXPECT_EQ(scrambled_test_cube[BOTTOM], scrambled_test_cube_default[BOTTOM]);
	}

	TEST(Rotate_Right, CENTER) {
		// Arrange: Create a cube to test using the default solved state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_row_right(scrambled_test_cube, GridAlignVertical::CENTER);

		// Assert: Check the top row of each face contains the left adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][3], scrambled_test_cube_default[LEFT][3]);
		EXPECT_EQ(scrambled_test_cube[FRONT][4], scrambled_test_cube_default[LEFT][4]);
		EXPECT_EQ(scrambled_test_cube[FRONT][5], scrambled_test_cube_default[LEFT][5]);

		EXPECT_EQ(scrambled_test_cube[LEFT][3], scrambled_test_cube_default[BACK][5]);
		EXPECT_EQ(scrambled_test_cube[LEFT][4], scrambled_test_cube_default[BACK][4]);
		EXPECT_EQ(scrambled_test_cube[LEFT][5], scrambled_test_cube_default[BACK][3]);

		EXPECT_EQ(scrambled_test_cube[BACK][3], scrambled_test_cube_default[RIGHT][5]);
		EXPECT_EQ(scrambled_test_cube[BACK][4], scrambled_test_cube_default[RIGHT][4]);
		EXPECT_EQ(scrambled_test_cube[BACK][5], scrambled_test_cube_default[RIGHT][3]);

		EXPECT_EQ(scrambled_test_cube[RIGHT][3], scrambled_test_cube_default[FRONT][3]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][4], scrambled_test_cube_default[FRONT][4]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][5], scrambled_test_cube_default[FRONT][5]);

		// Verify top face and bottom face are unaffected
		EXPECT_EQ(scrambled_test_cube[TOP], scrambled_test_cube_default[TOP]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM], scrambled_test_cube_default[BOTTOM]);
	}

	TEST(Rotate_Right, BOTTOM) {
		// Arrange: Create a cube to test using the default solved state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_row_right(scrambled_test_cube, GridAlignVertical::BOTTOM);

		// Assert: Check the top row of each face contains the left adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][6], scrambled_test_cube_default[LEFT][6]);
		EXPECT_EQ(scrambled_test_cube[FRONT][7], scrambled_test_cube_default[LEFT][7]);
		EXPECT_EQ(scrambled_test_cube[FRONT][8], scrambled_test_cube_default[LEFT][8]);

		EXPECT_EQ(scrambled_test_cube[LEFT][6], scrambled_test_cube_default[BACK][8]);
		EXPECT_EQ(scrambled_test_cube[LEFT][7], scrambled_test_cube_default[BACK][7]);
		EXPECT_EQ(scrambled_test_cube[LEFT][8], scrambled_test_cube_default[BACK][6]);

		EXPECT_EQ(scrambled_test_cube[BACK][6], scrambled_test_cube_default[RIGHT][8]);
		EXPECT_EQ(scrambled_test_cube[BACK][7], scrambled_test_cube_default[RIGHT][7]);
		EXPECT_EQ(scrambled_test_cube[BACK][8], scrambled_test_cube_default[RIGHT][6]);

		EXPECT_EQ(scrambled_test_cube[RIGHT][6], scrambled_test_cube_default[FRONT][6]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][7], scrambled_test_cube_default[FRONT][7]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][8], scrambled_test_cube_default[FRONT][8]);

		// Verify bottom face has been rotated
		EXPECT_EQ(scrambled_test_cube[BOTTOM][0], scrambled_test_cube_default[BOTTOM][6]); // Top Left == old Bottom Left
		EXPECT_EQ(scrambled_test_cube[BOTTOM][1], scrambled_test_cube_default[BOTTOM][3]); // Top Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[BOTTOM][2], scrambled_test_cube_default[BOTTOM][0]); // Top right == old Top left

		EXPECT_EQ(scrambled_test_cube[BOTTOM][3], scrambled_test_cube_default[BOTTOM][7]); // Middle Left == old Bottom Middle
		EXPECT_EQ(scrambled_test_cube[BOTTOM][5], scrambled_test_cube_default[BOTTOM][1]); // Middle right == old Top Middle

		EXPECT_EQ(scrambled_test_cube[BOTTOM][6], scrambled_test_cube_default[BOTTOM][8]); // Bottom Left == old Bottom Right
		EXPECT_EQ(scrambled_test_cube[BOTTOM][7], scrambled_test_cube_default[BOTTOM][5]); // Bottom Middle == old Right Middle
		EXPECT_EQ(scrambled_test_cube[BOTTOM][8], scrambled_test_cube_default[BOTTOM][2]); // Bottom right == old Top Right

		EXPECT_EQ(scrambled_test_cube[BOTTOM][4], scrambled_test_cube_default[BOTTOM][4]); // Center does not change in inplace rotation

		EXPECT_EQ(scrambled_test_cube[TOP], scrambled_test_cube_default[TOP]);
	}

	TEST(Rotate_Left, TOP) {
		// Arrange: Create a cube to test using the default solved state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_row_left(scrambled_test_cube, GridAlignVertical::TOP);

		// Assert: Check the top row of each face contains the left adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][0], scrambled_test_cube_default[RIGHT][0]);
		EXPECT_EQ(scrambled_test_cube[FRONT][1], scrambled_test_cube_default[RIGHT][1]);
		EXPECT_EQ(scrambled_test_cube[FRONT][2], scrambled_test_cube_default[RIGHT][2]);

		EXPECT_EQ(scrambled_test_cube[RIGHT][0], scrambled_test_cube_default[BACK][2]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][1], scrambled_test_cube_default[BACK][1]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][2], scrambled_test_cube_default[BACK][0]);

		EXPECT_EQ(scrambled_test_cube[BACK][0], scrambled_test_cube_default[LEFT][2]);
		EXPECT_EQ(scrambled_test_cube[BACK][1], scrambled_test_cube_default[LEFT][1]);
		EXPECT_EQ(scrambled_test_cube[BACK][2], scrambled_test_cube_default[LEFT][0]);

		EXPECT_EQ(scrambled_test_cube[LEFT][0], scrambled_test_cube_default[FRONT][0]);
		EXPECT_EQ(scrambled_test_cube[LEFT][1], scrambled_test_cube_default[FRONT][1]);
		EXPECT_EQ(scrambled_test_cube[LEFT][2], scrambled_test_cube_default[FRONT][2]);

		// Verify TOP face has been rotated
		EXPECT_EQ(scrambled_test_cube[TOP][0], scrambled_test_cube_default[TOP][6]); // Top Left == old Bottom Left
		EXPECT_EQ(scrambled_test_cube[TOP][1], scrambled_test_cube_default[TOP][3]); // Top Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[TOP][2], scrambled_test_cube_default[TOP][0]); // Top right == old Top left

		EXPECT_EQ(scrambled_test_cube[TOP][3], scrambled_test_cube_default[TOP][7]); // Middle Left == old Bottom Middle
		EXPECT_EQ(scrambled_test_cube[TOP][5], scrambled_test_cube_default[TOP][1]); // Middle right == old Top Middle

		EXPECT_EQ(scrambled_test_cube[TOP][6], scrambled_test_cube_default[TOP][8]); // Bottom Left == old Bottom Right
		EXPECT_EQ(scrambled_test_cube[TOP][7], scrambled_test_cube_default[TOP][5]); // Bottom Middle == old Right Middle
		EXPECT_EQ(scrambled_test_cube[TOP][8], scrambled_test_cube_default[TOP][2]); // Bottom right == old Top Right

		EXPECT_EQ(scrambled_test_cube[TOP][4], scrambled_test_cube_default[TOP][4]); // Center does not change in inplace rotation

		EXPECT_EQ(scrambled_test_cube[BOTTOM], scrambled_test_cube_default[BOTTOM]);
	}

	TEST(Rotate_Left, CENTER) {
		// Arrange: Create a cube to test using the default solved state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_row_left(scrambled_test_cube, GridAlignVertical::CENTER);

		// Assert: Check the top row of each face contains the left adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][3], scrambled_test_cube_default[RIGHT][3]);
		EXPECT_EQ(scrambled_test_cube[FRONT][4], scrambled_test_cube_default[RIGHT][4]);
		EXPECT_EQ(scrambled_test_cube[FRONT][5], scrambled_test_cube_default[RIGHT][5]);

		EXPECT_EQ(scrambled_test_cube[RIGHT][3], scrambled_test_cube_default[BACK][5]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][4], scrambled_test_cube_default[BACK][4]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][5], scrambled_test_cube_default[BACK][3]);

		EXPECT_EQ(scrambled_test_cube[BACK][3], scrambled_test_cube_default[LEFT][5]);
		EXPECT_EQ(scrambled_test_cube[BACK][4], scrambled_test_cube_default[LEFT][4]);
		EXPECT_EQ(scrambled_test_cube[BACK][5], scrambled_test_cube_default[LEFT][3]);

		EXPECT_EQ(scrambled_test_cube[LEFT][3], scrambled_test_cube_default[FRONT][3]);
		EXPECT_EQ(scrambled_test_cube[LEFT][4], scrambled_test_cube_default[FRONT][4]);
		EXPECT_EQ(scrambled_test_cube[LEFT][5], scrambled_test_cube_default[FRONT][5]);

		// TOP and BOTTOM should be unaffected
		EXPECT_EQ(scrambled_test_cube[TOP], scrambled_test_cube_default[TOP]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM], scrambled_test_cube_default[BOTTOM]);
	}

	TEST(Rotate_Left, BOTTOM) {
		// Arrange: Create a cube to test using the default solved state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_row_left(scrambled_test_cube, GridAlignVertical::BOTTOM);

		// Assert: Check the top row of each face contains the left adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][6], scrambled_test_cube_default[RIGHT][6]);
		EXPECT_EQ(scrambled_test_cube[FRONT][7], scrambled_test_cube_default[RIGHT][7]);
		EXPECT_EQ(scrambled_test_cube[FRONT][8], scrambled_test_cube_default[RIGHT][8]);

		EXPECT_EQ(scrambled_test_cube[RIGHT][6], scrambled_test_cube_default[BACK][8]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][7], scrambled_test_cube_default[BACK][7]);
		EXPECT_EQ(scrambled_test_cube[RIGHT][8], scrambled_test_cube_default[BACK][6]);

		EXPECT_EQ(scrambled_test_cube[BACK][6], scrambled_test_cube_default[LEFT][8]);
		EXPECT_EQ(scrambled_test_cube[BACK][7], scrambled_test_cube_default[LEFT][7]);
		EXPECT_EQ(scrambled_test_cube[BACK][8], scrambled_test_cube_default[LEFT][6]);

		EXPECT_EQ(scrambled_test_cube[LEFT][6], scrambled_test_cube_default[FRONT][6]);
		EXPECT_EQ(scrambled_test_cube[LEFT][7], scrambled_test_cube_default[FRONT][7]);
		EXPECT_EQ(scrambled_test_cube[LEFT][8], scrambled_test_cube_default[FRONT][8]);

		// TOP should be unaffected
		EXPECT_EQ(scrambled_test_cube[TOP], scrambled_test_cube_default[TOP]);

		// Verify BOTTOM face has been rotated
		EXPECT_EQ(scrambled_test_cube[BOTTOM][0], scrambled_test_cube_default[BOTTOM][2]); // Top Left == old Top Right
		EXPECT_EQ(scrambled_test_cube[BOTTOM][1], scrambled_test_cube_default[BOTTOM][5]); // Top Middle == old Right Middle 
		EXPECT_EQ(scrambled_test_cube[BOTTOM][2], scrambled_test_cube_default[BOTTOM][8]); // Top Right == old Bottom Right

		EXPECT_EQ(scrambled_test_cube[BOTTOM][3], scrambled_test_cube_default[BOTTOM][1]); // Middle Left == old Top Middle
		EXPECT_EQ(scrambled_test_cube[BOTTOM][5], scrambled_test_cube_default[BOTTOM][7]); // Middle Right == old Bottom Middle

		EXPECT_EQ(scrambled_test_cube[BOTTOM][6], scrambled_test_cube_default[BOTTOM][0]); // Bottom Left == old Top Left
		EXPECT_EQ(scrambled_test_cube[BOTTOM][7], scrambled_test_cube_default[BOTTOM][3]); // Bottom Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[BOTTOM][8], scrambled_test_cube_default[BOTTOM][6]); // Bottom Right == Bottom Top Left

		EXPECT_EQ(scrambled_test_cube[BOTTOM][4], scrambled_test_cube_default[BOTTOM][4]); // Center stays same in an inplace rotation
	}

	TEST(Rotate_Up, LEFT) {
		// Arrange: Create a cube to test using the default scrambled state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_col_up(scrambled_test_cube, GridAlignHorizontal::LEFT);

		// Assert: Check the left column of each face contains the bottom adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][0], scrambled_test_cube_default[BOTTOM][0]);
		EXPECT_EQ(scrambled_test_cube[FRONT][3], scrambled_test_cube_default[BOTTOM][3]);
		EXPECT_EQ(scrambled_test_cube[FRONT][6], scrambled_test_cube_default[BOTTOM][6]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[BOTTOM][0], scrambled_test_cube_default[BACK][8]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][3], scrambled_test_cube_default[BACK][5]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][6], scrambled_test_cube_default[BACK][2]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[BACK][8], scrambled_test_cube_default[TOP][0]);
		EXPECT_EQ(scrambled_test_cube[BACK][5], scrambled_test_cube_default[TOP][3]);
		EXPECT_EQ(scrambled_test_cube[BACK][2], scrambled_test_cube_default[TOP][6]);

		EXPECT_EQ(scrambled_test_cube[TOP][0], scrambled_test_cube_default[FRONT][0]);
		EXPECT_EQ(scrambled_test_cube[TOP][3], scrambled_test_cube_default[FRONT][3]);
		EXPECT_EQ(scrambled_test_cube[TOP][6], scrambled_test_cube_default[FRONT][6]);

		// TOP should be unaffected
		EXPECT_EQ(scrambled_test_cube[RIGHT], scrambled_test_cube_default[RIGHT]);

		// Verify BOTTOM face has been rotated
		EXPECT_EQ(scrambled_test_cube[LEFT][0], scrambled_test_cube_default[LEFT][2]); // Top Left == old Top Right
		EXPECT_EQ(scrambled_test_cube[LEFT][1], scrambled_test_cube_default[LEFT][5]); // Top Middle == old Right Middle 
		EXPECT_EQ(scrambled_test_cube[LEFT][2], scrambled_test_cube_default[LEFT][8]); // Top Right == old Bottom Right

		EXPECT_EQ(scrambled_test_cube[LEFT][3], scrambled_test_cube_default[LEFT][1]); // Middle Left == old Top Middle
		EXPECT_EQ(scrambled_test_cube[LEFT][5], scrambled_test_cube_default[LEFT][7]); // Middle Right == old Bottom Middle

		EXPECT_EQ(scrambled_test_cube[LEFT][6], scrambled_test_cube_default[LEFT][0]); // Bottom Left == old Top Left
		EXPECT_EQ(scrambled_test_cube[LEFT][7], scrambled_test_cube_default[LEFT][3]); // Bottom Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[LEFT][8], scrambled_test_cube_default[LEFT][6]); // Bottom Right == Bottom Top Left

		EXPECT_EQ(scrambled_test_cube[LEFT][4], scrambled_test_cube_default[LEFT][4]); // Center stays same in an inplace rotation
	}

	TEST(Rotate_Up, CENTER) {
		// Arrange: Create a cube to test using the default scrambled state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_col_up(scrambled_test_cube, GridAlignHorizontal::CENTER);

		// Assert: Check the left column of each face contains the bottom adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][1], scrambled_test_cube_default[BOTTOM][1]);
		EXPECT_EQ(scrambled_test_cube[FRONT][4], scrambled_test_cube_default[BOTTOM][4]);
		EXPECT_EQ(scrambled_test_cube[FRONT][7], scrambled_test_cube_default[BOTTOM][7]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[BOTTOM][1], scrambled_test_cube_default[BACK][8-1]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][4], scrambled_test_cube_default[BACK][8-4]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][7], scrambled_test_cube_default[BACK][8-7]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[BACK][8-1], scrambled_test_cube_default[TOP][1]);
		EXPECT_EQ(scrambled_test_cube[BACK][8-4], scrambled_test_cube_default[TOP][4]);
		EXPECT_EQ(scrambled_test_cube[BACK][8-7], scrambled_test_cube_default[TOP][7]);

		EXPECT_EQ(scrambled_test_cube[TOP][1], scrambled_test_cube_default[FRONT][1]);
		EXPECT_EQ(scrambled_test_cube[TOP][4], scrambled_test_cube_default[FRONT][4]);
		EXPECT_EQ(scrambled_test_cube[TOP][7], scrambled_test_cube_default[FRONT][7]);

		// TOP should be unaffected
		EXPECT_EQ(scrambled_test_cube[RIGHT], scrambled_test_cube_default[RIGHT]);
		EXPECT_EQ(scrambled_test_cube[LEFT], scrambled_test_cube_default[LEFT]);
	}

	TEST(Rotate_Up, RIGHT) {
		// Arrange: Create a cube to test using the default scrambled state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_col_up(scrambled_test_cube, GridAlignHorizontal::RIGHT);

		// Assert: Check the left column of each face contains the bottom adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][2], scrambled_test_cube_default[BOTTOM][2]);
		EXPECT_EQ(scrambled_test_cube[FRONT][5], scrambled_test_cube_default[BOTTOM][5]);
		EXPECT_EQ(scrambled_test_cube[FRONT][8], scrambled_test_cube_default[BOTTOM][8]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[BOTTOM][2], scrambled_test_cube_default[BACK][6]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][5], scrambled_test_cube_default[BACK][3]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][8], scrambled_test_cube_default[BACK][0]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[BACK][6], scrambled_test_cube_default[TOP][2]);
		EXPECT_EQ(scrambled_test_cube[BACK][3], scrambled_test_cube_default[TOP][5]);
		EXPECT_EQ(scrambled_test_cube[BACK][0], scrambled_test_cube_default[TOP][8]);

		EXPECT_EQ(scrambled_test_cube[TOP][2], scrambled_test_cube_default[FRONT][2]);
		EXPECT_EQ(scrambled_test_cube[TOP][5], scrambled_test_cube_default[FRONT][5]);
		EXPECT_EQ(scrambled_test_cube[TOP][8], scrambled_test_cube_default[FRONT][8]);

		// TOP should be unaffected
		EXPECT_EQ(scrambled_test_cube[LEFT], scrambled_test_cube_default[LEFT]);

		EXPECT_EQ(scrambled_test_cube[RIGHT][0], scrambled_test_cube_default[RIGHT][6]); // Top Left == old Bottom Left
		EXPECT_EQ(scrambled_test_cube[RIGHT][1], scrambled_test_cube_default[RIGHT][3]); // Top Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[RIGHT][2], scrambled_test_cube_default[RIGHT][0]); // Top right == old Top left

		EXPECT_EQ(scrambled_test_cube[RIGHT][3], scrambled_test_cube_default[RIGHT][7]); // Middle Left == old Bottom Middle
		EXPECT_EQ(scrambled_test_cube[RIGHT][5], scrambled_test_cube_default[RIGHT][1]); // Middle right == old Top Middle

		EXPECT_EQ(scrambled_test_cube[RIGHT][6], scrambled_test_cube_default[RIGHT][8]); // Bottom Left == old Bottom Right
		EXPECT_EQ(scrambled_test_cube[RIGHT][7], scrambled_test_cube_default[RIGHT][5]); // Bottom Middle == old Right Middle
		EXPECT_EQ(scrambled_test_cube[RIGHT][8], scrambled_test_cube_default[RIGHT][2]); // Bottom right == old Top Right

		EXPECT_EQ(scrambled_test_cube[RIGHT][4], scrambled_test_cube_default[RIGHT][4]); // Center does not change in inplace rotation
	}

	TEST(Rotate_Down, LEFT) {
		// Arrange: Create a cube to test using the default scrambled state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_col_down(scrambled_test_cube, GridAlignHorizontal::LEFT);

		// Assert: Check the left column of each face contains the bottom adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][0], scrambled_test_cube_default[TOP][0]);
		EXPECT_EQ(scrambled_test_cube[FRONT][3], scrambled_test_cube_default[TOP][3]);
		EXPECT_EQ(scrambled_test_cube[FRONT][6], scrambled_test_cube_default[TOP][6]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[TOP][0], scrambled_test_cube_default[BACK][8]);
		EXPECT_EQ(scrambled_test_cube[TOP][3], scrambled_test_cube_default[BACK][5]);
		EXPECT_EQ(scrambled_test_cube[TOP][6], scrambled_test_cube_default[BACK][2]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[BACK][8], scrambled_test_cube_default[BOTTOM][0]);
		EXPECT_EQ(scrambled_test_cube[BACK][5], scrambled_test_cube_default[BOTTOM][3]);
		EXPECT_EQ(scrambled_test_cube[BACK][2], scrambled_test_cube_default[BOTTOM][6]);

		EXPECT_EQ(scrambled_test_cube[BOTTOM][0], scrambled_test_cube_default[FRONT][0]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][3], scrambled_test_cube_default[FRONT][3]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][6], scrambled_test_cube_default[FRONT][6]);

		EXPECT_EQ(scrambled_test_cube[RIGHT], scrambled_test_cube_default[RIGHT]);

		EXPECT_EQ(scrambled_test_cube[LEFT][0], scrambled_test_cube_default[LEFT][6]); // Top Left == old Bottom Left
		EXPECT_EQ(scrambled_test_cube[LEFT][1], scrambled_test_cube_default[LEFT][3]); // Top Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[LEFT][2], scrambled_test_cube_default[LEFT][0]); // Top right == old Top left

		EXPECT_EQ(scrambled_test_cube[LEFT][3], scrambled_test_cube_default[LEFT][7]); // Middle Left == old Bottom Middle
		EXPECT_EQ(scrambled_test_cube[LEFT][5], scrambled_test_cube_default[LEFT][1]); // Middle right == old Top Middle

		EXPECT_EQ(scrambled_test_cube[LEFT][6], scrambled_test_cube_default[LEFT][8]); // Bottom Left == old Bottom Right
		EXPECT_EQ(scrambled_test_cube[LEFT][7], scrambled_test_cube_default[LEFT][5]); // Bottom Middle == old Right Middle
		EXPECT_EQ(scrambled_test_cube[LEFT][8], scrambled_test_cube_default[LEFT][2]); // Bottom right == old Top Right

		EXPECT_EQ(scrambled_test_cube[LEFT][4], scrambled_test_cube_default[LEFT][4]); // Center does not change in inplace rotation
	}

	TEST(Rotate_Down, CENTER) {
		// Arrange: Create a cube to test using the default scrambled state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the LEFT col to the DOWN
		rotate_col_down(scrambled_test_cube, GridAlignHorizontal::CENTER);

		// Assert: Check the left column of each face contains the bottom adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][1], scrambled_test_cube_default[TOP][1]);
		EXPECT_EQ(scrambled_test_cube[FRONT][4], scrambled_test_cube_default[TOP][4]);
		EXPECT_EQ(scrambled_test_cube[FRONT][7], scrambled_test_cube_default[TOP][7]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[TOP][1], scrambled_test_cube_default[BACK][8 - 1]);
		EXPECT_EQ(scrambled_test_cube[TOP][4], scrambled_test_cube_default[BACK][8 - 4]);
		EXPECT_EQ(scrambled_test_cube[TOP][7], scrambled_test_cube_default[BACK][8 - 7]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[BACK][8 - 1], scrambled_test_cube_default[BOTTOM][1]);
		EXPECT_EQ(scrambled_test_cube[BACK][8 - 4], scrambled_test_cube_default[BOTTOM][4]);
		EXPECT_EQ(scrambled_test_cube[BACK][8 - 7], scrambled_test_cube_default[BOTTOM][7]);

		EXPECT_EQ(scrambled_test_cube[BOTTOM][1], scrambled_test_cube_default[FRONT][1]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][4], scrambled_test_cube_default[FRONT][4]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][7], scrambled_test_cube_default[FRONT][7]);

		// TOP should be unaffected
		EXPECT_EQ(scrambled_test_cube[RIGHT], scrambled_test_cube_default[RIGHT]);
		EXPECT_EQ(scrambled_test_cube[LEFT], scrambled_test_cube_default[LEFT]);
	}

	TEST(Rotate_Down, RIGHT) {
		// Arrange: Create a cube to test using the default scrambled state
		Cube scrambled_test_cube = scrambled_test_cube_default;

		// Act: Rotate the top row to the right
		rotate_col_down(scrambled_test_cube, GridAlignHorizontal::RIGHT);

		// Assert: Check the left column of each face contains the bottom adjacent faces old content
		EXPECT_EQ(scrambled_test_cube[FRONT][2], scrambled_test_cube_default[TOP][2]);
		EXPECT_EQ(scrambled_test_cube[FRONT][5], scrambled_test_cube_default[TOP][5]);
		EXPECT_EQ(scrambled_test_cube[FRONT][8], scrambled_test_cube_default[TOP][8]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[TOP][2], scrambled_test_cube_default[BACK][6]);
		EXPECT_EQ(scrambled_test_cube[TOP][5], scrambled_test_cube_default[BACK][3]);
		EXPECT_EQ(scrambled_test_cube[TOP][8], scrambled_test_cube_default[BACK][0]);

		// inversion happens here
		EXPECT_EQ(scrambled_test_cube[BACK][6], scrambled_test_cube_default[BOTTOM][2]);
		EXPECT_EQ(scrambled_test_cube[BACK][3], scrambled_test_cube_default[BOTTOM][5]);
		EXPECT_EQ(scrambled_test_cube[BACK][0], scrambled_test_cube_default[BOTTOM][8]);

		EXPECT_EQ(scrambled_test_cube[BOTTOM][2], scrambled_test_cube_default[FRONT][2]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][5], scrambled_test_cube_default[FRONT][5]);
		EXPECT_EQ(scrambled_test_cube[BOTTOM][8], scrambled_test_cube_default[FRONT][8]);

		// TOP should be unaffected
		EXPECT_EQ(scrambled_test_cube[LEFT], scrambled_test_cube_default[LEFT]);

		// Verify BOTTOM face has been rotated
		EXPECT_EQ(scrambled_test_cube[RIGHT][0], scrambled_test_cube_default[RIGHT][2]); // Top Left == old Top Right
		EXPECT_EQ(scrambled_test_cube[RIGHT][1], scrambled_test_cube_default[RIGHT][5]); // Top Middle == old Right Middle 
		EXPECT_EQ(scrambled_test_cube[RIGHT][2], scrambled_test_cube_default[RIGHT][8]); // Top Right == old Bottom Right

		EXPECT_EQ(scrambled_test_cube[RIGHT][3], scrambled_test_cube_default[RIGHT][1]); // Middle Left == old Top Middle
		EXPECT_EQ(scrambled_test_cube[RIGHT][5], scrambled_test_cube_default[RIGHT][7]); // Middle Right == old Bottom Middle

		EXPECT_EQ(scrambled_test_cube[RIGHT][6], scrambled_test_cube_default[RIGHT][0]); // Bottom Left == old Top Left
		EXPECT_EQ(scrambled_test_cube[RIGHT][7], scrambled_test_cube_default[RIGHT][3]); // Bottom Middle == old Left Middle
		EXPECT_EQ(scrambled_test_cube[RIGHT][8], scrambled_test_cube_default[RIGHT][6]); // Bottom Right == Bottom Top Left

		EXPECT_EQ(scrambled_test_cube[RIGHT][4], scrambled_test_cube_default[RIGHT][4]); // Center stays same in an inplace rotation
	}

	TEST(Roll_Left, LEFT) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Roll_Left, CENTER) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Roll_Left, RIGHT) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Roll_Right, LEFT) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Roll_Right, CENTER) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Roll_Right, RIGHT) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}
}
