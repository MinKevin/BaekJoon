//221109
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	int buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		v.push_back(buf);
	}
	vector<int> memoization(K + 1, 0);
	memoization[0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= K; j++) {
			memoization[j] += memoization[j - v[i]];
		}
	}


	cout << memoization[K];
}