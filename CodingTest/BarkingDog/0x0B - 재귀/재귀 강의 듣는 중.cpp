#include <iostream>

using namespace std;

int N = 10, sum = 0;

void Recur(int cur) {
	if (cur == 10) {
		cout << cur << ' ';
		return;
	}
	Recur(cur + 1);
	cout << cur << ' ';
}

int Sum(int cur) {
	if (cur == 10) 
		return cur;
	
	return cur + Sum(cur + 1);
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//10 ���� 1���� ���
	Recur(1);

	//1���� 10���� ���ϱ�
	cout << '\n' << Sum(1);
}