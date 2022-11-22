#include <iostream>

using namespace std;

int main(void) {
	int arr[26] = { 0, };

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		arr[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}
}