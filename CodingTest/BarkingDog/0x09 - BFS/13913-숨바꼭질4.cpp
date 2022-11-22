//1) 시작점과 도착점이 같은 경우를 확인하세요
//
//입력 : 5 5
//
//출력 :
//
//	0
//
//	5
//
//
//
//	2) 시작점이 0인 경우를 생각하세요. (메모리 초과)
//
//	만약 방문했던 부모를 저장하는 배열을 0으로 초기화해서 구현하셨을 경우
//
//	시작점이 0인 경우에 문제가 생길 수도 있습니다.

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int board[100001][2];
int dx[2] = { 1, -1 };

int N, K;

int BFS() {
	if (N == K) 
		return 0;
	

	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int dir = 0; dir < 3; dir++) {
			int nx;
			if (dir == 2)
				nx = cur * 2;
			else
				nx = cur + dx[dir];

			if (nx < 0 || nx > 100000)
				continue;

			if (nx == K) {
				board[K][1] = cur;
				return board[cur][0];
			}

			if (board[nx][0] == -1) {
				board[nx][0] = board[cur][0] + 1;
				board[nx][1] = cur;
				q.push(nx);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(&board[0][1], &board[100001][1], -1);
	cin >> N >> K;
	board[N][0] = 1;
	board[K][0] = -1;
	
	cout << BFS() << '\n';

	stack<int> s;
	s.push(K);
	int cur = K;
	while (board[cur][1] != -1) {
		s.push(board[cur][1]);
		cur = board[cur][1];
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}