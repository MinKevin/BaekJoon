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
		if (vis[i] != 1 && repeated[inp[i] - 'a'] == 0) {
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

		memset(vis, 0, sizeof(vis));


		sort(inp.begin(), inp.end());

		anagram(0, "", inp.length());
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}