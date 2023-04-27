//https://goodsosbva.tistory.com/46

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V;
vector<vector<pair<int, int>>> tree; //{target, len}
vector<bool> vis; //{길이}
void input() {
	cin >> V;
	tree.resize(V + 1, vector<pair<int, int>>());
	vis.resize(V + 1, false);

	int node;
	for (int i = 0; i < V; i++) {
		cin >> node;
		
		int target, len;
		while (true) {
			cin >> target;
			if (target == -1)
				break;
			cin >> len;
			tree[node].push_back({ target, len });
		}
	}
}

pair<int, int> dfs(int now) {
	pair<int, int> rst = make_pair(now, 0);

	for (int i = 0; i < tree[now].size(); i++) {
		int nxtNode = tree[now][i].first;
		int len = tree[now][i].second;
		if (vis[nxtNode] == false) {
			vis[nxtNode] = true;
			pair<int, int> rstBuf = dfs(nxtNode);
			rstBuf.second += len;
			if (rst.second == 0 || rst.second < rstBuf.second) {
				rst = rstBuf;
			}
		}
	}
	return rst;
}

int solution() {
	vis[1] = true;
	pair<int, int> result = dfs(1);
	//cout << result.first << ' ' << result.second << '\n';
	
	fill(vis.begin(), vis.end(), false);
	vis[result.first] = true;
	result = dfs(result.first);

	return result.second;
}



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}