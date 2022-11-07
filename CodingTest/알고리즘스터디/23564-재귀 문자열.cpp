#include <iostream>
#include <vector>
#include <string>

using namespace std;

string inp;
int inpLen;
vector<char> S;
vector<int> A;

void func(string x, int n) {
	int len = x.size();
	
	char s;
	int a = 0;
	int cur = len;

	if (n == 1) {
		for (int i = 0; i < inpLen; i++) {
			if (inp[i] == x[0])
				a++;
			else
				break;
		}
		S.push_back(x[0]);
		A.push_back(a);
		
		if (a == inpLen)
			return;

		func(inp.substr(0, a), n + 1);
	}

	else {
		s = inp[len];

		while (cur < inpLen) {
			if (s == inp[cur])
				a++;
			else {
				S.push_back(s);
				A.push_back(a);
				func(inp.substr(0, cur), n + 1);
				return;
			}
			cur += len + 1;
		}
		S.push_back(s);
		A.push_back(a);
		return;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> inp;
	inpLen = inp.size();
	func(inp.substr(0, 1), 1);

	for (auto x : S)
		cout << x;
	cout << '\n';
	for (auto x : A)
		cout << x << ' ';
}