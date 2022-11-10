//221110
#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[200];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int max = 0;
	int maxCnt[201];
	memset(maxCnt, 0, sizeof(maxCnt));
	for (int i = 0; i < N; i++) {
		for (int j = i - 1; j >= 0; j++) {
			if (arr[i] > arr[j] && maxCnt[i] < maxCnt[j] + 1)
				maxCnt[i] = maxCnt[j] + 1;
		}
		if (max < maxCnt[i])
			max = maxCnt[i];

		if (maxCnt[i] == 0)
			maxCnt[i] = 1;
	}

	cout << N - max << '\n';
}