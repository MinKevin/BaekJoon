/*
Date : 
Time : 
Comment :
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr, lis, index;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		arr.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		if (lis.size() == 0 || lis[lis.size() - 1] < arr[i]) {
			lis.push_back(arr[i]);
			index.push_back(lis.size() - 1);
		}
		else {
			int st = 0, en = lis.size() - 1;
			while (st < en) {
				int mid = (st + en) / 2;
				if (lis[mid] >= arr[i]) {
					en = mid;
				}
				else {
					st = mid + 1;
				}
			}
			lis[st] = arr[i];
			index.push_back(st);
		}
	}

	cout << lis.size() << '\n';

	vector<int> answer;
	int largest = lis.size() - 1;
	for (int i = index.size() - 1; i >= 0; i--) {
		if (index[i] == largest) {
			answer.push_back(arr[i]);
			largest--;
		}

		if (largest == -1)
			break;
	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << ' ';
	}
}