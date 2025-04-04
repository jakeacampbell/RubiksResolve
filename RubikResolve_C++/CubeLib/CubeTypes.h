#pragma once

#include <iostream>

#define DEFAULT_CUBE_CONTENT { \
    { WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE }, \
    { YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW }, \
    { RED, RED, RED, RED, RED, RED, RED, RED, RED }, \
    { GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN }, \
    { ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE }, \
    { BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE } \
}

enum grid_t {
	WHITE,
	YELLOW,
	RED,
	GREEN,
	ORANGE,
	BLUE
};

enum class face_index : uint8_t {
	FRONT = 0,
	BACK = 1,
	LEFT = 2,
	RIGHT = 3,
	TOP = 4,
	BOTTOM = 5,
};

enum class grid_align_horizontal : uint8_t {
	LEFT = 0,
	CENTER = 1,
	RIGHT = 2,
};

enum class grid_align_vertical : uint8_t {
	TOP = 0,
	CENTER = 1,
	BOTTOM = 2,
};

typedef grid_t cube_face[9];
typedef cube_face cube[6];

constexpr cube default_cube_rep = DEFAULT_CUBE_CONTENT;