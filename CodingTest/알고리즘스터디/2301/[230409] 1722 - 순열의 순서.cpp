#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int type;
long long k;
vector<int> inp;
int cnt = 0;

void type1() {
	if (N == 1) {
		cout << 1 << '\n';
		return;
	}


	long long buf = 1;
	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		buf *= i;
	}
	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	deque<int>::iterator it;
	
	int loc = 0;
	while (true) {
		long long quotient, remainder;
		quotient = k / buf;
		remainder = k % buf;
		
		if (remainder == 0) {
			if (loc != 0) {
				ans.push_back(dq[quotient - 1]);
				dq.erase(dq.begin() + quotient - 1);
			}
			while (!dq.empty()) {
				ans.push_back(dq.back());
				dq.pop_back();
			}
			break;
		}
		else if (remainder != 0 && loc != 0) {
			ans.push_back(dq[quotient]);
			dq.erase(dq.begin() + quotient);
		}
		buf /= N - loc;
		loc++;
		k = remainder;
	}

	for (auto v : ans)
		cout << v << ' ';

}

long long type2() {
	long long buf = 1;
	long long ans = 1;
	for (int i = 1; i < N; i++) {
		buf *= i;
	}
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	vector<int>::iterator it;
	
	int loc = 0;
	while (true) {
		it = find(v.begin(), v.end(), inp[loc]);

		ans += buf * (it - v.begin());
		v.erase(it);

		loc++;
		if (loc == N)
			break;
		buf /= N - loc;
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> type;

	if (type == 1) {
			cin >> k;
			type1();
	}
	else {
		int buf;
		for (int i = 0; i < N; i++) {
			cin >> buf;
			inp.push_back(buf);
		}
		cout << type2();
	}
}