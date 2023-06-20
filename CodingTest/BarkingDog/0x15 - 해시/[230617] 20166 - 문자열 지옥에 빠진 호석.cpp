#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int N, M, K;
vector<string> board;
vector<vector<vector<map<string, int>>>> memoization;
map<string, int> totalMap;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<int> ans;

void input() {
	cin >> N >> M >> K;

	board.resize(N);
	for (int i = 0; i < N; i++)
		cin >> board[i];
}

void mergeRstMap(map<string, int>& memoMap, map<string, int> rstMap, string alphabet) {
	for (auto it = rstMap.begin(); it != rstMap.end(); it++) {
		memoMap[alphabet + it->first] += it->second;
		totalMap[alphabet + it->first] += it->second;
	}
}

map<string, int> recur(int x, int y, int length) {
	map<string, int> memoMap = memoization[length][x][y];

	if (memoMap.size() != 0)
		return memoMap;

	if (length == 1) {
		memoMap.insert({ board[x].substr(y, 1), 1 });
		memoization[length][x][y] = memoMap;
		totalMap[board[x].substr(y, 1)] += 1;

		return memoMap;
	}




	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx == -1) nx = N - 1;
		if (nx == N) nx = 0;
		if (ny == -1) ny = M - 1;
		if (ny == M) ny = 0;

		map<string, int> rstMap = recur(nx, ny, length - 1);
		/*
		char + string = >
		char은 upcasting 시 int로 변환되므로,
		char + string => int + string과 같다, 즉 'a' + "" = 97 + "" = "97"이 된다.
		*/
		mergeRstMap(memoMap, rstMap, board[x].substr(y, 1));
	}

	memoization[length][x][y] = memoMap;
	cout << memoMap.size() << '\n';
	return memoMap;
}

void solution() {

	memoization.resize(6, vector<vector<map<string, int>>>(N, vector<map<string, int>>(M, map<string, int>())));

	/*
	아래 2가지의 fill 중
	첫번째 fill의 경우는 배열에서 사용할 수 있는 방식이다. vector에서는 이와같은 방식은 사용이 불가능하다.
	두번째 fill의 경우는 vector에서 사용하는 방식이다. 지금까지 간과하고 있던 방식이므로, 꼭 기억하도록하자.
	*/

	//fill(&memoization[0][0][0], &memoization[0][N - 1][M], 1);
	//fill(memoization[1].begin(), memoization[1].end(), vector<map<string, int>>(M, map<string, int>({ make_pair("make_size_1", 1) })));


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			memoization[5][i][j] = recur(i, j, 5);
		}

	string str;
	for (int i = 0; i < K; i++) {
		cin >> str;
		if (totalMap.find(str) != totalMap.end())
			ans.push_back(totalMap[str]);
		else
			ans.push_back(0);
	}


	for (auto v : ans)
		cout << v << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}