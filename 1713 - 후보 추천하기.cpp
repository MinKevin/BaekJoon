/*
Date : 221123
Time : 2:30
Comment : 
	sort를 통한 정렬 시에는 웬만해서는 first, second 등 모든 변인들을 원하는 순서대로 정렬해주어야함
	{1, 2}, {1, 1}, {1, 3}와 여러 인자를 가지는 vector<pair<int, int>> v를
	first를 기준으로 정렬한다고 했을 때, ({1, 2}, {1, 1}, {1, 3}은 순서대로 존재, 중간에 다른 값 존재 가능)
	위 3개의 인자만 확인했을 때, 순서대로 
	{1, 2}, {1, 1}, {1, 3}가 된다는 보장이 없다.
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N, T;

vector<tuple<int, int, int>> frame;

//int* findFrame(int number) {
//	for (auto& a : frame) {
//		if (a == number) {
//			return &a;
//		}
//	}
//	return 0;
//}

//STL (vector etc)에서 뒤에 정렬 방식 지정할 시 사용, greater, less자리
struct cmpByFst {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.first < b.first;
	}
};

struct cmpBySec {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second < b.second;
	}
};

//#include <algorthm>의 sort에 사용
bool cmpByFirst(tuple<int, int, int>& a, tuple<int, int, int>& b) {
	return get<0>(a) < get<0>(b);
}

bool cmpBySecond(tuple<int, int, int>& a, tuple<int, int, int>& b) {
	if (get<1>(a) == get<1>(b))
		return get<2>(a) < get<2>(b);
	else
		return get<1>(a) < get<1>(b);
}


vector<tuple<int, int, int>>::iterator findFrame(int number) {
	vector<tuple<int, int, int>>::iterator it;
	for (it = frame.begin(); it < frame.end(); it++) {
		if (get<0>(*it) == number)
			return it;
	}
	return frame.end();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T;

	int inp;
	for (int i = 0; i < T; i++) {
		cin >> inp;
		vector<tuple<int, int, int>>::iterator idx = findFrame(inp);
		if (idx == frame.end()) {
			if (frame.size() == N) {
				//cout << get<0>(*frame.begin()) << '\n';
				frame.erase(frame.begin());
				frame.push_back({ inp, 1, i });
			}
			else {
				frame.push_back({ inp, 1, i });
			}
		}
		else {
			tuple<int, int, int> buf = *idx;
			get<1>(buf)++;

			frame.erase(idx);
			frame.push_back(buf);
		}
		sort(frame.begin(), frame.end(), cmpBySecond);
	}

	sort(frame.begin(), frame.end(), cmpByFirst);

	for (auto v : frame)
		cout << get<0>(v) << ' ';


}