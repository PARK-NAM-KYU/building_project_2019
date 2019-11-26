#include "basic.h"
#include "function.h"

int main() {

	Player me;
	Building** building;
	Position position; // x,y 좌표
	int floor = 1; //플레이어의 현재 층
	int choice; //각 층에서 사용자의 방 선택

	//position 초기화
	position.x = 1;
	position.y = 1;

	//1.시작화면 출력하기
	start_view(&position);
	start_logic();

	//2. 일단 하 기준으로 난이도 설정
	//3. 건물 만들고 보여주기
	building = make_building();
	building_view(&position); //어떤 키를 누르면 다음으로 넘어가는 함수 구현

	building_info(&building); // 빌딩 정보 넣어주기

	while (floor <= 5) {
		floor_view(&position); //각 층 보여주기
		choice = floor_logic(); //방 선택
		building[floor - 1][choice - 1].func(&position, &me, &floor);
	}

	//엔딩화면
	result_view(&position); // 그냥 무슨키 누르면 끝내주는 로직도 같이 구현

}