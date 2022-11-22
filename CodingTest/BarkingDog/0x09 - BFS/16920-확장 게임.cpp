#include <iostream>
#include <queue>

using namespace std;

char board[1000][1000];
int arrP[10];
int N, M, P;

struct S {
	int x = 0;
};

struct compare {
	bool operator()(const S& s1, const S& s2) {
		return s1.x > s2.x;
	}
};

void Input() {
	cin >> N >> M >> P;

	for (int i = 0; i < P; i++)
		cin >> arrP[i];

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
}