#include "basic.h"

void building_info(Building *** building) {
	int i,j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5-i; j++) {
			(*building)[i][j].func = game2;
		}
	}
}