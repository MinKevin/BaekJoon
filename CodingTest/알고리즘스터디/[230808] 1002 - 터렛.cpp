#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int T, x1, x2, yy1, y2, r1, r2;
vector<int> answer;

void input() {
	cin >> x1 >> yy1 >> r1 >> x2 >> y2 >> r2;
}

void solution() {
	while (T--) {
		input();
		double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - yy1) * (y2 - yy1));
		if (x1 == x2 and yy1 == y2 and r1 == r2)
			answer.push_back(-1);

		else if (max(r1, r2) > distance) {
			if (distance + min(r1, r2) < max(r1, r2))
				answer.push_back(0);
			else if (distance + min(r1, r2) == max(r1, r2))
				answer.push_back(1);
			else
				answer.push_back(2);
		}
		else if (max(r1, r2) == distance) {
			answer.push_back(2);
		}

		else if (max(r1, r2) < distance) {
			if (r1 + r2 > distance)
				answer.push_back(2);
			else if (r1 + r2 == distance)
				answer.push_back(1);
			else if (r1 + r2 < distance)
				answer.push_back(0);
		}
	}
	
	for (auto v : answer)
		cout << v << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	solution();
}