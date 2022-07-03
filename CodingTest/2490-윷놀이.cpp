#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[2] = {0, };

	int buf;
	for (int i = 0; i < 3; i++) {
		memset(arr, 0, sizeof(arr));
		for (int j = 0; j < 4; j++) {
			cin >> buf;
			arr[buf]++;
		}

		switch (arr[0]) {
		case 0:
			cout << "E";
			break;
		case 1:
			cout << "A";
			break;
		case 2:
			cout << "B";
			break;
		case 3:
			cout << "C";
			break;
		case 4:
			cout << "D";
			break;
		}
		cout << '\n';
	}
}