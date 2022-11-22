#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, answer = 0;
	stack<int> s;

	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0 && !s.empty()) {
			s.pop();
		}
		else
			s.push(num);
	}

	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}
	cout << answer;
}