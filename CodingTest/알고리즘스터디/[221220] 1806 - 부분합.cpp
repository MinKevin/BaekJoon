/*
Date : 22.12.20
Time :
Comment :
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, S;
int arr[100000];
int answer = INT_MAX;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int en = 0;
	int sum = arr[0];
	for (int st = 0; st < N - 1; st++) {
		while (en < N && sum < S) {
			sum += arr[++en];
		}
		if (en == N)
			break;

		if (answer > en - st + 1) {
			answer = en - st + 1;
		}
		sum -= arr[st];
	}
	if (answer > 100000 || answer < 0)
		cout << 0;
	else
		cout << answer;
}