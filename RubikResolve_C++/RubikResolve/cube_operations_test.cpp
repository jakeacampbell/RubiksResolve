#include "pch.h"

#include "gtest/gtest.h"
#include "cube_operations.h"

namespace TransformationTests
{
	TEST(Rotate_Right, TOP) {
		Cube test_cube = DEFAULT_CUBE_CONTENT;

		rotate_row_right(test_cube, GridAlignVertical::TOP);


	  EXPECT_EQ(1, 1);
	  //EXPECT_TRUE(false);
	}

	TEST(Rotate_Right, CENTER) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Right, BOTTOM) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Left, TOP) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Left, CENTER) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Left, BOTTOM) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Up, LEFT) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Up, CENTER) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Up, RIGHT) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Down, LEFT) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Down, CENTER) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
	}

	TEST(Rotate_Down, RIGHT) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(false);
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
