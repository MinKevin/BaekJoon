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
		//위와 같이 작성하면 에러가 발생
		//이유는 raminder의 최대값은 int 양의 최대값 -1, 대략적으로 10^9이고 이 두 수를 곱하면 최소 10^18
		//long long의 범위는 10^18이므로, reaminder의 제곱에 A를 곱할 경우 높은 확률로 오버플로우가 발생
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

