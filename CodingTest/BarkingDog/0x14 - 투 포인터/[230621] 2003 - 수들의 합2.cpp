#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void input() {
	cin >> N >> M;

	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
}

int solution() {
	int en = 0, sum = 0, ans = 0;

	for (int st = 0; st < N; st++) {
		while (en < N && sum < M) {
			sum += v[en++];
		}
		if (sum == M)
			ans++;
		sum -= v[st];
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}