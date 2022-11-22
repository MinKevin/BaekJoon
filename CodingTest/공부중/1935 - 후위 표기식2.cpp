#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long arr[26] = {0, };
	string inp;
	stack<double> s;

	cin >> N;
	cin >> inp;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < inp.size(); i++) {
		if (inp[i] >= 'A' && inp[i] <= 'Z')
			s.push(arr[inp[i] - 'A']);

		else {
			double num2 = s.top();
			s.pop();
			double num1 = s.top();
			s.pop();

			switch (inp[i]) {
			case '+':
				s.push(num1 + num2);
				break;

			case '-':
				s.push(num1 - num2);
				break;

			case '*':
				s.push(num1 * num2);
				break;

			case '/':
				s.push(num1 / num2);
				break;
			}
		}
	}
	cout.precision(2);
	cout << fixed;
	cout << s.top();
}