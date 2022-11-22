#include <iostream>

using namespace std;

int func(int n, int r, int c) {
	if (n == 0) 
		return 0;

	int half = 1 << (n - 1);
	if (r < half && c < half) return func(n - 1, r, c);
	else if (r < half && c >= half) 
		return half * half * func(n - 1, r, c - half);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


}
