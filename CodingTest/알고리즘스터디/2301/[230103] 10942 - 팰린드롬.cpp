/*
Date : 230123
Time : 20:58 ~ 
Comment :
	줜나 어렵다....
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
int board[2001][2001];

void palindrome() {
	for (int i = 1; i <= N; i++) {
		board[i][i] = 1;

		if (i != 1 && arr[i - 1] == arr[i]) {
			board[i - 1][i] = 1;
		}
	}

	for (int i = 3; i <= N; i++) {
		for (int j = 1; i + j - 1 <= N; j++) {
			if (arr[j] == arr[j + i - 1] && board[j + 1][j + i - 2] == 1) {
				board[j][j + i - 1] = 1;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int input;
	arr.push_back(0);
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}

	palindrome();

	cin >> M;
	int x, y;
	vector<int> answer;
	while (M--) {
		cin >> x >> y;
		answer.push_back(board[x][y]);
	}
	for (auto v : answer)
		cout << v << '\n';
}