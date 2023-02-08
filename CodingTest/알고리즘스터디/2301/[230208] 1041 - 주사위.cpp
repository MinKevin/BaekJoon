#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#define ll long long 
using namespace std;

ll N;
ll minOneSide = INT_MAX, minTwoSide = INT_MAX, minThreeSide = INT_MAX;
vector<pair<int, int>> v = { {0, 1}, {0, 2}, {0, 3}, {0, 3}, {0, 2}, {0, 1} };


ll func() {
	ll sum;

	for (int i = 0; i < 6; i++) {
		sum = v[i].first;
		if (sum < minOneSide)
			minOneSide = sum;
		for (int j = i + 1; j < 6;  j++) {
			if (v[i].second != v[j].second) {
				sum += v[j].first;
				if (sum < minTwoSide)
					minTwoSide = sum;
				for (int k = j + 1; k < 6; k++) {
					if (v[j].second != v[k].second && v[i].second != v[k].second) {
						sum += v[k].first;
						if (sum < minThreeSide)
							minThreeSide = sum;
						sum -= v[k].first;
					}
				}
				sum -= v[j].first;
			}
		}
	}
	cout << minOneSide << ' ' << minTwoSide << ' ' << minThreeSide << '\n';
	/*
	N ^ 3개의 주사위 일 때,
	1면 => (N - 2)^2 * 5 + (N - 2) * 4;
	2면 => (N - 2) * 12 + 4;
	3면 => 4;
	*/
	sum = 0;
	int max = 0;
	if (N == 1) {
		for (int i = 0; i < 6; i++) {
			if (v[i].first > max)
				max = v[i].first;
			sum += v[i].first;
		}
		sum -= max;
		return sum;
	}

	if (N - 2 >= 0) {
		sum += minOneSide * ((N - 2) * (N - 1) * 4 + (N - 2) * (N - 2));
		sum += minTwoSide * ((N - 2) * 8 + 4);
	}
	sum += minThreeSide * 4 ;
	
	return sum;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int input;
	for (int i = 0; i < 6; i++) {
		cin >> input;
		v[i].first = input;
	}

	for (int i = 0; i < 6; i++) {
		cout << v[i].first << ", " << v[i].second << '\n';
	}

	cout << func();
}