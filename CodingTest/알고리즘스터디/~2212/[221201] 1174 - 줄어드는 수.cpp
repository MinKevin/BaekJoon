/*
Date : 22.12.18
Time : 15:44 ~ 16:42
Comment :
	
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N;
vector<long long> v;
void dfs(int digit, int exNum, long long sum) {
	if (digit == 0) {
		//cout << sum << ' ';
		v.push_back(sum);
		return;
	}
	for (int i = digit - 1; i < exNum; i++) {
		int sumBuf = sum;
		dfs(digit - 1, i, sum += i * pow(10, digit - 1));
		sum = sumBuf;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= 10; i++) {
		dfs(i, 10, 0);
	}
	if (N > v.size())
		cout << -1;
	else
		cout << v[N - 1] << '\n';
}