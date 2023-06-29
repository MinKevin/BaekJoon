#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>

using namespace std;

int N, M;
vector<pair<int, int>> v;
vector<int> cntEach;
int cntClass;
//mutiset은 중복을 허용하는 set
// 이문제에서는 필요가없네..?ㅋㅋ
//multiset<int, less<int>> storeStat;


bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

void input() {
	cin >> N >> M;
	v.resize(N * M);
	cntEach.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int inp;
			cin >> inp;
			v[i * M + j] = { inp, i };
		}
	}
	sort(v.begin(), v.end(), cmp);
}

bool erase(multiset<int, less<int>> &set, int target) {
	for (auto it = set.begin(); it != set.end(); it++) {
		if (*it == target) {
			set.erase(it);
			return true;
		}
	}
	return false;
}

int solution() {
	if (N == 1)
		return 0;


	int st = 0, en = 0;
	int ans = INT_MAX;
	int min = v[0].first, max = v[0].first;
	cntEach[v[0].second]++;
	cntClass = 1;

	int stat, clazz;
	while (st <= en) {
		if (cntClass < N) {
			if (++en >= N * M)
				return ans;
			
			stat = v[en].first;
			clazz = v[en].second;
			if (cntEach[clazz]++ == 0) {
				cntClass++;
			}
			max = stat;
		}
		else {//cntClass == N
			if (ans > max - min) {
				//cout << min << ' ' << max << '\n';
				//for (auto s : storeStat)
				//	cout << s << ' ';
				//cout << '\n';
				//cout << "cntClass : " << cntClass << "\n\n";
				ans = max - min;
			}

			stat = v[st].first;
			clazz = v[st].second;
			if (--cntEach[clazz] == 0) {
				cntClass--;
			}
			min = v[++st].first;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}