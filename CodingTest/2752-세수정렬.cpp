#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[3];

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	//오름차순 정렬 1
	//sort(arr, arr + 3);
	
	//오름차순 정렬 2
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 3; j++) {
			//내림차순의 경우 arr[i] < arr[j];
			if (arr[i] > arr[j]) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (auto a : arr) {
		cout << a << ' ';
	}

	
	//순서대로 오름차순, 내림차순
	sort(begin(arr), end(arr), less<>());
	sort(begin(arr), end(arr), greater<>());
}