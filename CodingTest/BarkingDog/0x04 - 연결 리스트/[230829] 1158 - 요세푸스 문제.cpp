#include <iostream>
#include <list>

using namespace std;

int N, K;

void input() {
	cin >> N >> K;
}

void solution() {
	cout << "<";

	list<int> lst;
	for (int i = 1; i <= N; i++)
		lst.push_back(i);

	list<int>::iterator it = lst.begin();

	while (!lst.empty()) {
		for (int i = 1; i < K; i++) {
			if (++it == lst.end())
				it = lst.begin();
		}
		if (lst.size() == 1)
			cout << *it << ">";
		else
			cout << *it << ", ";
		it = lst.erase(it);
		if (it == lst.end())
			it = lst.begin();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}