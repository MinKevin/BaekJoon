/*
Date : 22.12.18
Time : 16:45 ~ 17:55
Comment : 
	
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

int N, M;
vector<pair<int, int>> chicken, home;
int vis[13];
int answer = INT_MAX;

void calculateDistance() {
	int totalDistance = 0;
	for (int i = 0; i < home.size(); i++) {
		int minDistance = 100;
		for (int j = 0; j < chicken.size(); j++) {
			if (vis[j] == 1) {
				int distance = abs(chicken[j].first - home[i].first) + abs(chicken[j].second - home[i].second);
				minDistance = minDistance > distance ? distance : minDistance;
			}
		}
		totalDistance += minDistance;
	}
	if (totalDistance < answer)
		answer = totalDistance;
}

void combination(int M, int idx) {
	if (M == 0) {
		calculateDistance();
		return;
	}

	if (idx == chicken.size())
		return;

	vis[idx] = 1;
	combination(M - 1, idx + 1);
	vis[idx] = 0;
	combination(M, idx + 1);
}



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == 1) {
				home.push_back({ i, j });
			}
			else if (input == 2) {
				chicken.push_back({ i, j });
			}
		}
	}

	combination(M, 0);

	cout << answer;
}