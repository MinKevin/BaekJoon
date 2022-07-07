#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int arr[10];
	int max = 0;

	fill_n(arr, sizeof(arr)/sizeof(arr[0]), 0);
	cin >> N;

	while (N != 0) {
		arr[N % 10]++;
		N /= 10;
	}

	arr[6] += arr[9];
	arr[6] = arr[6] / 2 + arr[6] % 2;

	for (int i = 0; i < 10; i++) {
		if (arr[i] > max && i != 9)
			max = arr[i];
	}
	cout << max;

}