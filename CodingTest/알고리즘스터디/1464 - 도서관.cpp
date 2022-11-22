//221108
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
int answer, cntNegative;

int func() {	
	for (int i = N - 1; i >= cntNegative; i -= M)
		answer += v[i] * 2;

	for (int i = 0; i < cntNegative; i += M)
		answer += v[i] * 2 * (-1);

	answer -= v[N - 1] > -1 * v[0] ? v[N - 1] : -1 * v[0];

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		v.push_back(buf);
		if (buf < 0)
			cntNegative++;
	}
	sort(v.begin(), v.end(), less<>());

	cout << func();
}