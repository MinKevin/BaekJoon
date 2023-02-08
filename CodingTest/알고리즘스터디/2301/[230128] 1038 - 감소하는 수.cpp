/*
9 = 1~9
1 = 10
2 = 20 21
3 = 30 31 32
4 = 40 41 42 43
5 = 
6 = 
7 = 
8 = 
9 = 
0
1
1 + 2
1 + 2 + 3

*/
#include <iostream>
#include <vector>

using namespace std;

int N;
int sum[8][10];
int board[1000001];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < 10; i++) {
		sum[1][i] = 1;
		board[i] = i;
	}

	int totalSum = 10;
	for (int i = 2; i < 8; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k < j; k++) {
				sum[i][j] += sum[i - 1][k];
			}
			totalSum += sum[i][j];
			if (totalSum >= N) {
				int dif = totalSum - N;

			}
		}
	}


}