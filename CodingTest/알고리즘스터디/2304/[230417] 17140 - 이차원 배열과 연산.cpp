#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int r, c, k;
int arr[100][100];


int recur(int x, int y, int t) {
	if (t == 101)
		return -1;

	map<int, int> mp;
	int maxLoc = 0;
	for (int i = 0; i < (x >= y ? x : y); i++) {
		mp.clear();
		for (int j = 0; j < (x >= y ? y : x); j++) {
			int val;
			if (x >= y)
				val = arr[i][j];
			else
				val = arr[j][i];
			if (val == 0)
				continue;

			if (mp.find(val) == mp.end()) {
				mp.insert({ val, 1 });
			}
			else {
				mp[val]++;
			}
		}
		vector<pair<int, int>> v(mp.begin(), mp.end());
		sort(v.begin(), v.end(), cmp);

		int loc = 0;
		for (auto m : v) {
			if (loc == 100) {
				loc = 99;
				break;
			}
			if (x >= y) {
				arr[i][loc++] = m.first;
				arr[i][loc++] = m.second;
			}
			else {
				arr[loc++][i] = m.first;
				arr[loc++][i] = m.second;
			}
		}
		for (int k = loc; k < (x >= y ? y : x); k++) {
			int *val = &(x >= y ? arr[i][k] : arr[k][i]);
			if (*val != 0)
				*val = 0;
		}
		if (loc > maxLoc)
			maxLoc = loc;
	}

	//cout << '\n';
	//for (int i = 0; i < 10; i++) {
	//	for (int j = 0; j < 10; j++) {
	//		if (arr[i][j] != 0)
	//			cout << arr[i][j] << ' ';
	//		else
	//			cout << "  ";
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';

	if (arr[r - 1][c - 1] == k) {
		return t;
	}

	return x >= y ? recur(x, maxLoc, t + 1) : recur(maxLoc, y, t + 1);	
}

int solution() {
	if (arr[r - 1][c - 1] == k)
		return 0;
	return recur(3, 3, 1);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	cout << solution();
}