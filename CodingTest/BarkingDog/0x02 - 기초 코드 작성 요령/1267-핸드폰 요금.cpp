#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int Y = 0, M = 0;

	int buf;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> buf;
		buf++;
		Y += (buf / 30 + (buf % 30 == 0 ? 0 : 1)) * 10;
		M += (buf / 60 + (buf % 60 == 0 ? 0 : 1)) * 15;
	}

	if (Y > M) {
		cout << "M " << M;
	}
	else if (Y == M) {
		cout << "Y M " << Y;
	}
	else {
		cout << "Y " << Y;
	}
	
}