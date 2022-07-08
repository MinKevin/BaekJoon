#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> s;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string odr;
		cin >> odr;
		if (odr == "push") {
			int buf;
			cin >> buf;
			s.push(buf);
		}
		else if (odr == "pop") {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else
				cout << "-1\n";
			
		}
		else if (odr == "top") {
			if (!s.empty())
				cout << s.top() << '\n';
			else
				cout << "-1\n";
		}
		else if (odr == "size") {
			cout << s.size() << '\n';
		}

		else if (odr == "empty") {
			cout << s.empty() << '\n';
		}
			
	}
}