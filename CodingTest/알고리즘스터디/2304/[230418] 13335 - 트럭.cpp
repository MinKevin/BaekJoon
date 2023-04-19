#include <iostream>
#include <queue>

using namespace std;

int n, w, L;
queue<int> imcomplete;
queue<pair<int, int>> proceeding;

int solution() {
	int t = 1;
	int onBridge = 0;
	while (!imcomplete.empty()) {
		if (!proceeding.empty() && proceeding.front().first == t) {
			onBridge -= proceeding.front().second;
			proceeding.pop();
		}
		if (imcomplete.front() + onBridge <= L) {
			onBridge += imcomplete.front();
			proceeding.push({ t + w, imcomplete.front()});
			imcomplete.pop();
		}
		t++;
	}
	while (!(proceeding.size() == 1)) {
		proceeding.pop();
	}

	return proceeding.front().first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> w >> L;
	int inp;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		imcomplete.push(inp);
	}

	cout << solution();
}