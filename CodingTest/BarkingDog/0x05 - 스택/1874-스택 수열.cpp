#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string answer = "";
	stack<int> s;
	int pos = 1;
	
	cin >> N;

	int odr;
	for (int i = 0; i < N; i++) {
		cin >> odr;
		if (!s.empty() && s.top() == odr) {
			answer += "-\n";
			s.pop();
		}
		else if (pos <= odr) {
			while (pos <= odr) {
				answer += "+\n";
				s.push(pos);
				pos++;
			}
			answer += "-\n";
			s.pop();
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << answer;

}