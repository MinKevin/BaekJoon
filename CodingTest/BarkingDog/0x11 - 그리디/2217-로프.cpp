#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int answer;
vector<int> v;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	
	int buf;
	for (int i = 0; i < N; i++) {
		cin >> buf;
		v.push_back(buf);
	}

	//내림차순
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < N; i++) {
		int k = i + 1;
		if (v[i] * k > answer)
			answer = v[i] * k;

		//else
		//	break;
	}

	cout << answer;

}