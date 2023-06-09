#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool>knowTruth;


void input() {
	cin >> N >> M;
	knowTruth.resize(N + 1, false);

	int inp;
	cin >> inp;
	for (int i = 0; i < inp; i++) {
		int buf;
		cin >> buf;
		knowTruth[buf] = true;
	}

	for (int i = 0; i < M; i++) {
		cin >> inp;

	}
}

int solution() {

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << solution();
}