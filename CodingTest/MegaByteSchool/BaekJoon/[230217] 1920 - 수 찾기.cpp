#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int board[100000];
vector<int> ans;

int binarySearch(int target) {
	int st = 0, en = N - 1;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (board[mid] < target) {
			st = mid + 1;
		}
		else if (board[mid] > target) {
			en = mid - 1;
		}
		else
			return 1;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	sort(&board[0], &board[N], less<>());
	
	cin >> M;
	int target;
	for (int i = 0; i < M; i++) {
		cin >> target;
		ans.push_back(binarySearch(target));
	}

	for (auto v : ans)
		cout << v << '\n';
}