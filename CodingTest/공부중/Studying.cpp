/*
Date : 22.12.18
Time : 16:45 ~
Comment :

*/
#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

int N, M;
vector<pair<int, int>> chicken;
vector<pair<int, int>> selectedChicken;
vector<pair<int, int>> home;
int answer = INT_MAX;
int count_ = 0;
void calculateDistance() {
	int totalDistance = 0;
	for (int i = 0; i < home.size(); i++) {
		int minDistance = 100;
		for (int j = 0; j < selectedChicken.size(); j++) {
			int distance = abs(selectedChicken[j].first - home[i].first) + abs(selectedChicken[j].second - home[i].second);
			minDistance = minDistance > distance ? distance : minDistance;
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

	for (int i = idx; i < chicken.size() - (M - 1); i++) {
		count_++;
		selectedChicken.push_back(chicken[i]);
		combination(M - 1, i + 1); //idx + 1이 아니라 i + 1임...ㅠㅠ
		selectedChicken.pop_back();
	}
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

	cout << answer << '\n';
	cout << count_;
}