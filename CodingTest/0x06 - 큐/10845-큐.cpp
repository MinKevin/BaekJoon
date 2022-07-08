#include <iostream>

using namespace std;

const int MX = 10001;

int dat[MX];
int head, tail;

void push() {
	int inp;
	cin >> inp;
	dat[tail++] = inp;
}

void pop() {
	if (tail - head == 0) {
		cout << -1 << '\n';
		return;
	}
	cout << dat[head++] << '\n';
}

void size() {
	cout << tail - head << '\n';
}

void empty() {
	if (tail - head == 0) {
		cout << 1 << '\n';
	}
	else
		cout << 0 << '\n';
}

void front() {
	if (tail - head == 0) {
		cout << -1 << '\n';
		return;
	}
	cout << dat[head] << '\n';
}

void back() {
	if (tail - head == 0) {
		cout << -1 << '\n';
		return;
	}
	cout << dat[tail - 1] << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string odr;
	while (N--) {
		cin >> odr;
		if (odr == "push")
			push();
		else if (odr == "pop")
			pop();
		else if (odr == "size")
			size();
		else if (odr == "empty")
			empty();
		else if (odr == "front")
			front();
		else if (odr == "back")
			back();
	}
}