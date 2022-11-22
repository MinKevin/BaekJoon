#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> inp;
int answer;

bool Cmp(pair<int, int>& a, pair<int, int>& b) {
	//return a.second < b.second;
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}
bool Cmp2(pair<int, int>& a, pair<int, int>& b) {
	return a.second < b.second;
}

int func() {
	answer = 1;
	int recentEnd = inp[0].second;
	int cur = 1;
	while (cur < N) {
		while (!(inp[cur].second >= recentEnd && inp[cur].first >= recentEnd)) {
			cur++;
			if (cur >= N)
				return answer;
		}
		recentEnd = inp[cur++].second;
		answer++;
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int str, end;
	for (int i = 0; i < N; i++) {
		cin >> str >> end;
		inp.push_back({ str , end });
	}	

	//sort(inp.begin(), inp.end(), Cmp);
	sort(inp.begin(), inp.end(), Cmp2);

	/*cout << "결과 \n";
	for (auto a : inp)
		cout << a.first << ' ' << a.second << '\n';*/

	cout << func();
}