/*
Date : 22.12.03
Time : 14:11~
Comment :
*/

#include <iostream>

using namespace std;

int N;
bool columnUsed[30];
bool downTopUsed[30];
bool topDownUsed[30];
int answer;

void dfs(int cur) {
	if (cur == N) {
		answer++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (columnUsed[i] || downTopUsed[i + cur] || topDownUsed[i - cur + N - 1])
			continue;
		columnUsed[i] = 1;
		downTopUsed[i + cur] = 1;
		topDownUsed[i - cur + N - 1] = 1;
		dfs(cur + 1);
		columnUsed[i] = 0;
		downTopUsed[i + cur] = 0;
		topDownUsed[i - cur + N - 1] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	dfs(0);

	cout << answer;
}