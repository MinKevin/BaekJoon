#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	int answer = 0;
	int temp = 1;
	stack<char> s;

	char input[31];
	cin.getline(input, 31);

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] == '(') {
			temp *= 2;
			s.push(input[i]);
		}
		else if (input[i] == '[') {
			temp *= 3;
			s.push(input[i]);
		}
		else if (input[i] == ')') {
			if (s.empty() || s.top() == '[') {
				answer = 0;
				break;
			}
			else if (input[i - 1] == '(') {
				answer += temp;
				temp /= 2;
			}
			else {
				temp /= 2;
			}
			s.pop();
		}
		else if (input[i] == ']') {
			if (s.empty() || s.top() == '(') {
				answer = 0;
				break;
			}
			else if (input[i - 1] == '[') {
				answer += temp;
				temp /= 3;
			}
			else {
				temp /= 3;
			}
			s.pop();
		}
	}
	if (!s.empty())
		answer = 0;

	cout << answer;
}
