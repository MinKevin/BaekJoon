/*
Date : 22.12.19
Time : 07:43 ~
Comment :
*/

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int N, M;
int A[100000];
int st, en;
int answer = INT_MAX;

bool cmp(int a, int b) {
	return a < b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	en = N - 1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N, cmp);
	int en = 0;
	for (int st = 0; st < N; st++) {
		while (en < N && A[en] - A[st] < M)
			en++;
		if (en == M)
			break;
		answer = answer > A[en] - A[st] ? A[en] - A[st] : answer;
	}
	cout << answer;
}