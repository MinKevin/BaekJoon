#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long long answer = 0;
	stack<int> s;

	cin >> N;

	int buf;
	while (N--) {
		cin >> buf;
		while (!s.empty() && s.top() <= buf)
			s.pop();
		answer += s.size();
		s.push(buf);
	}
	cout << answer;
}