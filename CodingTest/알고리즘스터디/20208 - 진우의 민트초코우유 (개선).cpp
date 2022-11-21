#include <iostream>
#include <vector>
using namespace std;

//반례
//2 2 1
//1 0
//0 2

vector<pair<int, int>> mintChoco;
int vis[10][10];
pair<int, int> home;
int N, M, H;

int totalMilk;
int answer;

int abs(int x) {
	if (x < 0)
		return x * -1;

	else
		return x;
}

void findMilk(int x, int y, int cntMilk, int M) {
	int disFromHome = abs(x- home.first) + abs(y - home.second);
	if (disFromHome <= M && answer < cntMilk)
		answer = cntMilk;

	for (int i = 0; i < totalMilk; i++) {
		pair<int, int> cur = mintChoco[i];
		if (vis[cur.first][cur.second] == 1)
			continue;

		int disFromExMilk = abs(cur.first - x) + abs(cur.second - y);
		if (disFromExMilk <= M) {
			M -= disFromExMilk - H;
			vis[cur.first][cur.second] = 1;
			//cout << cur.first << ' ' << cur.second << ' ' << cntMilk + 1 << ' ' <<  M << '\n';
			findMilk(cur.first, cur.second, cntMilk + 1, M);
			vis[cur.first][cur.second] = 0;
			M += disFromExMilk - H;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;

	int inp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> inp;
			if (inp == 2)
				mintChoco.push_back({ i, j });
			if (inp == 1)
				home = { i, j };
		}
	}
	totalMilk = mintChoco.size();
	findMilk(home.first, home.second, 0);

	cout << answer;
}