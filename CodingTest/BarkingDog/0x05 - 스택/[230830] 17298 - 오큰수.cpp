#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MX = 1000000;

int N;

stack<pair<int, int>> s;
int nge[MX];

void input() {
	cin >> N;
}

void solution() {
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		
		while (!s.empty() && s.top().first < num) {
			nge[s.top().second] = num;
			s.pop();
		}
		s.push({ num, i });
	}

	while (!s.empty()) {
		nge[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < N; i++)
		cout << nge[i] << ' ';

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}