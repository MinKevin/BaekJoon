#include <iostream>

using namespace std;

#define ll long long

ll Recur(ll A, ll B, ll C) {
	if (B == 1) {
		return A % C;
	}
	ll remainder = Recur(A, B / 2, C);

	if (B % 2 == 0)
		return remainder * remainder % C;
	else {

		//return remainder * remainder * A % C;
		//���� ���� �ۼ��ϸ� ������ �߻�
		//������ raminder�� �ִ밪�� int ���� �ִ밪 -1, �뷫������ 10^9�̰� �� �� ���� ���ϸ� �ּ� 10^18
		//long long�� ������ 10^18�̹Ƿ�, reaminder�� ������ A�� ���� ��� ���� Ȯ���� �����÷ο찡 �߻�
		remainder = remainder * remainder % C;
		return remainder * A % C;
	}


}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll A, B, C;
	cin >> A >> B >> C;

	cout << Recur(A, B, C);


	int N;
	for (int i = 1; i < N; i * 2) {

	}

	for (int i = 10000; i > N; i / 2) {

	}
}

