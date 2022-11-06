#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<vector<int>> board;
int answer[2];

int func(int N, int x, int y) {
	if (N == 1) {
		answer[board[x][y]]++;
		return board[x][y];
	}

	int cnt[2];
	memset(cnt, 0, sizeof(cnt));

	bool cantOne = false;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			//비트 시프트 연산자의 우선순위는 덧셈, 뺄셈 연산자 다음이므로
			int buf = func(N >> 1, x + (N >> 1) * i, y + (N >> 1) * j);
			if (buf != -1)
				cnt[buf]++;
			else
				cantOne = true;
		}
	}

	if (cantOne == false)
		for (int i = 0; i < 2; i++) {
			if (cnt[i] == 4) {
				answer[i] -= 3;
				return i;
			}
		}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	board.resize(N, vector<int>(0));

	int inpNum;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> inpNum;
			board[i].push_back(inpNum);
		}
	}

	func(N, 0, 0);

	cout << answer[0] << '\n' << answer[1];
}