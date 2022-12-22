#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> Tk;
long long maxT;

void Solution() {
	long long st = 0, en = maxT * M;
	long long answer;
	while (st <= en) {
		long long mid = (st + en) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += mid / Tk[i];
		}
		//1.sum == M 인 경우의 최솟값
		if (sum < M) {
			st = mid + 1;
		}
		else {
			answer = mid;
			en = mid - 1;
		}
		
		//2.sum == M 인 경우의 최댓값
		//if (sum > M) {
		//	en = mid - 1;
		//}
		//else {
		//  answer = st;
		//	st = mid + 1;
		//}
	}
	cout << st;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		Tk.push_back(input);
		if (input > maxT)
			maxT = input;
	}

	Solution();
}