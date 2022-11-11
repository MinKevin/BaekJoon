#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	for (int i = 0; i < 100; i++) {
		cout << i << ' ';
		if (true) {
			if (i == 10) {
				cout << "10!\n";
				break;
			}
		}
	}

}