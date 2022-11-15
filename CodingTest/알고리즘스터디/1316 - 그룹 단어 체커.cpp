#include <iostream>

using namespace std;

int N;
int answer;

int func(string inp) {
	int alphabet[26] = { 0, };

	char exChar;
	for (int i = 0; i < inp.size(); i++) {
		if (alphabet[inp[i] - 'a'] != 0) {
			if (exChar == inp[i])
				alphabet[inp[i] - 'a']++;
			else
				return 0;
		}
		else {
			alphabet[inp[i] - 'a']++;
			exChar = inp[i];
		}
	}
	return 1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	string inp;
	for (int i = 0; i < N; i++) {
		cin >> inp;
		answer += func(inp);
	}
	cout << answer;

}