#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<int> primeNumber;
vector<int> v;
void input() {
	cin >> N;
	v.resize(N + 1, -1);
}

int solution() {
	if (N == 1)
		return 0;

	for (int i = 2; i <= N; i++) {
		if (v[i] != -1)
			continue;
		primeNumber.push_back(i);
		int j = 1;
		while (i * j <= N) {
			v[i * j++] = 1;
		}
	}
	int en = 0;
	int sum = 0;
	for (int st = 0; st < primeNumber.size(); st++) {
		while (en != primeNumber.size() && sum < N) {
			sum += primeNumber[en++];
		}
		if (sum == N)
			ans++;
		sum -= primeNumber[st];
	}

	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  

	input();

	cout << solution();

}