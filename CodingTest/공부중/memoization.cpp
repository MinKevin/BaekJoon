#include <iostream>

using namespace std;

int dat[100];

int fibonacci(int x) {
	if (x <= 2)
		return 1;

	if (dat[x] != 0)
		return dat[x];

	dat[x] = fibonacci(x - 1) + fibonacci(x - 2);
	return dat[x];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


}