/*
Date : 22.12.06
Time : 1:00
Memo :
	//buf[buf.size() - 1] = '\0';
	buf.erase(buf.size() - 1);
	위와 같이 string 문자열에 '\0'를 삽입 시, 백준에서는 오류 (Visual Studio에서는 잘되긴함)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int vis[20];
string inp;
vector<string> answer;

void anagram(int idx, string buf, int length) {
	if (idx == length) {
		//cout << buf << '\n';
		answer.push_back(buf);
		return;
	}

	int repeated[26] = {0,};
	for (int i = 0; i < length; i++) {
		if (vis[i] == 0 && repeated[inp[i] - 'a'] == 0) {
			vis[i] = 1;
			repeated[inp[i] - 'a'] = 1;
			buf += inp[i];
			anagram(idx + 1, buf, length);
			//buf[buf.size() - 1] = '\0';
			buf.erase(buf.size() - 1);
			vis[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	while (N--) {
		cin >> inp;

		sort(inp.begin(), inp.end());

		anagram(0, "", inp.length());
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}