/*
Date : 22.12.12
Time : 
Comment : 
*/

#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

bool cmp(pair<int, int> A, pair<int, int> B) {
	if (A.first != B.first)
		return A.first < B.first;
	else
		return A.second < B.second;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int x, y;
	while (N--) {
		cin >> x >> y;
		v.push_back({ x, y });
	}
	
	sort(v.begin(), v.end(), cmp);

	for (auto a : v)
		cout << a.first << ' ' << a.second << '\n';
}