#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> S;
//홀짝, 연속된 길이
vector<pair<bool, int>> sMdf;

void input() {
	cin >> N >> K;
	S.resize(N);

	for (int i = 0; i < N; i++)
		cin >> S[i];
}

int solution() {
	//연속된 홀|짝의 개수를 새롭게 저장
	for (int i = 0; i < N; i++) {
		bool isEven = false;
		if (S[i] % 2 == 0)
			isEven = true;

		if (sMdf.empty()) {
			sMdf.push_back({ isEven, 1 });
			continue;
		}

		if (sMdf.back().first == isEven)
			sMdf.back().second++;
		else
			sMdf.push_back({ isEven, 1 });
	}

	//결과도출
	int ans = 0;
	int sumK = 0;
	int length = 0;
	int en = 0;
	for (int st = 0; st != sMdf.size(); st++) {
		while (en < sMdf.size() && sumK <= K) {
			if (sMdf[en].first == false) {
				sumK += sMdf[en].second;
			}
			else {
				length += sMdf[en].second;
			}
			en++;
		}
		if (length > ans)
			ans = length;

		if (en == sMdf.size()) {
			return ans;
		}

		if (sMdf[st].first == false)
			sumK -= sMdf[st].second;
		else {
			length -= sMdf[st].second;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}