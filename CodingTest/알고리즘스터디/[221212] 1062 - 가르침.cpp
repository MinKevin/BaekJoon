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
int vis[26];
int alphabetCount = 0;
int answer;
string words[50];
string str;

int countWords() {
	int count = 0;
	for (int i = 0; i < N; i++) {
		bool isPossible = true;
		string word = words[i];
		for (int j = 0; j < word.size(); j++) {
			if (vis[word[j] - 'a'] == 0) {
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
	vis[idx] = true;
	alphabetCount++;
	if (alphabetCount == K) {
		answer = max(countWords(), answer);
	}
	else {
		for (int i = idx + 1; i < 26; i++) {
			if (!vis[i]) {
				dfs(i);
			}
		}
	}
	vis[idx] = false;
	alphabetCount--;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	vis['a' - 'a'] = true;
	vis['n' - 'a'] = true;
	vis['t' - 'a'] = true;
	vis['i' - 'a'] = true;
	vis['c' - 'a'] = true;
	alphabetCount = 5;

	for (int i = 0; i < N; i++) {
		cin >> str;
		str = str.substr(4); //4번 index부터 추출
		str = str.substr(0, str.size() - 4);
		words[i] = str;
	}

	answer = countWords();
	for (int i = 0; i < 26; i++) {
		if (vis[i] == 0)
			dfs(i);
	}
	if (K < 5) {
		answer = 0;
	}
	cout << answer;
}