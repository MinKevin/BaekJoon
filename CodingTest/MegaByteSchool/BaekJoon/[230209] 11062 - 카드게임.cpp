#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int T, N;
deque<int> dq;
vector<int> answer;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> T;

	while (T--) {
		cin >> N;
		int inp;
		for (int i = 0; i < N; i++) {
			cin >> inp;
			dq.push_back(inp);
		}
	}
}