#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n;
int x;
int input[9999];
int output[9999];
int count = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	vector<int> v;
	cin >> n >> x;

	int buf;
	for (int i = 0; i < n; i++) {
		cin >> buf;
		if (buf < x) {
			v.push_back(buf);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}

}