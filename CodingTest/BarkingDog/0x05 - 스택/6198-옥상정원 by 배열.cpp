#include <iostream>

using namespace std;

const int MX = 80005;
int dat[MX];
int pos = 0;

int main(void) {
	int N;
	long long answer = 0;
	cin >> N;

	int buf;
	while (N--) {
		cin >> buf;
		while (pos != 0 && dat[pos - 1] <= buf) {
			pos--;

		}
		answer += pos;
		dat[pos++] = buf;
	}
	cout << answer;
}
