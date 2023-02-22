#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	int answer = 0;
	stack<char> s;

	cin >> input;

	char buf =' ';
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(')
			s.push(input[i]);
		else {
			if (s.empty()) {

			}
			if (buf == '(') {
				s.pop();
				if (!s.empty())
					s.push('1');
			}
			else {
				int razor_cnt = 0;
				while (s.top() != '(') {
					razor_cnt += s.top() - '0';
					s.pop();
				}
				s.pop();
				answer += razor_cnt + 1;

				cout << answer << '\n';
				if (!s.empty()) {
					s.push(razor_cnt + '0');
				}
			}
		}
		buf = input[i];
	}
	cout << answer;
}