#include <iostream>

using namespace std;

int N;

void func(int cnt) {
	string underBar = "";
	for (int i = 0; i < cnt; i++) {
		underBar += "____";
	}
	cout << underBar << "\"����Լ��� ������?\"\n";

	if (cnt == N) {
		cout << underBar << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		cout << underBar << "��� �亯�Ͽ���.\n";
		return;
	}
	else {
		cout << underBar << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		cout << underBar << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		cout << underBar << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	}

	func(cnt + 1);
	cout << underBar << "��� �亯�Ͽ���.\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	func(0);
}