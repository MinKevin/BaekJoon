#include <iostream>

using namespace std;

const int MX = 1251;
int dat[2 * MX + 1];
int head = MX, tail = MX;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, ans = 0;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dat[tail++] = i;
		//dat[[--head] = i;
	}

	int inp;
	int index;
	while (M--) {
		cin >> inp;
		for (int i = 0; i < tail - head; i++) {
			if (inp == dat[head + i]) {
				index = i;
				break;
			}
		}
		if (index < tail - head - index) {
			ans += index;
			while (index--) {
				dat[tail++] = dat[head++];
			}
			head++;
		}
		else {
			ans += tail - head - index;
			while (tail - head - 1 - index++) {
				dat[--head] = dat[--tail];
			}
			tail--;
		}
	}
	cout << ans;
}