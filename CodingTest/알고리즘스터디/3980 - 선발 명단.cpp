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
int mask[11];
vector<int> distance_;

void dfs(int cur, int sum) {
	if (cur == 11) {
		if (distance_.size() == repeat)
			distance_.push_back(sum);
		else //answer.size() == repeat + 1{
			if (distance_[repeat] < sum)
				distance_[repeat] = sum;
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (stats[cur][i] != 0 && mask[i] == 0) {
			mask[i] = 1;
			sum += stats[cur][i];
			dfs(cur + 1, sum);
			mask[i] = 0;
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

		memset(mask, 0, sizeof(mask));

		dfs(0, 0);
	}
	
	for (auto ans : distance_)
		cout << ans << '\n';
}