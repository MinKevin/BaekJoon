#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[26];
	fill(arr, arr + 26, 0);

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - 'a']++;
	}

	cin >> str;

	for (int i = 0; i < str.length(); i++)
		arr[str[i] - 'a']--;

	int sum = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] < 0)
			sum -= arr[i];
		else if (arr[i] > 0)
			sum += arr[i];
	}
	cout << sum;
}