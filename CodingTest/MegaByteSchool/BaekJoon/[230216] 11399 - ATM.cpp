#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		v.push_back(inp);
	}
	
	sort(v.begin(), v.end(), less<>());

	for (int i = 0; i < N; i++) {
		ans += v[i] * (N - i);
	}

	cout << ans;
}