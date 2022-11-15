#include <iostream>
#include <vector>

using namespace std;

string inp;
string boom;

bool findDif(int i) {
	if (i + boom.size() > inp.size())
		return true;

	for (int j = 1; j < boom.size(); j++) {
		if (inp[i + j] != boom[j]) {
			return true;
			break;
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> inp >> boom;

	vector<char> v;

	for (int i = 0; i < inp.size(); i++) {
		v.push_back(inp[i]);

		if (v.size() >= boom.size()) {
			bool isDif = false;
			for (int j = 0; j < boom.size(); j++) {
				if (v[inp.size() - boom.size() + j] != boom[j]) {
					isDif = true;
					break;
				}
			}
			if (!isDif) {
				for (int j = 0; j < boom.size(); j++)
					v.pop_back();
			}
		}
	}

	if (v.size() == 0)
		cout << "FRULA";
	else {
		for (auto x : v)
			cout << x;

	}
}