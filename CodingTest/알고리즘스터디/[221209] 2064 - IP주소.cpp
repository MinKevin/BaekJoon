/*
Date : 22.12.11
Time : 약 2시간...?
Comment :
	시간줄이자고 4중for문 사용했는데, 그냥 하는게 나았으려나 싶기도하고
	익숙하지 않다보니까 머리가 잘 안굴러간다 휴....

*/

#include <iostream>
#include <string> //stoi header
#include <vector>
#include <sstream> //stringstream, getline header

using namespace std;

int n;
string str;
vector<vector<int>> ip;

vector<int> split(string input, char delimeter) {
	vector<int> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimeter)) {
		answer.push_back(stoi(temp));
	}
	return answer;
}

int threeBundle() {
	//.단위로 다른값이 있는지 확인
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < n; j++) {
			int result = ip[0][i] ^ ip[j][i];
			if (result != 0) {
				for (int k = 7; k >= 0; k--) {
					int mask = ip[0][i] & (1 << k);
					for (int l = 1; l < n; l++) {
						int buf = ip[l][i] & (1 << k);
						if (mask != buf) {
							return (8 * i) + (8 - k);
						}
					}
				}
			}
		}
	}
	return 0;
}

void answer(int position) {
	string networkAddress = "";
	string networkMask = "";
	if (position == 0) {
		int mask = (1 << 8) - 1;
		for (int i = 0; i < 4; i++) {
			networkAddress += to_string(ip[0][i]);
			networkMask += to_string(mask);
			if (i != 3) {
				networkAddress += '.';
				networkMask += '.';
			}
		}
	}
	else {
		//int mask = ~((1 << (32 + 1 - position)) - 1);
		int mask = ~((1 << (8 - (position - 1) % 8)) - 1);
		//cout << "mask : " << mask << '\n';
		for (int i = 0; i < 4; i++) {
			if (position > 8 * (i + 1)) {
				networkAddress += to_string(ip[0][i]);
				networkMask += "255";
			}
			else if (position <= 8 * i) {
				networkAddress += '0';
				networkMask += '0';
			}
			else {
				networkAddress += to_string(ip[0][i] & mask);
				networkMask += to_string((255 & mask));
			}

			if (i != 3) {
				networkAddress += '.';
				networkMask += '.';
			}
		}
	}

	cout << networkAddress << '\n' << networkMask;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	//ip주소 모두 저장
	for (int i = 0; i < n; i++) {
		cin >> str;
		ip.push_back(split(str, '.'));
	}

	int position = threeBundle();
	//cout << "position : " << position << '\n';
	answer(position);
}