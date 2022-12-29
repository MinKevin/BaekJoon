
/*
Date : 22.12.27
Time : 10:53 ~ 11:14 (23m)
Comment :
	메모이제이션 비슷한 개념
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, input, answer = 0;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back({ input, 1 });
	}

	for (int i = 0; i < v.size(); i++) {
		int maxBuf = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (v[i].first > v[j].first) {
				if (v[j].second + 1 > maxBuf)
					maxBuf = v[j].second + 1;
			}
		}
		v[i].second = maxBuf;
		//cout << v[i].first << ' ' << v[i].second << '\n';
		if (maxBuf > answer)
			answer = maxBuf;
	}
	cout << answer;
}