//뭔가 단단히 잘못됐다...
//다시 풀지말자

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double x, y, z;

double binarySearch(double smallNum) {
	double st = 0;
	double end = smallNum;

	int i = 0;
	while(st <= end){
	//while (i++ <= 10000) {
		double base = (st + end) / 2;
		double h1 = sqrt(pow(x, 2) - pow(base, 2));
		double h2 = sqrt(pow(y, 2) - pow(base, 2));
		double expect = (h1 * h2) / (h1 + h2);
		//cout << st << ' ' << end << ' ' << base << ' ' << expect << '\n';
		//if (z > expect)
		//	end = base;
		//else
		//	st = base;
		//오차범위의 값을 정확히 출력하는게 아니라 
		//precision(3)을 통해 소수점 4번째 자리에서 반올림이 진행되므로
		//구해진 값이 정확히 출력되지 않는다.
		//따라서 오차범위를 1/10만큼 더 타이트하게 잡으면 반올림 했을 때
		//원래 구하려는 값의 범위와 동일한 값을 얻을 수 있다.
		if (expect <= z - pow(10, -4))
			end = base;
		else if (expect  >= z + pow(10, -4))
			st = base;
		else
			return base;
	}
	return st;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y >> z;

	double bigNum = x < y ? x : y;
	double num = 0.0005;
	double num1 = 1.1;
	cout.precision(3);
	cout << fixed;
	cout << binarySearch(bigNum);
}

/*
3000000000
3000000000
1000000000
*/

//39.192
// 1430.??
//908093.438

//2236067977.499
//2236067977.500
//2236067840.000