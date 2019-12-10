#include "basic.h"
#include "function.h"
#include <stdlib.h>
#include <time.h>

void building_info(Building*** building) {
	srand(time(NULL));

	int i; //¹æ ÀÎµ¦½º
	int j; //ÀÌº¥Æ®¹æ
	int k; //º¸»óÀÖ´Â ¹èÆ²¹æ È½¼ö

	//1Ãş

	for (i = 0; i < 5; i++) {
		(*building)[0][i].func = game1;
		if (i < 3) (*building)[0][i].reward = 1;
		else (*building)[0][i].reward = 0;
	}

	//2Ãş
	k = 0;
	j = rand() % 4;
	for (i = 0; i < 4; i++) {
		if (i == j) {
			(*building)[1][i].func = event;
			(*building)[1][i].reward = 1;
		}
		else {
			(*building)[1][i].func = game2;
			(*building)[1][i].reward = 0;
		}
	}

	//3Ãş
	k = 0;
	j = rand() % 3;
	for (i = 0; i < 3; i++) {
		if (i == j) {
			(*building)[2][i].func = event;
			(*building)[2][i].reward = 1;
		}
		else {
			(*building)[2][i].func = game3;
			(*building)[2][i].reward = 0;
		}
	}

	//4Ãş
	k = 0;
	for (i = 0; i < 2; i++) {
		(*building)[3][i].func = game4;
		(*building)[3][i].reward = 1;
	}
}
