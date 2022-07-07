#include <iostream>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	list<char> L;

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		L.push_back(str[i]);
	}

	int N;
	list<char>::iterator cur = L.end();

	cin >> N;

	for (int i = 0; i < N; i++) {
		char odr;
		cin >> odr;

		switch (odr) {
		case 'L':
			if (cur != L.begin())
				cur--;
			break;

		case 'D':
			if (cur != L.end())
				cur++;
			break;

		case 'B':
			if (cur != L.begin())
				//erase는 해당 값을 지우고 다음 값의 위치를 반환
				cur = L.erase(--cur);
			break;
		case 'P':
			char s;
			cin >> s;
			//insert한 값의 위치를 반환
			L.insert(cur, s);
			break;
		}
	}
	for (list<char>::iterator i = L.begin(); i != L.end(); i++)
		cout << *i;
}