/*
Date : 22.12.12
Time : 08:06~
Comment :

*/
//antic

#include <iostream>
#include <math.h>

using namespace std;

int N, K;
int mask[26];
int alphabetCount = 0;
int distance_;
string words[50];
string str;

int countWords() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		bool isPossible = true;
		string word = words[i];
		for (int j = 0; j < word.size(); j++) {
			if (mask[word[j] - 'a'] == 0) {
				isPossible = false;
				break;
			}
		}
		if (isPossible == true)
			count++;
	}
	return count;
}

void dfs(int idx) {
	mask[idx] = true;
	alphabetCount++;
	if (alphabetCount == K) {
		distance_ = max(countWords(), distance_);
	}
	else {
		for (int i = idx + 1; i < 26; i++) {
			if (!mask[i]) {
				dfs(i);
			}
		}
	}
	mask[idx] = false;
	alphabetCount--;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	mask['a' - 'a'] = true;
	mask['n' - 'a'] = true;
	mask['t' - 'a'] = true;
	mask['i' - 'a'] = true;
	mask['c' - 'a'] = true;
	alphabetCount = 5;

	for (int i = 0; i < N; i++) {
		cin >> str;
		str = str.substr(4); //4번 index부터 추출
		str = str.substr(0, str.size() - 4);
		words[i] = str;
	}

	distance_ = countWords();
	for (int i = 0; i < 26; i++) {
		if (mask[i] == 0)
			dfs(i);
	}
	if (K < 5) {
		distance_ = 0;
	}
	cout << distance_;
}