#include "basic.h"
#include<malloc.h>
Building ** make_building() {
	
	Building ** building;
	building = (Building * *)malloc(sizeof(Building*) * 5);
	if (building != NULL) {

		building[4] = (Building*)malloc(sizeof(Building) * 1);
		building[3] = (Building*)malloc(sizeof(Building) * 2);
		building[2] = (Building*)malloc(sizeof(Building) * 3);
		building[1] = (Building*)malloc(sizeof(Building) * 4);
		building[0] = (Building*)malloc(sizeof(Building) * 5);
	}
	else {
		printf("Building 할당에 실패하였습니다.");
		return 0;
	}
	return building;
}