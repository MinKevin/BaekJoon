#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct A {
	int data;
	int pos;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L;

	cin >> N >> L;

	deque<A> dq;
	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		if (!dq.empty() && dq.front().pos + L == i)
			dq.pop_front();
		while (!dq.empty() && dq.back().data > arr[i])
			dq.pop_back();
		dq.push_back({ arr[i], i });

		cout << dq.front().data << ' ';
	}
}