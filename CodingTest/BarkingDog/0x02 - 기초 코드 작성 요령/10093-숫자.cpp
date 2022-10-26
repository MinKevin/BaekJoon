#include <iostream>

using namespace std;

int main(void) {
	long long start_num, end_num;

	cin >> start_num >> end_num;

	if (start_num == end_num) {
		cout << 0;
		return 0;
	}

	if (start_num > end_num) {
		long long buf = start_num;
		start_num = end_num;
		end_num = buf;
	}

	cout << end_num - start_num - 1 << '\n';

	for (long long i = start_num + 1; i < end_num; i++) {
		cout << i << ' ';
	} 
}