/*

*/
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> v;
int visit[100];

void DFS(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		if (!visit[v[x][i]]) {
			visit[v[x][i]] = 1;
			DFS(v[x][i]);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	v = vector<vector<int>>(N, vector<int>());
	int input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (input == 1) {
				v[i].push_back(j);
			}
		}
	}
	int rst = 0;
	for (int i = 0; i < N; i++) {
		memset(visit, 0, sizeof(visit));
		DFS(i);
		for (int j = 0; j < N; j++) {
			cout << visit[j] << ' ';
		}
		cout << '\n';
	}
	
}