#include <iostream>
#include <list>

using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	list<char> l;
	string inp;
	cin >> N;

	list<char>::iterator it;

	for (int i = 0; i < N; i++) {
		l.clear();
		it = l.begin();
		cin >> inp;
		
		for (int j = 0; j < inp.length(); j++) {
			switch (inp[j]) {
			case '<':
				if (it != l.begin())
					it--;
				break;

			case '>':
				if (it != l.end())
					it++;
				break;

			case '-':
				if (it != l.begin())
					it = l.erase(--it);
				break;

			default:
				l.insert(it, inp[j]);
				break;
			}
		}
		for (it = l.begin(); it != l.end(); it++) {
			cout << *it;
		}
		cout << '\n';

	}


}