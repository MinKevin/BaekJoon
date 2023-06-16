#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<string> st;
string inp;

void input() {
	cin >> inp;
}

void addToSet(int length) {
	for (int i = 0; i + length - 1< inp.size(); i++) {
		st.insert(inp.substr(i, length));
	}
}

int solution() {
	for (int i = 1; i <= inp.size(); i++) {
		addToSet(i);
	}

	return st.size();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}