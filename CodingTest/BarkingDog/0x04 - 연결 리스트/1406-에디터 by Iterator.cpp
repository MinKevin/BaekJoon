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
				//erase�� �ش� ���� ����� ���� ���� ��ġ�� ��ȯ
				cur = L.erase(--cur);
			break;
		case 'P':
			char s;
			cin >> s;
			//insert�� ���� ��ġ�� ��ȯ
			L.insert(cur, s);
			break;
		}
	}
	for (list<char>::iterator i = L.begin(); i != L.end(); i++)
		cout << *i;
}