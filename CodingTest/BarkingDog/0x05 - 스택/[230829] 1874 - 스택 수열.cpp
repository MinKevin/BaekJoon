#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> v;
stack<int> s;
int num = 1;
vector<char> answer;

void input() {
	cin >> N;

	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		v.push_back(inp);
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		int cur = v[i];

		while (cur >= num) {
			s.push(num++);
			answer.push_back('+');
		}
		if (s.top() == cur) {
			answer.push_back('-');
			s.pop();
		}
		else {
			cout << "NO";
			return;
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}