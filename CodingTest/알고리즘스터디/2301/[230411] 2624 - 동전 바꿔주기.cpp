#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, k;
vector<pair<int, int>> arr;
int ans;
int sum;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

void recur(int depth, int remainder) {
	if (depth == k )
		return;
	
		

	int range = min(remainder / arr[depth].first, arr[depth].second);
	for (int i = 0; i <= range; i++) {
		int buf = arr[depth].first * i;
		if (buf < remainder) {
			recur(depth + 1, remainder - buf);
			continue;
		}
		if (buf == remainder) 
			ans++;
		break;		
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T >> k;

	int p, n;
	for (int i = 0; i < k; i++) {
		cin >> p >> n;
		arr.push_back({ p, n });
	}

	sort(arr.begin(), arr.end(), cmp);

	recur(0, T);

	cout << ans;
}