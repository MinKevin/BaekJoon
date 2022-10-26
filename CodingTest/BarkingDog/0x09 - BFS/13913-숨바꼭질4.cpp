//1) �������� �������� ���� ��츦 Ȯ���ϼ���
//
//�Է� : 5 5
//
//��� :
//
//	0
//
//	5
//
//
//
//	2) �������� 0�� ��츦 �����ϼ���. (�޸� �ʰ�)
//
//	���� �湮�ߴ� �θ� �����ϴ� �迭�� 0���� �ʱ�ȭ�ؼ� �����ϼ��� ���
//
//	�������� 0�� ��쿡 ������ ���� ���� �ֽ��ϴ�.

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