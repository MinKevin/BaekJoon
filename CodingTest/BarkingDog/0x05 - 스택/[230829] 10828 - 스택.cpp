#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> s;

void input() {
	cin >> N;
}

void solution() {
	string order;
	int num;
	while (N--) {
		cin >> order;
		if (order == "push") {
			cin >> num;
			s.push(num);
		}
		else if (order == "pop") {
			if (s.empty())
				cout << "-1\n";
			else {
				cout << s.top() << '\n';
				s.pop();
				
			}
		}
		else if (order == "size")
			cout << s.size() << '\n';

		else if (order == "empty")
			cout << s.empty() << '\n';

		else if (order == "top")
			if (s.empty())
				cout << "-1\n";
			else
				cout << s.top() << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}