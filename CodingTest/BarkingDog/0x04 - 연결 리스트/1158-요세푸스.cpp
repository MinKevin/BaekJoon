#include <iostream>
#include <list>
using namespace std;

int main(void) {
	int N, K;

	cin >> N >> K;

	list<int> l;

	for (int i = 1; i <= N; i++) {
		l.push_back(i);
	}

	list<int>::iterator it = l.begin();
	cout << '<';
	while (l.size() != 0) {
		for (int j = 0; j < K - 1; j++) {
			it++;
			if (it == l.end())
				it = l.begin();
		}
		if (l.size() == 1)
			cout << *it << '>';
		else
			cout << *it << ", ";
		it = l.erase(it);

		if (it == l.end())
			it = l.begin();
	}
}