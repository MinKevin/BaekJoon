#include <iostream>
#include <queue>

using namespace std;

int N;
//{count, where}
int dp[1000001];
vector<int> answer;
void func() {
	if (N == 1) {
		answer.push_back(1);
		return;
	}

	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int dir = 0; dir < 3; dir++) {
			int nx;
			if (dir == 0) {
				nx = cur * 3;
			}
			else if (dir == 1) {
				nx = cur * 2;
			}
			else {
				nx = cur + 1;
			}
			if (nx > N)
				continue;
			
			if (nx == N) {
				answer.push_back(N);
				int loc = cur;
				while (loc > 0) {
					answer.push_back(loc);
					loc = dp[loc];
				}
				return;
			}
			if (dp[nx] == 0) {
				dp[nx] = cur;
				q.push(nx);
			}
		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	func();
	cout << answer.size() - 1 << '\n';

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
}