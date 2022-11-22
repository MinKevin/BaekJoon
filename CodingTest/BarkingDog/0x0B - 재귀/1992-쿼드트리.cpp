#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<string> board;
vector<char> answer;

char func(int N, int x, int y) {
	if (N == 1) {
		answer.push_back(board[x][y]);
		return board[x][y];
	}

	char buf;
	bool cantOne = false;
	int count[2];
	memset(count, 0, sizeof(count));
	answer.push_back('(');
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			buf = func(N >> 1, x + N / 2 * i, y + N / 2 * j);
			if (buf != NULL) {
				//이 부분 debugging 하는데 거의 1시간을 썼다...
				// 아래 구문을 여기다 넣으면 안되고 
				// BaseCondition, 즉 13번째 줄에 넣어야한다...
				//answer.push_back(buf);
				count[buf - '0']++;
			}
			
			else
				cantOne = true;
		}
	}

	if (cantOne == false) {
		for (int i = 0; i < 2; i++) {
			if (count[i] == 4) {
				while (answer.back() != '(')
					answer.pop_back();
				answer.pop_back();
				answer.push_back(buf);
				return buf;
			}
		}
	}
	answer.push_back(')');
	return '\0';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	board.resize(N);

	for (int i = 0; i < N; i++)
		cin >> board[i];

	func(N, 0, 0);
	
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i];
}