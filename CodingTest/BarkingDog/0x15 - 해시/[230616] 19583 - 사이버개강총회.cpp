#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, vector<bool>> mp;
string S, E, Q;
int s, e, q;

void input() {
	cin >> S >> E >> Q;
	cin.ignore();
}

int solution() {
	int ans = 0;

	S.erase(2, 1); E.erase(2, 1); Q.erase(2, 1);
	s = stoi(S); e = stoi(E); q = stoi(Q);

	string inp, Time, id;
	int time;
	while (true) {
		getline(cin, inp, '\n');
		if (inp[0] == '\0')
			break;
		Time = inp.substr(0, 5);
		id = inp.substr(6);
		Time.erase(2, 1);
		time = stoi(Time);
		if (time <= s) {
			if (mp.find(id) == mp.end()) {
				mp.insert({ id, {true, false} });
			}
		}
		else if (time >= e && time <= q) {
			if (mp.find(id) != mp.end() && mp[id][1] == false) {
				mp[id][1] = true;
				ans++;
			}
		}
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	cout << solution();
}