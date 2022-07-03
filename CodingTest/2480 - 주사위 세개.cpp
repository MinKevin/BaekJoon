#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//int board[7] == {1} <= ù��° ���Ҹ� 1�� �ʱ�ȭ, �������� 0���� �ʱ�ȭ��
	int board[7] = {0, };

	//memset�� for������ ���� �ӵ��� ���� ����
	//memset(board, 1, sizeof(board));

	//fill_n(board, sizeof(board), 1);

	int buf;
	for (int i = 0; i < 3; i++) {
		cin >> buf;
		board[buf]++;
	}
	
	int max_one = 0;
	for (int i = 1; i <= 6; i++) {
		if (board[i] == 3) {
			cout << 10000 + i * 1000;
			return 0;
		}
		else if (board[i] == 2) {
			cout << 1000 + i * 100;
			return 0;
		}
		else if (board[i] == 1) {
			if (i > max_one)
				max_one = i;
		}
	}
	cout << max_one * 100;


	return 0;
}