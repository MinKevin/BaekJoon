// ( => result + 1, cnt++,  () ==> result += cnt, ) => cnt--;

#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0, cnt = 0;
	//string inp;
	char inp[100001];
	//cin >> inp;
	cin.getline(inp, 100001);

	for (int i = 0; inp[i] != '\0'; i++) {
		if (inp[i] == '(') {
			if (inp[i + 1] == ')')
				answer += cnt;
			else {
				cnt++;
				answer++;
			}
		}
		else if (inp[i] == ')' && inp[i - 1] != '(')
			cnt--;
	}
	cout << answer;
}
