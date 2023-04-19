#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, answer;
vector<int> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int buf;
		cin >> buf;
		v.push_back(buf);
	}

	sort(v.begin(), v.end());

	for (int i = v.size() - 1; i >= 0; i--) {
		if (i == 0) {
			answer += v[i];
			break;
		}

		if (v[i] * v[i - 1] <= 0) {
			if (v[i] > 0 && v[i - 1] == 0)
				answer += v[i] + v[i - 1];


			else if (v[i] == 0 && v[i - 1] < 0 && i % 2 == 1)
				i--;

			else
				answer += v[i];
		}


		else {
			if (v[i] < 0 && i % 2 == 0) {
				answer += v[i];
				continue;
			}

			else if (v[i] == 1 || v[i - 1] == 1)
				answer += v[i] + v[i - 1];
			else
				answer += v[i] * v[i - 1];
			i--;

		}

		//cout << answer << '\n';
	}

	cout << answer << '\n';

}