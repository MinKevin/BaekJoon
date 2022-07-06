#include <iostream>
#include <algorithm>

using namespace std;

struct comp {
	bool operator()(int const& i, int const& j) const {
		return i < j;
	}
};

int main(void) {
	int arr[9];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int begin = 0;
	int end = 8;

	sort(std::begin(arr), std::end(arr), comp());

	while (arr[begin] + arr[end] != sum - 100) {
		if (arr[begin] + arr[end] < sum - 100)
			begin++;
		else if (arr[begin] + arr[end] > sum - 100)
			end--;
	}
	

	for (int i = 0; i < 9; i++) {
		if (i == begin || i == end)
			continue;

		cout << arr[i] << '\n';
	}

}