/*
Date : 22.12.06
Time : 0:25
Memo : 이 문제를 기준으로 0일 때 건너뛰는 조건도 중간 탈출이므로 백트래킹
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int C, repeat;
int stats[11][11]; 
int vis[11];
vector<int> answer;

void dfs(int cur, int sum) {
	if (cur == 11) {
		if (answer.size() == repeat)
			answer.push_back(sum);
		else //answer.size() == repeat + 1{
			if (answer[repeat] < sum)
				answer[repeat] = sum;
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (stats[cur][i] != 0 && vis[i] == 0) {
			vis[i] = 1;
			sum += stats[cur][i];
			dfs(cur + 1, sum);
			vis[i] = 0;
			sum -= stats[cur][i];
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> C;
	for (repeat = 0; repeat < C; repeat++) {
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> stats[i][j];

		memset(vis, 0, sizeof(vis));

		dfs(0, 0);
	}
	
	for (auto ans : answer)
		cout << ans << '\n';
}