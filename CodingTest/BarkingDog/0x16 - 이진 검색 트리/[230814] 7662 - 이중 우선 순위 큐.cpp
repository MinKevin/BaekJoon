#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int T, k;

void solution() {
	string order;
	int orderNum;
	multiset<int, greater<int>> s;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> order >> orderNum;
		if (order == "I")
			s.insert(orderNum);
		else if (order == "D") {
			if(orderNum == -1) {
				if (!s.empty())
					s.erase(--s.end());
			}
			else if (orderNum == 1) {
				if (!s.empty())
					s.erase(s.begin());
			}
		}
	}


	if (s.empty())
		cout << "EMPTY\n";
	else
		cout << *s.begin() << ' ' << *(--s.end()) << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		solution();
	}
}