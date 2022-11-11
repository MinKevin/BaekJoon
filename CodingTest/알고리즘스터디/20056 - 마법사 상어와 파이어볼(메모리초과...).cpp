//221111
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

struct Data {
	int m, s, d;
	int cntBall = 1, trial = 0;
	bool isOdd = false;
	bool isEven = false;
};

int N, M, K;
int infoSize;
deque<Data> board[50][50];
int vis[50][50];

int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void func() {
	int cnt = 0;
	while (K--) {
		//cout << "first\n";
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << vis[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (vis[i][j] != 0) {
					while (!board[i][j].empty() && board[i][j].front().trial == cnt) {
						Data cur = board[i][j].front();
						board[i][j].pop_front();
						//요 아래 부분 수식 r과 c는 0 ~ N - 1인데 성립하는 이유 잘 생각해보자
						//x % N일 경우 나올 수 있는 값은 0 ~ N - 1이기 때문에 성립하는 것도 하나의 이유
						int nx = (i + (cur.s % N) * dx[cur.d] + N * 2) % N;
						int ny = (j + (cur.s % N) * dy[cur.d] + N * 2) % N;
						vis[nx][ny] = 1;

						if (!board[nx][ny].empty() && board[nx][ny].back().trial == cnt + 1) {
							Data cur2 = board[nx][ny].back();
							cur2.m += cur.m;
							cur2.s += cur.s;
							cur2.cntBall++;
							if (cur.d % 2 == 0)
								cur2.isEven = true;
							else
								cur2.isOdd = true;
							board[nx][ny].back() = cur2;
						}
						else {
							if (cur.d % 2 == 0)
								cur.isEven = true;
							else
								cur.isOdd = true;
							board[nx][ny].push_back({ cur.m, cur.s, cur.d, 1, cur.trial + 1, cur.isOdd, cur.isEven });
						}
					}
					if (board[i][j].empty())
						vis[i][j] = 0;
				}
			}
		}
		cnt++;

		//cout << "second\n";
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << vis[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (vis[i][j] != 0 && board[i][j].front().cntBall != 1) {
					Data cur = board[i][j].front();
					board[i][j].pop_front();

					//cout << cur.m << ' ' << cur.s << ' ' << cur.d << ' ' << cur.cntBall << ' ' << cur.trial << '\n';

					Data dat;
					if (cur.isEven == 0 || cur.isOdd == 0) { //모두 홀, 짝
						for (int k = 0; k < 4; k++) {
							dat.m = cur.m / 5; dat.s = cur.s / cur.cntBall; dat.d = 2 * k; dat.trial = cnt;
							if (dat.m == 0)
								break;

							board[i][j].push_back(dat);
							//cout << dat.m << ' ' << dat.s << ' ' << dat.d << ' ' << cur.cntBall << ' ' << dat.trial << '\n';
						}
					}
					else {
						for (int k = 0; k < 4; k++) {
							dat.m = cur.m / 5; dat.s = cur.s / cur.cntBall; dat.d = 2 * k + 1; dat.trial = cnt;
							if (dat.m == 0)
								break;

							board[i][j].push_back(dat);
							//cout << dat.m << ' ' << dat.s << ' ' << dat.d << ' ' << cur.cntBall << ' ' << dat.trial << '\n';
						}
					}
				}
			}
		}

		//cout << "third\n";
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << vis[i][j] << ' ';
		//	}
		//	cout << '\n';
		//}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	Data dat;
	infoSize = M;
	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c >> dat.m >> dat.s >> dat.d;
		r--; c--;
		board[r][c].push_back(dat);
		vis[r][c] = 1;
	}

	//N = 50;
	//M = 2500;
	//K = 1000;


	//for (int i = 0; i < 50; i++) {
	//	for (int j = 0; j < 50; j++) {
	//		vis[i][j] = 1;
	//		board[i][j].push(50 * i + j);
	//		//info.push_back({ i, j, i * j, i * j % 1000, i * j % 1000, j % 8 });
	//		info.push_back({ i, j, j % 8, 1000, 1000, 0 });
	//	}
	//}

	func();

	int answer = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (vis[i][j] == 1)
				while (!board[i][j].empty()) {
					//cout << info[board[i][j].front()].m << ' ';
					answer += board[i][j].front().m;
					board[i][j].pop_front();
				}
		}

	cout << answer << '\n';
}