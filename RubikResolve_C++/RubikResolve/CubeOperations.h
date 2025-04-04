#pragma once

#include "CubeTypes.h"

#include <string>

char grid_to_char(const grid_t& grid);

void rotate_row_right(cube& cube_to_rotate, const grid_align_vertical pos_v);
void rotate_row_left(cube& cube_to_rotate, const grid_align_vertical pos_v);
void rotate_col_up(const cube& cube_to_rotate, const grid_align_horizontal pos_h);
void rotate_col_down(const cube& cube_to_rotate, const grid_align_horizontal pos_h);
void roll_col_left(const cube& cube_to_rotate, const grid_align_horizontal pos_h);
void roll_col_right(const cube& cube_to_rotate, const grid_align_horizontal pos_h);

std::string visualize_cube(const cube& cube_to_visualize);

std::string visualize_grid(const cube_face& grid_to_visualize);