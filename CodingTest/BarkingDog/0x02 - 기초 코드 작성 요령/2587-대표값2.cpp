#include <iostream>
#include <algorithm>

using namespace std;

struct comp {
	bool operator()(int const& i, int const& j) const {
		return i > j;
	}
};

int main(void) {

	int arr[5];
	int average = 0; 

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		average += arr[i];
	}

	average /= 5;

	sort(begin(arr), end(arr), comp());

	cout << average <<'\n';
	cout << arr[2] << '\n';
}