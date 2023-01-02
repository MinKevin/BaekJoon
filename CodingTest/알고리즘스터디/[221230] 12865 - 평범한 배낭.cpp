/*
Date : 22.12.30
Time : 17:32 ~ 16:43 (1h 9m)
Comment :
*/
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<pair<int, int>> v;
int answer[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	int W, V;
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		v.push_back({ W, V });
	}

	int max = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].first > K)
			continue;
		vector<pair<int, int>> answerBuf;
		for (int j = 0; j < K; j++) {
			if (answer[j] != 0) {
				int sumW = v[i].first + j;
				int sumV = v[i].second + answer[j];
				if (sumW <= K && sumV > answer[sumW]) {
					answerBuf.push_back({ sumW, sumV });
					if (sumV > max)
						max = sumV;
				}
			}
		}
		for (int k = 0; k < answerBuf.size(); k++) {
			answer[answerBuf[k].first] = answerBuf[k].second;
		}
		if (answer[v[i].first] < v[i].second) {
			answer[v[i].first] = v[i].second;
			if (max < v[i].second)
				max = v[i].second;
		}
	}

	cout << max;
}