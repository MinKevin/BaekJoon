#include <iostream>

using namespace std;

int n, budget, ans;
int arr[10000];

int solution() {
	int st = 0;
	int en = budget;

	while (st <= en) {
		int mid = (st + en) / 2;

		int sum = 0;
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] <= mid) {
				sum += arr[i];
				if (arr[i] > max)
					max = arr[i];
			}
			else {
				sum += mid;
				if (mid > max)
					max = mid;
			}
				
		}

		if (sum > budget) {
			en = mid - 1;
		}
		else {
			ans = max;
			st = mid + 1;
		}
	}

	return ans;

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> budget;

	cout << solution();
}