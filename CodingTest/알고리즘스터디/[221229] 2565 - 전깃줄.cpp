/*
Date : 22.12.29
Time : 16:00
Comment : 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;
	}
};

int N, answer;
vector<pair<int, int>> v;
vector<int> arr, lis, index;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), cmp());

	for (int i = 0; i < v.size(); i++) {
		arr.push_back(v[i].second);
	}

	for (int i = 0; i < arr.size(); i++) {
		if (lis.size() == 0 || lis[lis.size() - 1] < arr[i]) {
			lis.push_back(arr[i]);
			index.push_back(lis.size() - 1);
		}
		else {
			int st = 0, en = lis.size() - 1;
			while (st <= en) {
				int mid = (st + en) / 2;
				if (lis[mid] >= arr[i]) {
					en = mid - 1;
				}
				else {
					st = mid + 1;
				}
			}
			lis[st] = arr[i];
			index.push_back(st);
		}
	}

	cout << N - lis.size() << '\n';

	vector<int> answer;
	int max = lis.size() - 1;
	for (int i = index.size() - 1; i >= 0; i--) {
		if (index[i] == max) {
			answer.push_back(arr[i]);
			max--;
		}
		if (max == -1)
			break;
	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << ' ';
	}
}
