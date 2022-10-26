#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;
vector<int> v;

void input() {
	cin >> n;
	v.resize(n);
	for (int& k : v) 
		cin >> k;
	cin >> x;
	sort(v.begin(), v.end());
}

void sol() {
	int cnt = 0, sum = 0, lo = 0, hi = n - 1;
	while (lo < hi) {
		sum = v[lo] + v[hi];
		
		if (sum < x)
			lo++;
		else if (sum > x)
			hi--;
		else {
			cnt++;
			lo++;
			hi--;
		}
	}
	cout << cnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();
	sol();
}