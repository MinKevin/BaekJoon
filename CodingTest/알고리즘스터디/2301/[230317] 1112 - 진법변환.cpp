#include <iostream>
#include <stack>

using namespace std;

int x, b;
stack<int> ans;

void solution() {
	if (x < 0 && b > 0) {
		cout << '-';
		x = -1 * x;
	}
	int buf = x;
	do {
		if (buf % b >= 0) {
			ans.push(buf % b);
			buf = buf / b;
		}
		else {
			ans.push(buf % b - b);
			buf = (buf - (buf % b - b)) / b;
		}
	} while (buf != 0);

	while(!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//cout << 91 % -10 << ' ' << 91 / -10;
	//cout << -91 / -10 << ' ' << -91 % -10 << '\n';
	//cout << -9 / -10 << ' ' << -9 % -10 << '\n';
	//cout << -38 / 4 << ' ' << -38 % 4 << '\n';
	
	cin >> x >> b;

	solution();

}