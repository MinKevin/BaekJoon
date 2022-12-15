#include <iostream>
#include <cmath>
#include <vector>

//23 2 1 0 22 0 1 21 2 20

using namespace std;

int N;
int board[20][20];
int mask;
int distance_ = 0x7FFFFFFF;

int calculateStats(int vis) {
	int homeStats = 0;
	int awayStats = 0;
	for (int i = 0; i < N - 1; i++) {
		bool firstHomeTeam = (1 << i & vis) == 0 ? false : true;
		for (int j = i + 1; j < N; j++) {
			bool secondHomeTeam = (1 << j & vis) == 0 ? false : true;
			if (firstHomeTeam && secondHomeTeam) {
				awayStats += board[i][j] + board[j][i];
			}
			else if (!firstHomeTeam && !secondHomeTeam) {
				homeStats += board[i][j] + board[j][i];
			}
		}
	}
	return abs(homeStats - awayStats);
}

void bitMasking() {
	for (int i = 1; i < (1 << (N - 1)) - 1; i++) {
		distance_ = min(distance_, calculateStats(i));
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	bitMasking();

	cout << distance_;
}