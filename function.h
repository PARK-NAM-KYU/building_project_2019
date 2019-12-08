#pragma once
<<<<<<< Updated upstream
void start_view(Position * position);
void start_logic();
Building ** make_building();
void building_view(Position * position);
void building_info(Building *** building);
void floor_view(Position * position);
int floor_logic();
=======
#include "struct.h"

void start_view();
Building ** make_building();
void building_view();
void building_info(Building *** );
void floor_view(int);
int floor_logic();
void result_view();
void event(Player* player, int* floor);
>>>>>>> Stashed changes
