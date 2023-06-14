#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int N, M;
map<string, int, less<string>> mpByName;
vector<string> mpByNum;

void input() {
	cin >> N >> M;

	mpByNum.resize(N + 1);
	string name;
	for (int i = 1; i <= N; i++) {
		cin >> name;
		mpByName.insert(make_pair(name, i));
		mpByNum[i] = name;
	}
}


void solution() {
	vector<string> ans;
	string question;
	for (int i = 0; i < M; i++) {
		cin >> question;
		if (question[0] >= '0' && question[0] <= '9') {
			ans.push_back(mpByNum[stoi(question)]);
		}
		else {
			ans.push_back(to_string(mpByName.find(question)->second));
		}
	}

	for (auto a : ans)
		cout << a << '\n';
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();

	solution();
}