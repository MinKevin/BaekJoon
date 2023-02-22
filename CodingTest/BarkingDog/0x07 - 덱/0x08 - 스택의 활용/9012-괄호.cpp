#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string answer = "";

	cin >> N;

	string input;
	while (N--) {
		stack<char> s;
		
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(')
				s.push(input[i]);
			else if (input[i] == ')') {
				if (s.empty()) {
					s.push(input[i]);
					break;
				}
				else {
					s.pop();
				}
			}
		}
		if (s.empty())
			answer += "YES\n";
		else
			answer += "NO\n";
	}
	cout << answer;
}