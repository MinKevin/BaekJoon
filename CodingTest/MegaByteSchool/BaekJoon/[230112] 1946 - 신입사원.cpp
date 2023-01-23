#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
pair<int, int> board[100000];

struct cmp {
	bool operator()(pair<int, int> x, pair<int, int> y) {
		return x.first == y.first ? x.second < y.second : x.first < y.first;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		int x, y;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			board[i] = { x, y };
		}
		sort(&board[0], &board[N], cmp());
		int min = board[0].second;
		int answer = 1;
		for (int i = 1; i < N; i++) {
			if (board[i].second <= min) {
				answer++;
				min = board[i].second;
			}
		}
		cout << answer << '\n';
	}

}