#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<pair<int, int>> s;
vector<int> ans;
void input() {
	cin >> N;
}

void solution() {
	int inp;
	for (int i = 1; i <= N; i++) {
		cin >> inp;
		while (!s.empty() && s.top().first <= inp)
			s.pop();

		if (s.empty()) {
			s.push({ inp, i });
			ans.push_back(0);
		}
		else {
			ans.push_back(s.top().second);
			s.push({ inp, i });
		}
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}