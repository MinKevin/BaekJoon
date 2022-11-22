//뭔가 단단히 잘못됐다...
//다시 풀지말자

#include <iostream>
#include <cmath>
using namespace std;

double x, y, z;

double binarySearch(double smallNum) {
	double st = 0;
	double end = smallNum;

	int i = 0;
	while (i++ <= 10000) {
		double base = (st + end) / 2;
		double h1 = sqrt(pow(x, 2) - pow(base, 2));
		double h2 = sqrt(pow(y, 2) - pow(base, 2));
		double expect = (h1 * h2) / (h1 + h2);
		//cout << st << ' ' << end << ' ' << base << ' ' << expect << '\n';
		if (z > expect)
			end = base;
		else
			st = base;
		/*if (expect + pow(10, -3) <= z)
			end = base - 0.0005;
		else if (expect - pow(10, -3) >= z)
			st = base + 0.0005;
		else
			return base;*/
	}
	return st;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> z;

	double bigNum = x < y ? x : y;

	cout.precision(3);
	cout << fixed;
	cout << binarySearch(bigNum);
}

/*
3000000000
3000000000
1500000000
*/

//1430.511
//908093.438