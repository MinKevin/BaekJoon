#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string answer;

	while (true) {
		stack<char> s;
		string input;
		getline(cin, input);
		if (input[0] == '.')
			break;

		int cur = 0;
		while (cur != input.size()) { 
			if (input[cur] == '(' || input[cur] == '[') {
				s.push(input[cur]);
				cur++;
			}
			else if (input[cur] == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
					cur++;
				}
				else {
					answer += "no\n";
					break;
				}
			}
			else if (input[cur] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
					cur++;
				}
				else {
					answer += "no\n";
					break;
				}
			}
			else if (input[cur] == '.') {
				if (s.empty())
					answer += "yes\n";
				else
					answer += "no\n";
				cur++;
			}
			else
				cur++;
		}
	}
	cout << answer;
}