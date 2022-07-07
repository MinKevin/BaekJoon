#include <iostream>
#include <algorithm>

using namespace std;

const int MX = 1000005;
int pre[MX];
int nxt[MX];
char dat[MX];
int unused = 1;


void DoubleLinkedList(string Inp) {
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
	for (int i = 0; i < Inp.length(); i++) {
		pre[unused] = unused - 1;
		dat[unused] = Inp[i];
		nxt[unused - 1] = unused;
		unused++;
	}
}

void traverse() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur];
		cur = nxt[cur];
	}
	cout << '\n';
}

void FunctionL(int &cur) {
	if (cur == 0)
		return;
	cur = pre[cur];
}

void FunctionD(int& cur) {
	if (nxt[cur] == -1)
		return;
	cur = nxt[cur];
}

void FunctionB(int& cur) {
	if (pre[cur] == -1)
		return;
	nxt[pre[cur]] = nxt[cur];
	if (nxt[cur] != -1)
		pre[nxt[cur]] = pre[cur];
	cur = pre[cur];
}

void FunctionP(int& cur) {
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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string Inp;
	int N, cur;

	cin >> Inp >> N;

	cur = Inp.size();

	DoubleLinkedList(Inp);

	for (int i = 0; i < N; i++) {
		char odr;
		cin >> odr;
		switch (odr) {
		case 'L':
			FunctionL(cur);
			break;
		case 'D':
			FunctionD(cur);
			break;
		case'B':
			FunctionB(cur);
			break;
		case 'P':
			FunctionP(cur);
			break;
		}

	}
	traverse();
}