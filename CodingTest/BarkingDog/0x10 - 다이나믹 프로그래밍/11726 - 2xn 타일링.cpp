/*
BarkingDog 풀이 꼭 보기....
*/

#include <iostream>

using namespace std;

//n  1 2 3 4 5 6  7  8  9 
//an 1 2 3 5 8 13 21 34 55
int n;
int dp[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[n];
}