#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, ans;
vector<bool> knowTruth;
vector<vector<int>> party;
vector<bool> isPartyPossible;
queue<int> q;

void input() {
	int buf;


	cin >> N >> M;
	knowTruth.resize(N + 1, false);
	party.resize(M, vector<int>());
	isPartyPossible.resize(M, true);

	int knowTruthSize;
	cin >> knowTruthSize;
	for (int i = 0; i < knowTruthSize; i++) {
		cin >> buf;
		knowTruth[buf] = true;
		q.push(buf);
	}

	for (int i = 0; i < M; i++) {
		cin >> buf;
		for (int j = 0; j < buf; j++) {
			int buf2;
			cin >> buf2;
			party[i].push_back(buf2);
		}
	}
}

int solution() {
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < M; i++) {
			vector<int>::iterator it = find(party[i].begin(), party[i].end(), cur);		

			if (it != party[i].end()) {
				isPartyPossible[i] = false;
				for (int j = 0; j < party[i].size(); j++) {
					if (knowTruth[party[i][j]] == false) {
						knowTruth[party[i][j]] = true;
						q.push(party[i][j]);
					}
				}
			}

		}
	}
	
	for (int i = 0; i < M; i++) {
		if (isPartyPossible[i] == true)
			ans++;
	}

	return ans;
}



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}