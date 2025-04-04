#include "pch.h"
#include "CubeOperations.h"

const char* grid_to_str(const grid_t& grid)
{
	switch (grid) {
		case WHITE: return "WHITE";
		case YELLOW: return "YELLOW";
		case RED: return "RED";
		case GREEN: return "GREEN";
		case ORANGE: return "ORANGE";
		case BLUE: return "BLUE";
		default: return "UNKNOWN";
	}
}
