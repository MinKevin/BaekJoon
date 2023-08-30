#include <iostream>
#include <stack>

#define ll long long

using namespace std;

int N;
ll ans;
stack<ll> s;

void input() {
	cin >> N;
}

ll solution() {
	ll height;
	for (int i = 0; i < N; i++) {
		cin >> height;
		while (!s.empty() && s.top() <= height)
			s.pop();

		ans += s.size();
		s.push(height);
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}