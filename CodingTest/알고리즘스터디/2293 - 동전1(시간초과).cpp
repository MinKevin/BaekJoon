//�ð��ʰ�
//O(N^N^N.....^N)�� �ڵ� ������....
//���� N�� �پ��ٰ� �ص� �ð��ʰ��� �翬�� �����Ѵ�.
//N�� �۾Ƽ� �ɸ��Ѱ�? �ߴµ�, ��� ���µ� ������
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> v;
int answer;

void func(int idx, int change) {
	if (idx == N - 1) {
		if (change % v[idx] != 0)
			return;
		else {
			answer++;
			return;
		}
	}

	int quotient = change / v[idx];
	bool haveRemainder = change % v[idx] == 0 ? false : true;

	for (int i = 0; i <= quotient; i++) {
		if (i == quotient && haveRemainder == false) {
			answer++;
			return;
		}
		func(idx + 1, change - v[idx] * i);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	
	int buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		v.push_back(buf);
	}

	sort(v.begin(), v.end(), greater<>());

	func(0, K);
	cout << answer << '\n';
}