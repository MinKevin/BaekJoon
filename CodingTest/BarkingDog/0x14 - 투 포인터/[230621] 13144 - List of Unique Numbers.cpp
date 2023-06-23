#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int kindsCnt[100001];

void input() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
}

int solution() {
	int ans = 0;
	vector<int>::iterator end = v.begin();
	for (vector<int>:: iterator st = v.begin(); st != v.end(); st++) {
		while (end != v.end() && kindsCnt[*end] == 0) {
			kindsCnt[*end++] = 1;
		}
		ans += distance(st, end);
		kindsCnt[*st] = 0;
		//cout << ans << '\n';
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}