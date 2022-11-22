#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int N;
	queue<int> q;

	cin >> N;

	string odr;
	int inp;

	while (N--) {
		cin >> odr;
		if (odr == "push") {
			cin >> inp;
			q.push(inp);
		}
		else if (odr == "pop") {
			if (q.size() == 0) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (odr == "size") {
			cout << q.size() << '\n';
		}
		else if (odr == "empty") {
			cout << q.empty() << '\n';
		}
		else if (odr == "front") {
			if (q.empty() == 1) {
				cout << "-1\n";
			}
			else
				cout << q.front() << '\n';
		}
		else if (odr == "back") {
			if (q.empty() == 1) {
				cout << "-1\n";
			}
			else
				cout << q.back() << '\n';
		}
	}
}