#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<string, string> mp;

void input() {
	cin >> N >> M;
	
	string address, pw;
	for (int i = 0; i < N; i++) {
		cin >> address >> pw;
		mp[address] = pw;
	}
}

void solution() {
	string question;
	for (int i = 0; i < M; i++) {
		cin >> question;
		cout << mp[question] << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}