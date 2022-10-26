#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<int>& a) {
	long long result = 0;
	for (int i = 0; i < a.size(); i++) {
		result += a[i];
	}
	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v = { 0, 1, 2, 3, 4, 5 };
	cout << v.size() << '\n';
	cout << sum(v) ;

}