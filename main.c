#include "basic.h"
#include "function.h"

int main() {

	Player me = { "플레이어", 1000, 200,0 };
	Player boss = { "보스", 2000, 200,0 };
	Building** building;
	Potion * currentPotion;
	int floor = 1; //플레이어의 현재 층
	int choice = 0; //각 층에서 사용자의 방 선택
	int i;

	srand((unsigned int)time(NULL));

	me.potionList = addPotion(300);
	currentPotion = me.potionList;

	system("mode con cols=100 lines=30");//콘솔창 고정
	setcursortype(); //커서 없애주기

	//1.시작화면 출력하기
	basic_view2(&me);
	start_view();
	//2. 일단 하 기준으로 난이도 설정
	//3. 건물 만들고 보여주기

	building = make_building();
	building_info(&building); // 빌딩 정보 넣어주기

	basic_view2(&me);
	building_view(); //어떤 키를 누르면 다음으로 넘어가는 함수 구현

	while (floor <= 5) {
		i = floor;
		basic_view2(&me);
		floor_view(floor); //각 층 보여주기
		choice = floor_logic(floor); //방 선택
		system("cls");
		if (floor != 5) {
			basic_view2(&me);
			building[floor - 1][choice - 1].func(&me, &floor);
			//이거 이겼고 리워드가 1이면 포션연결해주기...
		}
		else {
			battle(&me, &boss);
		}
		if (i + 1 == floor && building[floor - 1][choice - 1].reward == 1) {

			currentPotion->link = addPotion(rand() % 10 + 300);
			currentPotion = currentPotion->link;
		}
	}

	//엔딩화면
	basic_view2(&me);
	result_view(); // 그냥 무슨키 누르면 끝내주는 로직도 같이 구현
	free(building);//☆마지막에 free해줘야함!!
}