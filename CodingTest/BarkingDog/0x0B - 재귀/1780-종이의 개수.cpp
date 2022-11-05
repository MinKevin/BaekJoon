#include <iostream>
#include <vector>

using namespace std;

int minusOne, zero, one;
vector<vector<int>> board;
int func(int N, int x, int y) {
	if (N == 1) {
		return board[x][y];
	}


}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);



	int N;
	cin >> N;
	board.resize(N, vector<int>(N, 0));
	//board.resize(N, vector<int>(0, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			/*int buf;
			cin >> buf;
			board[i].push_back(buf);*/
		}
	}

	func(N, 0, 0);
}