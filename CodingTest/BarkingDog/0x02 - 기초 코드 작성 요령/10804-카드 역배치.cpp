#include <iostream>

using namespace std;

int main(void) {
	int arr[21];
	int start_num;
	int end_num;

	for (int i = 1; i <= 20; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		cin >> start_num >> end_num;
		for (int j = 0; j < (end_num + 1 - start_num) / 2; j++) {
			int buf = arr[end_num - j];
			arr[end_num - j] = arr[start_num + j];
			arr[start_num + j] = buf;
		}
	}

	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << ' ';
	}
}