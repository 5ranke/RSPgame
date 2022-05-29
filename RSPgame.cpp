/* ��ǻ�Ϳ� ���������� ��� - 2022111279 ������*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

int win = 0, draw = 0, lose = 0;
string name0, name1, name2, name; //3�� �̸� ����, �Է¹��� ����

void winorlose(int u, int c); // ������� �¹��� �Ǻ�
void userresult(int ur); // ������� ����
void comresult(int cr); // ��ǻ���� ����
string namelist(int game); // �̸� ��������
void Choice(int ChoiceNumber); //���������� �׸����
void ranking(int sc[]); //���� ���� (3��)

int main()
{
	int times = 1, game = 0, score[5]={0}; //5���� �������� ����

	string ruleline;
	ifstream rule("��������.txt");

	if (rule.is_open())
		while (getline(rule, ruleline))
			cout << ruleline << endl; //���� ����ҷ�����(txt)

	//���� ��� �ȳ�
	cout << "\n      ����������������������������������������������������������������������������������" << endl;
	cout << "      ��       ��:3��    ��:1��    ��:0��      ��" << endl;
	cout << "      ����������������������������������������������������������������������������������" << endl;

	//3���� ����(game), ���� 5�Ǿ�(times)
	//5�� ���ӹݺ�
	while (times < 6) {
		srand((unsigned)time(NULL));
		int user, com; // ��ǻ�Ϳ� ������� ���ð� ����

		if (times==1) cout << "\n==============<��ǻ�Ϳ� ���������� ���>==============" << endl;
		else cout << "\n======================================================" << endl;
		cout << "\n[" << times << "��° �����Դϴ�]" << endl << endl; // 5�� �� ���°����
		cout << "1.����  2.����  3.��" << endl << endl;

		do { //���� 1~3�� �ƴҰ�� ��� �Է¹ް���
			cout << "��ȣ�� �Է��ϼ��� : ";
			cin >> user;
		} while (user < 1 || user>3);

		com = rand() % 3 + 1; //��ǻ�ͼ��ð�

		Choice(com); 
		comresult(com); //��ǻ���� ���ð��
		cout << endl;

		Choice(user);
		userresult(user); //������� ���ð��
		cout << endl;

		winorlose(user, com); //������� �¹��� �Ǻ�

		times += 1;
		cout << "\n���� ���: " << win << "�� " << draw << "�� " << lose << "�� " << endl;//���������

		if (times == 6) { //5��°�� ����
			cout << "\n======================================================" << endl << endl;
			score[game] = win * 3 + draw;
			cout << "�̸��� �Է��ϼ���: "; //�̸��Է¹޾� ����
			switch (game) {
			case 0: cin >> name0; break;
			case 1: cin >> name1; break;
			case 2: cin >> name2; break;
			}
			cout << "\n======================================================" << endl << endl;
			cout << "\n\n                  < ������� >" << endl << endl;
			cout << "                  " << win << "�� " << draw << "�� " << lose << "�� " << endl << endl;
			cout << "      " << namelist(game) << "���� ������ " << score[game] << "�� �Դϴ�." << endl << endl;

			//���° �������� ���(��3��)
			game++;

			//��Ƚ��, �¹��� �ʱ�ȭ
			times = 1, win = 0, draw = 0, lose = 0;
		}

		if (game == 3) break;//3�� ������ �ݺ� ����
	}
	// ���� ������ ����ǥ����
	cout << "\n\n======================================================" << endl<<endl;
	cout << "                  < ����ǥ > " << endl << endl;
	ranking(score);
	cout << "\n\n======================================================" << endl << endl;
	return 0;
}

void winorlose(int u, int c) { //������� �¹��� �Ǻ� �Լ�
	if (((u == 1) && (c == 3)) || ((u == 3) && (c == 1)))
		if (u == 1) { cout << "\n     �̰���ϴ�!" << endl << endl; win += 1; }
		else { cout << "\n     �����ϴ�!" << endl << endl; lose += 1; }

	else if (u == c) { cout << "\n     ���º��Դϴ�!" << endl << endl; draw += 1; }
	else
		if (u > c) { cout << "\n     �̰���ϴ�!" << endl << endl; win += 1; }
		else { cout << "\n     �����ϴ�!" << endl << endl; lose += 1; }
}

void userresult(int ur) { //����ڼ��� ���
	switch (ur) {
	case 1: cout << "����� ������ �½��ϴ�" << endl; break;
	case 2: cout << "����� ������ �½��ϴ�" << endl; break;
	case 3: cout << "����� ���� �½��ϴ�" << endl; break;
	}
}

void comresult(int cr) { // ��ǻ�ͼ��� ���
	switch (cr) {
	case 1: cout << "��ǻ�ʹ� ������ �½��ϴ�" << endl; break;
	case 2: cout << "��ǻ�ʹ� ������ �½��ϴ�" << endl; break;
	case 3: cout << "��ǻ�ʹ� ���� �½��ϴ�" << endl; break;
	}
}

string namelist(int game) { //�̸������
	switch (game) {
	case 0: name = name0; break;
	case 1: name = name1; break;
	case 2: name = name2; break;
	}
	return name;
}

void Choice(int ChoiceNumber) { //���������� �׸� �ҷ�����
	string line1, line2, line3;
	ifstream file1("����.txt"), file2("����.txt"), file3("��.txt");

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
void ranking(int sc[]) { //�����Ǻ�(3��)
	int jump;
	string jumpp;

	//ù��°�� ���� ū ��� �н�
	//�ι�°�� ���� ū ���, ù��°�� �ٲ���
	if (sc[1] > sc[0] && sc[1] > sc[2]) {
		jump = sc[0]; sc[0] = sc[1]; sc[1] = jump;
		jumpp = name0; name0 = name1; name1 = jumpp;
	}
	//����°�� ���� ū ���, ù��°�� �ٲ���
	else if (sc[2] > sc[0] && sc[2] > sc[1]) {
		jump = sc[0]; sc[0] = sc[2]; sc[2] = jump;
		jumpp = name0; name0 = name2; name2 = jumpp;
	}
	//�״������� ����°�� ū ���
	if (sc[2] > sc[1]) {
		jump = sc[1]; sc[1] = sc[2]; sc[2] = jump;//�����ٲٱ�
		jumpp = name1; name1 = name2; name2 = jumpp;//�̸��ٲٱ�
	}

	cout << "              1. " << name0 << "     " << sc[0] << endl;//1��
	cout << "              2. " << name1 << "     " << sc[1] << endl;//2��
	cout << "              3. " << name2 << "     " << sc[2] << endl;//3��
}