#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
vector<int> fruits;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		int inp;
		cin >> inp;
		fruits.push_back(inp);
	}

	sort(fruits.begin(), fruits.end(), less<>());

	for (int i = 0; i < fruits.size(); i++) {
		if (fruits[i] <= L) 
			L++;
		else
			break;
	}

	cout << L;
}