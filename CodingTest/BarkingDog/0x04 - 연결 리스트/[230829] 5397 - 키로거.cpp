#include <iostream>
#include <list>

using namespace std;

int T;
string L;
list<char> lst;
list<char>::iterator it;

void left() {
	if (it != lst.begin())
		it--;
}

void right() {
	if (it != lst.end())
		it++;
}

void backSpace() {
	if (it != lst.begin()) {
		it--;
		it = lst.erase(it);
	}
		
}

void input() {
	cin >> T;
}

void solution() {
	while (T--) {
		cin >> L;
		lst.clear();
		it = lst.begin();

		for (int i = 0; i < L.size(); i++) {
			if (L[i] == '<')
				left();
			else if (L[i] == '>')
				right();
			else if (L[i] == '-')
				backSpace();
			else {
				it = lst.insert(it, L[i]);
				it++;
			}
		}

		for (list<char>::iterator i = lst.begin(); i != lst.end(); i++)
			cout << *i;
		cout << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}