/*
Date : 22.12.21
Time : 01:50 ~ 
Comment :
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

struct comp {
	bool operator()(int a, int b) {
		return a < b;
	}
};

int N;
long long minDif = LLONG_MAX;
vector<long long> water, answer(3, 0);

void Solution() {
	for (int i = 0; i < N - 2; i++) {
		int st = i + 1, end = N - 1;
		while (st < end) {
			long long sum = water[i] + water[st] + water[end];
			if (abs(sum) < minDif) {
				minDif = abs(sum);
				answer[0] = water[i];
				answer[1] = water[st];
				answer[2] = water[end];
			}

			if (sum < 0)
				st++;
			else
				end--;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		water.push_back(input);
	}

	sort(water.begin(), water.end(), comp());

	
	Solution();

	for (auto v : answer)
		cout << v << ' ';
}