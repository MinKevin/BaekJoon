#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;
int A[50];
int B[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
		cin >> B[i];

	sort(A, &A[N]);
	sort(B, &B[N], greater<>());

	for (int i = 0; i < N; i++)
		answer += A[i] * B[i];

	cout << answer;
}