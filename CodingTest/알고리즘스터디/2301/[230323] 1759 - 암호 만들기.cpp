#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> vowel = { 'a', 'e', 'i', 'o', 'u' };
vector<char> character;
vector<char> ans;

void solution(int cnt, int idx, int vowelCnt, int constantCnt) {
	if (cnt == L) {

		if (vowelCnt >= 1 && constantCnt >= 2) {
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i];
			cout << '\n';
		}
		return;
	}
	//cout << vowelCnt << ' ' << constantCnt << '\n';
	bool isVowel = false;
	for (int i = idx; i < C; i++) {
		if (find(vowel.begin(), vowel.end(), character[i]) != vowel.end()) {
			isVowel = true;
			//cout << character[i] << '\n';
		}
		ans.push_back(character[i]);
		solution(cnt + 1, i + 1, vowelCnt + isVowel, constantCnt + !isVowel);
		ans.pop_back();
		isVowel = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;

	char inp;
	for (int i = 0; i < C; i++) {
		cin >> inp;
		character.push_back(inp);
	}
	sort(character.begin(), character.end(), less<>());

	solution(0, 0, 0, 0);
}