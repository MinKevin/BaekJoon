#include <iostream>
#define minDiscriminant a < b ? a : b

using namespace std;

int N, M;
int board[100];
int answer, minNum = 300000;
int func() {
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = board[i] + board[j] + board[k];
				//cout << "sum : " << sum << " " << board[i] << " " << board[j] << " " << board[k] << '\n';
				
				if (sum <= M && M - sum < minNum) {
					minNum = M - sum;
					answer = sum;
				}
			}
		}
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> board[i];

	cout << func();
}