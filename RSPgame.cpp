#include <iostream>
#include <cstdlib>
#include <ctime>

// 컴퓨터와 가위바위보 대결 - 랜덤함수 이용
using namespace std;
int main()
{
	int i = 1, j = 1, sum = 0;
	int win = 0, draw = 0, lose = 0;
	string name;

	cout << "\n      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	cout << "      ┃       승:3점    무:1점    패:0점      ┃" << endl;
	cout << "      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

	while (j == 1)
	{
		while (i < 6)
		{
			srand((unsigned)time(NULL));
			int user, com;

			cout << "\n==============<컴퓨터와 가위바위보 대결>==============" << endl;
			cout << "\n[" << i << "번째 게임입니다]" << endl << endl;
			cout << "1.가위\n2.바위\n3.보" << endl << endl;
			do {
				cout << "번호를 입력하세요 : ";
				cin >> user;
			} while (user < 1 || user>3);

			com = rand() % 3 + 1;

			// 사용자 기준 승패 판별
			if (((user == 1) && (com == 3)) || ((user == 3) && (com == 1)))
				if (user == 1) {
					cout << "\n이겼습니다!" << endl << endl;
					win += 1;
				}
				else {
					cout << "\n졌습니다!" << endl << endl;
					lose += 1;
				}

			else if (user == com) {
				cout << "\n무승부입니다!" << endl << endl;
				draw += 1;
			}

			else
				if (user > com) {
					cout << "\n이겼습니다!" << endl << endl;
					win += 1;
				}
				else {
					cout << "\n졌습니다!" << endl << endl;
					lose += 1;
				}

			// 사용자 가위바위보 출력
			switch (user)
			{
			case 1:
				cout << "당신은 가위를 냈습니다" << endl;
				break;
			case 2:
				cout << "당신은 바위를 냈습니다" << endl;
				break;
			case 3:
				cout << "당신은 보를 냈습니다" << endl;
				break;
			}

			// 컴퓨터 가위바위보 출력
			switch (com)
			{
			case 1:
				cout << "컴퓨터는 가위를 냈습니다" << endl;
				break;
			case 2:
				cout << "컴퓨터는 바위를 냈습니다" << endl;
				break;
			case 3:
				cout << "컴퓨터는 보를 냈습니다" << endl;
				break;
			}
			i += 1;
			cout << "\n현재 결과: " << win << "승 " << draw << "무 " << lose << "패 " << endl;

		}

		cout << "\n======================================================" << endl << endl;
		cout << "이름을 입력하세요: ";
		cin >> name;
		cout << endl << endl;
		cout << "\n\n                  < 최종결과 >" << endl << endl;
		cout << "                  " << win << "승 " << draw << "무 " << lose << "패 " << endl << endl;
		cout << "      " << name << "님의 점수는 " << win * 3 + draw << "입니다." << endl << endl;
		cout << "\n1.한번 더 하기\n2.중단하기\n\n번호를 입력하세요 : ";
		cin >> j;

		i = 1;
		win = 0, draw = 0, lose = 0;

	}



	return 0;
}