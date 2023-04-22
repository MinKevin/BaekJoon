#include <iostream>
#include <vector>

using namespace std;

int T, k;
vector<vector<int>> v;
int* ptr[10001];

int solution() {

	return 0;
}
int arr[100][100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T >> k;

	v.resize(k + 1, vector<int>(T + 1, -1));

	int p, n;
	for (int i = 0; i < k; i++) {
		cin >> p >> n;
		ptr[p] = &v[i + 1][0];
		for (int j = 1; j <= n; j++) {
			v[i + 1][p * j] = 1;		
		}
	}
	
	cout << solution();
}