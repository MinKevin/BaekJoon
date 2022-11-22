#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> dq;
	int N;
	cin >> N;

	string odr;
	int inp;
	while (N--) {
		cin >> odr;
		if (odr == "push_front") {
			cin >> inp;
			dq.push_front(inp);
		}
		else if (odr == "push_back") {
			cin >> inp;
			dq.push_back(inp);
		}
		else if (odr == "pop_front") {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			
		}
		else if (odr == "pop_back") {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (odr == "size") {
			cout << dq.size() << '\n';
		}
		else if (odr == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (odr == "front") {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (odr == "back") {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.back() << '\n';
			}
		}
	}

}