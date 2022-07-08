#include <iostream>

using namespace std;

const int MX = 10001;
int dat[MX];
int pos = 0;

void push() {
	int buf;
	cin >> buf;
	dat[pos++] = buf;
}

void pop() {
	if (pos == 0) {
		cout << "-1\n";
		return;
	}
	cout << dat[--pos] << '\n';
}

void size() {
	cout << pos << '\n';
}

void empty() {
	if (pos == 0)
		cout << "1\n";
	else
		cout << "0\n";
}

void top() {
	if (pos == 0)
		cout << "-1\n";
	else
		cout << dat[pos - 1] << '\n';
}

int main(void) {
	int N;
	cin >> N;

	string odr;
	for (int i = 0; i < N; i++) {
		cin >> odr;

		if (odr == "push")
			push();
		else if (odr == "pop")
			pop();
		else if (odr == "size")
			size();
		else if (odr == "empty")
			empty();
		else if (odr == "top")
			top();
	}
}