#include <iostream>

using namespace std;

const int MX = 5001;
int pre[MX];
int dat[MX];
int nxt[MX];
int unused = 1;



void init(int N) {
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	for (int i = 1; i <= N; i++) {
		pre[unused] = unused - 1;
		dat[unused] = i;
		nxt[unused - 1] = unused;
		unused++;
	}
}

void next(int& cur) {
	if (nxt[cur] == -1)
		cur = nxt[0];
	else
		cur = nxt[cur];
}
void erase(int& cur) {
	nxt[pre[cur]] = nxt[cur];
	if (nxt[cur] != -1) {
		pre[nxt[cur]] = pre[cur];
		cur = nxt[cur];
	}
	else
		cur = nxt[0];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	int cur;

	cin >> N >> K;
	init(N);
	cur = 1;

	cout << '<';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K - 1; j++) {
			next(cur);
		}
		if (i == N - 1) {
			cout << dat[cur] << '>';
		}
		else
			cout << dat[cur] << ", ";
		erase(cur);
	}
}