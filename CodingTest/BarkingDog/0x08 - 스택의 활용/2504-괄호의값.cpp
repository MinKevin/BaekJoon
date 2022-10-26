#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	char input[31];
	int answer = 0;
	bool wrong = false;
	stack<int> s;
	
	cin >> input;
	// ( : -1 [ : -2
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == '(')
			s.push(-1);
		else if (input[i] == '[')
			s.push(-2);
		else if (input[i] == ')') {
			int buf = 0;
			while (!s.empty() && s.top() != -1) {
				if (s.top() == -2) {
					wrong = true;
					break;
				}
					
				buf += s.top();
				s.pop();
			}
			if (s.empty()) {
				wrong = true;
				break;
			}
			else {
				s.pop();
				if (buf == 0)
					s.push(2);
				else
					s.push(buf * 2);
			}
		}
		else if (input[i] == ']') {
			int buf = 0;
			while (!s.empty() && s.top() != -2) {
				if (s.top() == -1) {
					wrong = true;
					break;
				}
				buf += s.top();
				s.pop();
			}
			if (s.empty()) {
				wrong = true;
				break;
			}
			else {
				s.pop();
				if (buf == 0)
					s.push(3);
				else
					s.push(buf * 3);
			}
		}
	}
	if (wrong == false) {
		while (!s.empty()) {
			if (s.top() == -2 || s.top() == -1) {
				answer = 0;
				break;
			}
			answer += s.top();
			s.pop();
		}
	}
	cout << answer;
}
