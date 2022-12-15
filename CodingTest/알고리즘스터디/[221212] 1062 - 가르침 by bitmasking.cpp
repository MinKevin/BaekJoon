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
int mask;
int alphabetCount = 0;
int answer;
int words[50];
string str;

int alphabet = 0;

int countWords() {
	int count = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		int word = words[i];
		int maskBuf = mask;
		bool isPossible = true;
		while (word != 0) {
			if ((word & 1) != 0) {
				if ((maskBuf & 1) == 0) {
					isPossible = false;
					break;
				}
			}
			word = word >> 1;
			maskBuf = maskBuf >> 1;
		}
		if (isPossible == true)
			count++;
	}
	return count;
}

void dfs(int idx) {
	if (alphabetCount == K) {
		answer = max(countWords(), answer);
		return;
	}
	for (int i = idx; i < 26; i++) {
		if ((mask & 1 << i) == 0) { //비교 연산자는 비트연산자보다 우선순위가 높다.
			alphabet = i;
			mask = mask | 1 << i;
			alphabetCount++;
			dfs(i + 1);
			//cout << "exMask : " << mask << ' ';
			//cout << "i : " << i << ' ';
			mask = mask & ~(1 << i);
			//cout << "afterMask : " << mask << '\n';
			alphabetCount--;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	mask = mask | 1 << ('a' - 'a');
	mask = mask | 1 << ('n' - 'a');
	mask = mask | 1 << ('t' - 'a');
	mask = mask | 1 << ('i' - 'a');
	mask = mask | 1 << ('c' - 'a');
	alphabetCount = 5;

	for (int i = 0; i < N; i++) {
		cin >> str;
		str = str.substr(4); //4번 index부터 출력
		str = str.substr(0, str.size() - 4);
		for (int j = 0; j < str.length(); j++) {
			words[i] = words[i] | 1 << (str[j] - 'a');
		}
	}

	if (K < 5) {
		cout << 0;
		return 0;
	}

	//answer = countWords();

	dfs(0);

	cout << answer;
}