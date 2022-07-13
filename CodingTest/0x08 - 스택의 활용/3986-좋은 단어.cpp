#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int answer = 0;

	cin >> N;
	cin.ignore();

	string buf;
	while (N--) {
		stack<char> s;
		getline(cin, buf);

		for (int i = 0; i < buf.size(); i++) {
			if (s.empty())
				s.push(buf[i]);
			else if (s.top() == buf[i])
				s.pop();
			else if (s.top() != buf[i])
				s.push(buf[i]);
		}
		if (s.empty()) {
			answer++;
		}
	}
	cout << answer;
}

