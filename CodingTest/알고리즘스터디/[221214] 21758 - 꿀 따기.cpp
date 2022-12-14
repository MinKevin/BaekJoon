/*
Date : 22.12.14
Time : 11:18~
Comment :

*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> memoization;

int func() {
	int answer = 0;
	//제일 오른쪽 꿀
	int startPoint = memoization[0] - v[0];
	for (int i = 1; i < N - 1; i++) {
		if (startPoint + memoization[i] - v[i] * 2 > answer)
			answer = startPoint + memoization[i] - v[i] * 2;
	}
	//제일 왼쪽 꿀
	startPoint = memoization[0] - v[N - 1];
	for (int i = N - 2; i > 0; i--) {
		if (startPoint + memoization[0] - memoization[i] - v[i] > answer) {
			answer = startPoint + memoization[0] - memoization[i] - v[i];
			cout << startPoint << ' ' << memoization[0] - memoization[i] - v[i] << '\n';
		}
		
	}

	//꿀이 가운데
	for (int i = 1; i < N - 1; i++) {
		if ((memoization[0] - v[0] - memoization[i + 1]) + (memoization[i] - v[N - 1]) > answer)
			answer = (memoization[0] - v[0] - memoization[i + 1]) + (memoization[i] - v[N - 1]);
		//cout << (memoization[0] - v[0] - memoization[i + 1]) << ' ' << (memoization[i] - v[N - 1]) <<'\n';
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int buf;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		sum += buf;
		v.push_back(buf);
	}
	memoization = vector<int>(N, 0);

	buf = 0;
	for (int i = N - 1; i >= 0; i--) {
		buf += v[i];
		memoization[i] = buf;
	}

	cout << func();
}