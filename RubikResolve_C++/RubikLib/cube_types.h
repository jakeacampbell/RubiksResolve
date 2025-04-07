#pragma once

#include <iostream>
#include <array>

#define DEFAULT_CUBE_CONTENT {\
    {\
        { WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE }, \
        { YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW }, \
        { RED, RED, RED, RED, RED, RED, RED, RED, RED }, \
        { GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN }, \
        { ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE }, \
        { BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE } \
    }\
}

/**
 * @brief Enumerates the colors available on the Rubik's Cube.
 */
enum TileColor {
    WHITE,   // Represents the white color on a cube face.
    YELLOW,  // Represents the yellow color on a cube face.
    RED,     // Represents the red color on a cube face.
    GREEN,   // Represents the green color on a cube face.
    ORANGE,  // Represents the orange color on a cube face.
    BLUE     // Represents the blue color on a cube face.
};

/**
 * @brief Enumerates the indices of each face on the Rubik's Cube.
 */
enum FaceIndex {
    FRONT = 0,  // The front face of the cube.
    BACK,       // The back face of the cube.
    LEFT,       // The left face of the cube.
    RIGHT,      // The right face of the cube.
    TOP,        // The top face of the cube.
    BOTTOM      // The bottom face of the cube.
};

/**
 * @brief Defines the horizontal alignment for column operations.
 */
enum class GridAlignHorizontal : uint8_t {
    LEFT = 0,   // The leftmost column of a face.
    CENTER,     // The center column of a face.
    RIGHT       // The rightmost column of a face.
};

/**
 * @brief Defines the vertical alignment for row operations.
 */
enum class GridAlignVertical : uint8_t {
    TOP = 0,    // The topmost row of a face.
    CENTER,     // The center row of a face.
    BOTTOM      // The bottom row of a face.
};

enum GridLayerDepth {
    FRONT,
    MIDDLE,
    BACK
};

/**
 * @brief Specifies the rotation direction for face or row operations on the cube.
 *
 * This enum can be used to indicate whether a particular face should be
 * rotated in a clockwise or counterclockwise direction.
 */
enum FaceRotationDirection {
    CLOCK,    // Rotate in a clockwise direction
    COUNTER_CLOCK,     // Rotate in a counter clockwise direction.
};

/**
 * @brief Represents a single face of the Rubik's Cube as a one-dimensional array of grid_t elements.
 */
typedef std::array<TileColor, 9> CubeFace;

/**
 * @brief Represents the entire Rubik's Cube as an array of six cube_face elements, one for each face.
 */
typedef std::array<CubeFace, 6> Cube;

/**
 * @brief A default, solved configuration of the Rubik's Cube where each face is uniformly colored.
 */
constexpr Cube solved_cube_rep = DEFAULT_CUBE_CONTENT;