#include "basic.h"
#include "function.h"

void building_info(Building*** building) {
	srand(time(NULL));
	int i;
	int j;
	int k;

	//1類
	while (1) {
		j = rand() % 5;
		k = rand() % 5;
		if (j != k) {
			building[0][j]->reward = NULL;
			building[0][k]->reward = NULL;
			break;
		}
		for (i = 0; i < 5; i++) {
			building[0][i]->func = game1;
			if (building[0][i]->reward != NULL) {
				building[0][i]->reward = 1;
			}
		}

		//2類
		while (1) {
			j = rand() % 4;
			k = rand() % 4;
			if (j != k) {
				building[1][j]->reward = NULL;
				building[1][j]->func = event;
				building[1][k]->reward = NULL;
				break;
			}
		}
		for (i = 0; i < 4; i++) {
			if (i != j) building[1][i]->func = game2;

			if (building[1][i]->reward != NULL) {
				building[1][i]->reward = 1;
			}
		}

		//3類
		while (1) {
			j = rand() % 3;
			k = rand() % 3;
			if (j != k) {
				building[2][j]->reward = NULL;
				building[2][j]->func = event;
				building[2][k]->reward = NULL;
				break;
			}
		}
		for (i = 0; i < 3; i++) {
			if (i != j) building[2][i]->func = game3;

			if (building[2][i]->reward != NULL) {
				building[2][i]->reward = 1;
			}
		}

		//4類
		j = rand() % 2;
		building[3][j]->reward = NULL;
		for (i = 0; i < 2; i++) {
			building[3][i]->func = game4;
			if (building[3][i]->reward != NULL) {
				building[3][i]->reward = 1;
			}
		}
	}
}