#include <iostream>

using namespace std;

const int MX = 10001;
int dat[2 * MX + 1];
int head = MX, tail = MX;
int inp;

void push_front() {
	cin >> inp;
	dat[--head] = inp;
}

void push_back() {
	cin >> inp;
	dat[tail++] = inp;
}

void pop_front() {
	if (tail - head == 0) {
		cout << "-1\n";
	}
	else{
		cout << dat[head++] << '\n';
	}
}

void pop_back() {
	if (tail - head == 0) {
		cout << "-1\n";
	}
	else {
		cout << dat[--tail] << '\n';
	}
}

void size() {
	cout << tail - head << '\n';
}

void empty() {
	if (tail - head == 0) {
		cout << "1\n";
	}
	else
		cout << "0\n";
}

void front() {
	if (tail - head == 0) {
		cout << "-1\n";
	}
	else
		cout << dat[head] << '\n';
}

void back() {
	if (tail - head == 0) {
		cout << "-1\n";
	}
	else
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
		if (odr == "push_front") {
			push_front();
		}
		else if (odr == "push_back") {
			push_back();
		}
		else if (odr == "pop_front") {
			pop_front();
		}
		else if (odr == "pop_back") {
			pop_back();
		}
		else if (odr == "size") {
			size();
		}
		else if (odr == "empty") {
			empty();
		}
		else if (odr == "front") {
			front();
		}
		else if (odr == "back") {
			back();
		}
	}
}