#include <iostream>

using namespace std;

//template<typename T>

//quick sort
void sort(int *arr, int *end) {
	int l = 0, r = (end - arr) - 1;
	if (l >= r) return;
	int mid = arr[(1 + r) / 2];

	while (l <= r) {
		while (arr[l] < mid) ++l;
		while (mid < arr[r]) --r;
		if (l <= r) {
			swap(arr[l++], arr[r--]);
		}
	}
}

int main(void) {
	int arr[5] = { 5, 3, 2, 4, 1 };

	sort(&arr[1], &arr[5]);

	//cout << *&arr[0] << '\n';
	// arr과 arr[0]의 주소값은 같다!
	//cout << *arr << '\n' << & arr[0] << '\n'; 

	for (auto a : arr) {
		cout << a << ' ';
	}

	int a = 5;
	int* b = &a;
	cout << '\n' << b << ' ' << *b << '\n';
}