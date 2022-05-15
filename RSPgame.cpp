/* 컴퓨터와 가위바위보 대결 - 랜덤함수 이용 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int win = 0, draw = 0, lose = 0;
string name0, name1, name2, name3, name4, name;

void winorlose(int u, int c);
void userresult(int ur);
void comresult(int cr);
string namelist(int game);

int main()
{
	int times = 1, game = 0, score[5]={0};

	cout << "\n      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	cout << "      ┃       승:3점    무:1점    패:0점      ┃" << endl;
	cout << "      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

	while (times < 6) {
		srand((unsigned)time(NULL));
		int user, com;

		cout << "\n==============<컴퓨터와 가위바위보 대결>==============" << endl;
		cout << "\n[" << times << "번째 게임입니다]" << endl << endl;
		cout << "1.가위\n2.바위\n3.보" << endl << endl;

		do { //값이 1~3이 아닐경우 계속 입력받게함
			cout << "번호를 입력하세요 : ";
			cin >> user;
		} while (user < 1 || user>3);

		com = rand() % 3 + 1;

		winorlose(user, com); //사용자의 승무패 판별
		userresult(user); //사용자의 선택
		comresult(com); //컴퓨터의 선택

		times += 1;
		cout << "\n현재 결과: " << win << "승 " << draw << "무 " << lose << "패 " << endl;

		if (times == 6) { //5판째에 실행
			cout << "\n======================================================" << endl << endl;
			score[game] = win * 3 + draw;
			cout << "이름을 입력하세요: ";
			switch (game) {
			case 0: cin >> name0; break;
			case 1: cin >> name1; break;
			case 2: cin >> name2; break;
			case 3: cin >> name3; break;
			case 4: cin >> name4; break;
			}
			cout << endl << endl;
			cout << "\n\n                  < 최종결과 >" << endl << endl;
			cout << "                  " << win << "승 " << draw << "무 " << lose << "패 " << endl << endl;
			cout << "      " << namelist(game) << "님의 점수는 " << score[game] << "점 입니다." << endl << endl;

			//몇번째 게임인지 기록
			game++;

			//판횟수, 승무패 초기화
			times = 1, win = 0, draw = 0, lose = 0;
		}

		if (game == 5) break;
	}
	cout << "\n\n======================================================" << endl<<endl;
	cout << "    <전체점수> " << endl << endl;
	for (int j=0; j < 5; j++) cout << j+1<<". "<<namelist(j) << "        " << score[j] << endl;
	cout << "\n\n======================================================" << endl << endl;
	return 0;
}

void winorlose(int u, int c) { //사용자의 승무패 판별 함수
	if (((u == 1) && (c == 3)) || ((u == 3) && (c == 1)))
		if (u == 1) { cout << "\n이겼습니다!" << endl << endl; win += 1; }
		else { cout << "\n졌습니다!" << endl << endl; lose += 1; }

	else if (u == c) { cout << "\n무승부입니다!" << endl << endl; draw += 1; }
	else
		if (u > c) { cout << "\n이겼습니다!" << endl << endl; win += 1; }
		else { cout << "\n졌습니다!" << endl << endl; lose += 1; }
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

string namelist(int game) {
	switch (game) {
	case 0: name = name0; break;
	case 1: name = name1; break;
	case 2: name = name2; break;
	case 3: name = name3; break;
	case 4: name = name4; break;
	}
	return name;
}