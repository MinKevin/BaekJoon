#include <iostream>
#include <vector>

#define X first
#define Y second

using namespace std;

vector<pair<int, int>> adj[20005];
const int INF = 0x7FFFFFFF;
bool fix[20005];
int d[20005];
int V = 10;

void dijkstra_naive(int st) {
	fill(d, d + V + 1, INF); //�ִ� �Ÿ� ���̺� �ʱ�ȭ
	d[st] = 0;
	while (true) {
		int idx = -1;
		for (int i = 1; i <= V; i++) {
			if (fix[i]) continue;
			if (idx == -1) idx = i;
			else if (d[i] < d[idx]) idx = i;
		}
		if (idx == -1 || d[idx] == INF) //�� �̻� ������ ������ ������
			break;
		fix[idx] = 1;
		for (auto nxt : adj[idx])
			d[nxt.Y] = min(d[nxt.Y], d[idx] + nxt.X);
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	if (-1)
		cout << "minus\n" << '\n';

}