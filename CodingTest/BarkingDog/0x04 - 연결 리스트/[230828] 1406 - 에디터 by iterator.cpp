#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<char> lst;
list<char>::iterator it;

void L() {
	if (it != lst.begin())
		it--;
}

void D() {
	if (it != lst.end())
		it++;
}

void B() {
	if (it != lst.begin())
		it = lst.erase(--it);
}

void P() {
	char ch;
	cin >> ch;
	it = lst.insert(it, ch);
	it++;
}

void input() {
	string inp;
	cin >> inp;
	for (int i = 0; i < inp.size(); i++) {
		lst.push_back(inp[i]);
	}
	it = lst.end();
}

void solution() {
	int N;
	cin >> N;
	it = lst.end();

	while (N--) {
		char order;
		cin >> order;
		
		if (order == 'L')
			L();
		else if (order == 'D')
			D();
		else if (order == 'B')
			B();
		else if (order == 'P')
			P();
	}

	for (list<char>::iterator i = lst.begin(); i != lst.end(); i++)
		cout << *i;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}