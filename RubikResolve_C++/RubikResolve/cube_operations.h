#pragma once

#include "cube_types.h"

#include <string>

#pragma region cube_transformations
/**
 * @brief Rotates a specified row to the right (clockwise) on the Rubik's Cube.
 * @param cube_to_rotate Reference to the Cube to be manipulated.
 * @param pos_v The row (vertical position) to rotate, typically top, middle, or bottom.
 */
void rotate_row_right(Cube& cube_to_rotate, const GridAlignVertical pos_v);

/**
 * @brief Rotates a specified row to the left (counter-clockwise) on the Rubik's Cube.
 * @param cube_to_rotate Reference to the Cube to be manipulated.
 * @param pos_v The row (vertical position) to rotate, typically top, middle, or bottom.
 */
void rotate_row_left(Cube& cube_to_rotate, const GridAlignVertical pos_v);

/**
 * @brief Rotates a specified column upwards on the Rubik's Cube.
 * @param cube_to_rotate Reference to the Cube to be manipulated.
 * @param pos_h The column (horizontal position) to rotate, typically left, center, or right.
 */
void rotate_col_up(Cube& cube_to_rotate, const GridAlignHorizontal pos_h);

/**
 * @brief Rotates a specified column downwards on the Rubik's Cube.
 * @param cube_to_rotate Reference to the Cube to be manipulated.
 * @param pos_h The column (horizontal position) to rotate, typically left, center, or right.
 */
void rotate_col_down(Cube& cube_to_rotate, const GridAlignHorizontal pos_h);

/**
 * @brief Rolls a specified column to the left across the cube faces.
 * @param cube_to_rotate Reference to the Cube to be manipulated.
 * @param pos_h The column (horizontal position) to roll, typically left, center, or right.
 */
void roll_col_left(Cube& cube_to_rotate, const GridAlignHorizontal pos_h);

/**
 * @brief Rolls a specified column to the right across the cube faces.
 * @param cube_to_rotate Reference to the Cube to be manipulated.
 * @param pos_h The column (horizontal position) to roll, typically left, center, or right.
 */
void roll_col_right(Cube& cube_to_rotate, const GridAlignHorizontal pos_h);
#pragma endregion

#pragma region cube_visualization
/**
 * @brief Converts a grid element (typically an enum) to a character for visualization.
 * @param grid The grid element to be converted.
 * @return A character representing the grid element.
 */
char grid_to_char(const TileColor& grid);

/**
 * @brief Generates a string visualization of the current state of the Rubik's Cube.
 * @param cube_to_visualize The cube to visualize.
 * @return A string representing the current state of the cube across all its faces.
 */
std::string visualize_cube(const Cube& cube_to_visualize);

std::string visualize_grid(const CubeFace& grid_to_visualize);
#pragma endregion