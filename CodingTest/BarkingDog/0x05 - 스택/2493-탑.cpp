#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	stack<pair<int, int>> s;
	string answer = "";
	cin >> N;
	
	int buf;
	for (int i = 1; i <= N; i++) {
		cin >> buf;
		
		while (!s.empty() && s.top().second < buf) {
			s.pop();
		}
		
		if (s.empty()) {
			s.push({ i, buf });
			answer += "0 ";
		}
		else {
			answer += to_string(s.top().first) + " ";
			s.push({ i, buf });
		}
	}

	cout << answer;
}