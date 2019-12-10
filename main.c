#include "basic.h"
#include "struct.h"
#include "function.h"

int main() {

<<<<<<< Updated upstream
<<<<<<< Updated upstream
	Player me;
=======
	Player me = { "플레이어", 1000, 200,0};
	Player boss = { "보스", 2000, 200,0};
>>>>>>> Stashed changes
	Building** building;
	Position position; // x,y 좌표
=======
	Player me = { "플레이어", 100, 20, {0, 0}};
	Player boss = { "보스", 200, 20, {0, 0}};
	Building** building;
	Potion* head = (Potion*)malloc(sizeof(Potion));
	Potion* potionList = (Potion*)malloc(sizeof(Potion)); //포션 얻을때마다 공간할당 후
	head->link = NULL; //head에 연결시켜주고 포션의 link에 NULL대입
	potionList->effect = 30;
	
>>>>>>> Stashed changes
	int floor = 1; //플레이어의 현재 층
	int choice; //각 층에서 사용자의 방 선택

<<<<<<< Updated upstream
	//position 초기화
	position.x = 1;
	position.y = 1;
=======
	me.potionList = addPotion(300);
	currentPotion = me.potionList;
>>>>>>> Stashed changes

	//1.시작화면 출력하기
<<<<<<< Updated upstream
	start_view(&position);
	start_logic();

=======
	basic_view2(&me);
	start_view();
>>>>>>> Stashed changes
	//2. 일단 하 기준으로 난이도 설정
	//3. 건물 만들고 보여주기
	building = make_building();
	building_view(&position); //어떤 키를 누르면 다음으로 넘어가는 함수 구현

	building_info(&building); // 빌딩 정보 넣어주기
<<<<<<< Updated upstream

	while (floor<=5) {
		floor_view(&position); //각 층 보여주기
=======
	
	basic_view2(&me);
	building_view(); //어떤 키를 누르면 다음으로 넘어가는 함수 구현
	
	/*while (floor <= 5) {
		basic_view2(me);

		floor_view(floor); //각 층 보여주기
>>>>>>> Stashed changes
		choice = floor_logic(); //방 선택
		building[floor - 1][choice - 1].func(&position, &me, &floor);
	}
<<<<<<< Updated upstream

	//엔딩화면
=======
	*/
	battle(&me, &boss); //5층에서 배틀

	//엔딩화면
	basic_view2(&me);
>>>>>>> Stashed changes
	result_view(); // 그냥 무슨키 누르면 끝내주는 로직도 같이 구현

}