#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int N, M;
int parent[1001];
double answer;
vector<pair<int, int>> coord;
vector<pair<int, int>> connect;
vector<pair<double, pair<int, int>>> edge;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		coord.push_back(make_pair(a, b));
	}


}