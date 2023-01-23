#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

//dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 4; dp[5] = 5; dp[6] = 6; dp[7] = 9; dp[8] = 12 dp[9] = 15 dp[10] = 18 dp[11] = 27



long long dp[100];
//{사용된 buf, 3자리 전의 값}
long long func(int N) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	dp[5] = 5;
	dp[6]= 6;

	for (int i = 7; i <= N; i++) {
		for (int j = 3; j < 6; j++) {
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
		}
	}

	return dp[N];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	cout << func(N);
}