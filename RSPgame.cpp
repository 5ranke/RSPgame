/* 컴퓨터와 가위바위보 대결 - 2022111279 정수진*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

int win = 0, draw = 0, lose = 0;
string name0, name1, name2, name; //3명 이름 저장, 입력받을 변수

void winorlose(int u, int c); // 사용자의 승무패 판별
void userresult(int ur); // 사용자의 선택
void comresult(int cr); // 컴퓨터의 선택
string namelist(int game); // 이름 꺼내오기
void Choice(int ChoiceNumber); //가위바위보 그림출력
void ranking(int sc[]); //순위 정렬 (3명)

int main()
{
	int times = 1, game = 0, score[5]={0}; //5번의 게임점수 저장

	string ruleline;
	ifstream rule("게임제목.txt");

	if (rule.is_open())
		while (getline(rule, ruleline))
			cout << ruleline << endl; //게임 제목불러오기(txt)

	//점수 계산 안내
	cout << "\n      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	cout << "      ┃       승:3점    무:1점    패:0점      ┃" << endl;
	cout << "      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

	//3명이 게임(game), 각각 5판씩(times)
	//5번 게임반복
	while (times < 6) {
		srand((unsigned)time(NULL));
		int user, com; // 컴퓨터와 사용자의 선택값 저장

		if (times==1) cout << "\n==============<컴퓨터와 가위바위보 대결>==============" << endl;
		else cout << "\n======================================================" << endl;
		cout << "\n[" << times << "번째 게임입니다]" << endl << endl; // 5번 중 몇번째인지
		cout << "1.가위  2.바위  3.보" << endl << endl;

		do { //값이 1~3이 아닐경우 계속 입력받게함
			cout << "번호를 입력하세요 : ";
			cin >> user;
		} while (user < 1 || user>3);

		com = rand() % 3 + 1; //컴퓨터선택값

		Choice(com); 
		comresult(com); //컴퓨터의 선택결과
		cout << endl;

		Choice(user);
		userresult(user); //사용자의 선택결과
		cout << endl;

		winorlose(user, com); //사용자의 승무패 판별

		times += 1;
		cout << "\n현재 결과: " << win << "승 " << draw << "무 " << lose << "패 " << endl;//현재결과출력

		if (times == 6) { //5판째에 실행
			cout << "\n======================================================" << endl << endl;
			score[game] = win * 3 + draw;
			cout << "이름을 입력하세요: "; //이름입력받아 저장
			switch (game) {
			case 0: cin >> name0; break;
			case 1: cin >> name1; break;
			case 2: cin >> name2; break;
			}
			cout << "\n======================================================" << endl << endl;
			cout << "\n\n                  < 최종결과 >" << endl << endl;
			cout << "                  " << win << "승 " << draw << "무 " << lose << "패 " << endl << endl;
			cout << "      " << namelist(game) << "님의 점수는 " << score[game] << "점 입니다." << endl << endl;

			//몇명째 게임인지 기록(총3명)
			game++;

			//판횟수, 승무패 초기화
			times = 1, win = 0, draw = 0, lose = 0;
		}

		if (game == 3) break;//3명 끝나면 반복 종료
	}
	// 게임 끝나고 순위표공개
	cout << "\n\n======================================================" << endl<<endl;
	cout << "                  < 순위표 > " << endl << endl;
	ranking(score);
	cout << "\n\n======================================================" << endl << endl;
	return 0;
}

void winorlose(int u, int c) { //사용자의 승무패 판별 함수
	if (((u == 1) && (c == 3)) || ((u == 3) && (c == 1)))
		if (u == 1) { cout << "\n     이겼습니다!" << endl << endl; win += 1; }
		else { cout << "\n     졌습니다!" << endl << endl; lose += 1; }

	else if (u == c) { cout << "\n     무승부입니다!" << endl << endl; draw += 1; }
	else
		if (u > c) { cout << "\n     이겼습니다!" << endl << endl; win += 1; }
		else { cout << "\n     졌습니다!" << endl << endl; lose += 1; }
}

void userresult(int ur) { //사용자선택 출력
	switch (ur) {
	case 1: cout << "당신은 가위를 냈습니다" << endl; break;
	case 2: cout << "당신은 바위를 냈습니다" << endl; break;
	case 3: cout << "당신은 보를 냈습니다" << endl; break;
	}
}

void comresult(int cr) { // 컴퓨터선택 출력
	switch (cr) {
	case 1: cout << "컴퓨터는 가위를 냈습니다" << endl; break;
	case 2: cout << "컴퓨터는 바위를 냈습니다" << endl; break;
	case 3: cout << "컴퓨터는 보를 냈습니다" << endl; break;
	}
}

string namelist(int game) { //이름저장소
	switch (game) {
	case 0: name = name0; break;
	case 1: name = name1; break;
	case 2: name = name2; break;
	}
	return name;
}

void Choice(int ChoiceNumber) { //가위바위보 그림 불러오기
	string line1, line2, line3;
	ifstream file1("가위.txt"), file2("바위.txt"), file3("보.txt");

	switch (ChoiceNumber) {
	case 1:
		if (file1.is_open()) {
			while (getline(file1, line1)) {
				cout << line1 << endl;
			}
		}break;

	case 2:
		if (file2.is_open()) {
			while (getline(file2, line2)) {
				cout << line2 << endl;
			}
		}break;

	case 3:
		if (file3.is_open()) {
			while (getline(file3, line3)) {
				cout << line3 << endl;
			}
		}break;
	}
}
void ranking(int sc[]) { //순위판별(3명)
	int jump;
	string jumpp;

	//첫번째가 가장 큰 경우 패스
	//두번째가 가장 큰 경우, 첫번째와 바꿔줌
	if (sc[1] > sc[0] && sc[1] > sc[2]) {
		jump = sc[0]; sc[0] = sc[1]; sc[1] = jump;
		jumpp = name0; name0 = name1; name1 = jumpp;
	}
	//세번째가 가장 큰 경우, 첫번째와 바꿔줌
	else if (sc[2] > sc[0] && sc[2] > sc[1]) {
		jump = sc[0]; sc[0] = sc[2]; sc[2] = jump;
		jumpp = name0; name0 = name2; name2 = jumpp;
	}
	//그다음으로 세번째가 큰 경우
	if (sc[2] > sc[1]) {
		jump = sc[1]; sc[1] = sc[2]; sc[2] = jump;//점수바꾸기
		jumpp = name1; name1 = name2; name2 = jumpp;//이름바꾸기
	}

	cout << "              1. " << name0 << "     " << sc[0] << endl;//1위
	cout << "              2. " << name1 << "     " << sc[1] << endl;//2위
	cout << "              3. " << name2 << "     " << sc[2] << endl;//3위
}