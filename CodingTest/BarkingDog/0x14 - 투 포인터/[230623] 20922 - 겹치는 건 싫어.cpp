#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, K;
vector<int> arr;
int numCnt[100001];

void input() {
	cin >> N >> K;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int solution() {
	int ans = 0;
	int en = 0;
	//vector<int> overK;
	multiset<int> overK;
	int length = 0;
	for (int st = 0; st < N; st++) {
		while (en != N && overK.empty()) {
			length++;
			int num = arr[en++];
			if (++numCnt[num] > K)
				//overK.push_back(num);
				overK.insert(num);
			else {
				ans = max(ans, length);
				cout << "ans : " << ans << ' ' << en << '\n';
			}
		}

		length--;
		int num = arr[st];
		if (--numCnt[num] >= K) {
			/*vector<int>::iterator it = find(overK.begin(), overK.end(), num);
			overK.erase(it);*/
			overK.erase(num);
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}