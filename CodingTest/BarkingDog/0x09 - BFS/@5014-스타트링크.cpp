#include <iostream>
#include <queue>

using namespace std;

int board[1000001];

int F, S, G, U, D;
int bufD;

int* dx[2] = { &U, &bufD };

int BFS() {
	queue<int> q;
	q.push(S);

	if (S == G)
		return 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + *dx[dir];

			if (nx <= 0 || nx > F)
				continue;

			if (board[nx] == 0) {
				board[nx] = board[cur] + 1;
				q.push(nx);
			}

			else if (board[nx] == -1) {
				return board[cur];
			}
		}
	}

	return -1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	
	board[G] = -1;
	board[S] = 1;
	bufD = D * -1;
	int answer = BFS();
	
	if (answer == -1)
		cout << "use the stairs";
	else
		cout << answer;
}