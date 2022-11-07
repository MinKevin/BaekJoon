//너무 어렵게 생각했다....
//직관적으로 보면 좋은데....
//다시생각해보니까 무조건 틀렸다.

#include <iostream>
#include <vector>

using namespace std;

vector<char> S;
vector<int> A;
pair<int, int> cur;

pair<int, int> func(string T, int depth) {
	int lenT = T.size();
	if (lenT == 1) {
		return { T[0], lenT };
	}

	int nxtLen = (lenT - 1) / 2;

	int modLen = nxtLen % 2;
	if (modLen == 1) {//X_i-1 이 홀수
		cur = func(T.substr(0, nxtLen), depth + 1);
		if (cur.first == T[nxtLen]) {
			return { T[nxtLen], cur.second * 2 + 1 };
		}
		else {
			S.push_back(cur.first);
			A.push_back(cur.second);
			return { T[nxtLen], 1 };
		}
	}
	else {//X_i-1이 짝수
		int startIndex = nxtLen - 1;
		int cnt = 0;
		for (int i = 1; i < lenT / 2; i += 2) {
			string ex = T.substr(0, nxtLen - i);
			string after = T.substr(nxtLen + i + 1, nxtLen - i);
			if (ex == after) {
				string inner = T.substr(nxtLen - i + 1, 1 + (i - 1) * 2);
				cur = func(inner, depth + 1);
				if (cur.first == T[nxtLen - i]) {
					return { T[nxtLen - i], cur.second * 3 + 2 };
				}
				else {
					S.push_back(cur.first);
					A.push_back(cur.second);
					return { T[nxtLen - i], 2 };
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string T;
	cin >> T;

	cur = func(T, 0);
	S.push_back(cur.first);
	A.push_back(cur.second);

	for (int i = 0; i < S.size(); i++) {
		cout << S[i];
	}
	cout << '\n';
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ' ';
	}
}