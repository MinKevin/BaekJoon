#include <iostream>
#include <algorithm>

using namespace std;

const int MX = 1000000;
int pre[MX];
char dat[MX];
int nxt[MX];
int cur = 0, unused = 1;


void L() {
	if (pre[cur] == -1)
		return;
	cur = pre[cur];
}

void D() {
	if (nxt[cur] == -1)
		return;
	cur = nxt[cur];
}

void B() {
	if (pre[cur] == -1)
		return;
	nxt[pre[cur]] = nxt[cur];
	if (nxt[cur] != -1)
		pre[nxt[cur]] = pre[cur];
	cur = pre[cur];
}

void P() {
	char ch;
	cin >> ch;
	dat[unused] = ch;
	pre[unused] = cur;
	nxt[unused] = nxt[cur];
	if (nxt[cur] != -1)
		pre[nxt[cur]] = unused;
	nxt[cur] = unused;
	cur = unused;
	unused++;
}

void input() {
	fill(&pre[0], &pre[MX], -1);
	fill(&nxt[0], &nxt[MX], -1);
	string Inp;
	cin >> Inp;
	for (int i = 0; i < Inp.size(); i++) {
		pre[unused] = cur;
		dat[unused] = Inp[i];
		nxt[cur] = unused;
		cur++; unused++;
	}
}

void solution() {
	int N;
	cin >> N;
	while (N--) {
		char order;
		cin >> order;
		if (order == 'L')
			L();
		else if (order == 'D')
			D();
		else if (order == 'B')
			B();
		else if (order == 'P')
			P();
	}

	cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur];
		cur = nxt[cur];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	input();

	solution();
}