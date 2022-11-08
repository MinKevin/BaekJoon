#include <iostream>
#include <vector>

using namespace std;

int N, K;
int value[10];
int answer;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> value[i];
	}

	int cur = N - 1;
	while (K != 0) {
		answer += K / value[cur];
		K = K % value[cur];
		cur--;
	}
	cout << answer;
}