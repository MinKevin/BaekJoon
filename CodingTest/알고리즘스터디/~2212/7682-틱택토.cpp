//221101
//백트래킹
#include <iostream>
#include <string>
using namespace std;

string inp = "";
bool answer;
bool findOLine = false;
bool findXLine = false;

void Check() {
	//대각선1
	char ansChar;

	ansChar = inp[0];
	if (ansChar != '.' && ansChar == inp[4] && ansChar == inp[8]) {
		//cout << "대각선1";
		if (ansChar == 'X')
			findXLine = true;
		else
			findOLine = true;
	}
	//대각선2
	ansChar = inp[2];
	if (ansChar != '.' && ansChar == inp[4] && ansChar == inp[6]) {
		//cout << "대각선2";
		if (ansChar == 'X')
			findXLine = true;
		else
			findOLine = true;
	}
	//행
	for (int i = 0; i < 9; i += 3) {
		ansChar = inp[i];
		if (ansChar != '.' && ansChar == inp[i + 1] && ansChar == inp[i + 2]) {
			//cout << "행";
			if (ansChar == 'X')
				findXLine = true;
			else
				findOLine = true;
		}
	} 
	//열
	for (int i = 0; i < 3; i++) {
		ansChar = inp[i];
		if (ansChar != '.' && ansChar == inp[i + 3] && ansChar == inp[i + 6]) {
			//cout << "열";
			if (ansChar == 'X')
				findXLine = true;
			else
				findOLine = true;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		findXLine = false;
		findOLine = false;
		cin >> inp;

		if (inp == "end")
			break;

		int cntX = 0, cntO = 0;
		for (int i = 0; i < inp.size(); i++) {
			if (inp[i] == 'X')
				cntX++;
			else if (inp[i] == 'O')
				cntO++;
		}
		  
		//https://lollolzkk.tistory.com/12
		int locDot = inp.find('.');
		if (locDot != string::npos) {//find 함수는 targetChar이 존재 하지 않으면 쓰레기 값(string::npos)를 return (NULL이 아님)
			Check();
			if (cntX == cntO && findXLine == false && findOLine == true)
				answer = true;
			else if (cntX == cntO + 1 && findXLine == true && findOLine == false)
				answer = true;
			else
				answer = false;
		}
		else {
			if (cntX == cntO + 1) {
				Check();
				if (findOLine == false)
					answer = true;
				else
					answer = false;
			}
			else
				answer = false;
		}

		if (answer == true)
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
}