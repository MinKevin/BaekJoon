//221111
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Data {
	int r, c, d;
	int m, s;
	int trial = 0;
};

int N, M, K;
int infoSize;
queue<int> board[50][50];
vector<Data> info;
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
		bool isOdd = false;
		bool isEven = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (vis[i][j] != 0) {

					while (!board[i][j].empty()) {
						if (cnt != info[board[i][j].front()].trial)
							break;

						int cur = board[i][j].front();
						board[i][j].pop();
						//�� �Ʒ� �κ� ���� r�� c�� 0 ~ N - 1�ε� �����ϴ� ���� �� �����غ���
						//x % N�� ��� ���� �� �ִ� ���� 0 ~ N - 1�̱� ������ �����ϴ� �͵� �ϳ��� ����
						int nx = (info[cur].r + (info[cur].s % N) * dx[info[cur].d] + N * 2) % N;
						int ny = (info[cur].c + (info[cur].s % N) * dy[info[cur].d] + N * 2) % N;

						//cout << nx << ' ' << ny << '\n';
						Data dat;

						dat.r = nx; dat.c = ny; dat.d = info[cur].d; dat.m = info[cur].m; dat.s = info[cur].s; dat.trial = info[cur].trial + 1;
						//cout << dat.r << ' ' << dat.c << ' ' << dat.d << ' ' << dat.m << ' ' << dat.s << ' ' << dat.trial << '\n';
						info.push_back(dat);
						board[nx][ny].push(infoSize++);
						vis[nx][ny] = 1;
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
				if (vis[i][j] != 0) {
					int mSum = 0;
					int sSum = 0;
					int evenOdd[2] = { 0, 0 };
					int cntBall = 0;

					if (board[i][j].size() <= 1)
						continue;

					bool once = false;
					while (!board[i][j].empty()) {
						//cout << "����\n";
						if (cnt != info[board[i][j].front()].trial)
							break;
						once = true;
						int cur = board[i][j].front();
						board[i][j].pop();

						cntBall++;
						//cout << info[cur].m << '\n';
						mSum += info[cur].m;
						sSum += info[cur].s;
						evenOdd[info[cur].d % 2]++;
					}
					if (once == false)
						continue;

					if (evenOdd[0] == 0 || evenOdd[1] == 0) {
						for (int d = 0; d < 4; d++) {
							Data dat;
							dat.r = i; dat.c = j; dat.d = 2 * d; dat.m = mSum / 5; dat.s = sSum / cntBall; dat.trial = cnt;
							//cout << dat.r << ' ' << dat.c << ' ' << dat.d << ' ' << dat.m << ' ' << dat.s << ' ' << dat.trial << '\n';
							info.push_back(dat);
							board[i][j].push(infoSize++);
						}
					}
					else {
						for (int d = 0; d < 4; d++) {
							Data dat;
							dat.r = i; dat.c = j; dat.d = 2 * d + 1; dat.m = mSum / 5; dat.s = sSum / cntBall; dat.trial = cnt;
							//cout << dat.r << ' ' << dat.c << ' ' << dat.d << ' ' << dat.m << ' ' << dat.s << ' ' << dat.trial << '\n';
							info.push_back(dat);
							board[i][j].push(infoSize++);
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
		dat.r = r - 1;
		dat.c = c - 1;
		info.push_back(dat);
		board[dat.r][dat.c].push(i);
		vis[dat.r][dat.c] = 1;
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
					answer += info[board[i][j].front()].m;
					board[i][j].pop();
				}
		}

	cout << answer << '\n';


	//func();

	//int answer = 0;
	//for (int i = 0; i < N; i++)
	//	for (int j = 0; j < N; j++) {
	//		if (vis[i][j] == 1)
	//			while (!board[i][j].empty()) {
	//				//cout << info[board[i][j].front()].m << ' ';
	//				answer += info[board[i][j].front()].m;
	//				board[i][j].pop();
	//			}
	//	}

	//cout << answer;

}