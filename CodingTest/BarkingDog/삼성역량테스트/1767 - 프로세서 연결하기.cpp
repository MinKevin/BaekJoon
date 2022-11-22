/////////////////////////////////////////////////////////////////////////////////////////////
// 湲곕낯 ?怨듭??? ?? ???대 愿怨 ??듬?? ?? ?異???щ㎎ 二쇱
// ?? ?以 ?異???? ??? 李멸???몄.
// ?以 ?????
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 蹂? 1媛 ??λ?? ??
// cin >> b >> c;                       // float 蹂? 2媛 ??λ?? ?? 
// cin >> d >> e >> f;                  // double 蹂? 3媛 ??λ?? ??
// cin >> g;                            // char 蹂? 1媛 ??λ?? ??
// cin >> var;                          // 臾몄??1媛 ??λ?? ??
// cin >> AB;                           // long long 蹂? 1媛 ??λ?? ??
/////////////////////////////////////////////////////////////////////////////////////////////
// ?以 異????
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 蹂? 1媛 異?ν? ??
// cout << b << " " << c;               // float 蹂? 2媛 異?ν? ??
// cout << d << " " << e << " " << f;   // double 蹂? 3媛 異?ν? ??
// cout << g;                           // char 蹂? 1媛 異?ν? ??
// cout << var;                         // 臾몄??1媛 異?ν? ??
// cout << AB;                          // long long 蹂? 1媛 異?ν? ??
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int N;
int board[12][12] = { 0, };
int vis[12][12] = { 0, };
pair<int, int> core[12];
int totalCore = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

pair<int, int> answer = { 0, 144 };
void func(int whatCore, int coreCnt, int wireCnt) {
	if (whatCore == totalCore) {
		if (coreCnt > answer.first || coreCnt == answer.first && wireCnt < answer.second) {
			answer.first = coreCnt;
			answer.second = wireCnt;
		}
		return;
	}
	int x = core[whatCore].first;
	int y = core[whatCore].second;

	bool once = false;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x; int ny = y;

		while (true) {
			nx += dx[dir]; ny += dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
				/*cout << '\n';
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						cout << vis[i][j];
					}
					cout << '\n';
				}
				cout << coreCnt + 1 << ' ' << wireCnt << '\n';*/
				once = true;
				func(whatCore + 1, coreCnt + 1, wireCnt);
				nx -= dx[dir]; ny -= dy[dir];
				while (nx != x || ny != y) {
					vis[nx][ny] = 0;
					wireCnt--;
					nx -= dx[dir]; ny -= dy[dir];
				}
				break;
			}
			else if (vis[nx][ny] == 0) {
				wireCnt++;
				vis[nx][ny] = 1;
			}
			else if (vis[nx][ny] == 1) {
				nx -= dx[dir]; ny -= dy[dir];
				while (nx != x || ny != y) {
					vis[nx][ny] = 0;
					wireCnt--;
					nx -= dx[dir]; ny -= dy[dir];
				}
				break;
			}
		}
	}
	if (x > 0 && x < N - 1 && y > 0 && y < N - 1)
		func(whatCore + 1, coreCnt, wireCnt);
	return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   ??? freopen ?⑥? input.txt 瑜?read only ???쇰? ???,
	   ??쇰? ?以 ????ㅻ낫?) ?? input.txt ??쇰?遺???쎌댁ㅺ??ㅻ ?誘몄 肄?????
	   //?щщ?????깊 肄?瑜???ㅽ?? ?, ?몄瑜???댁 input.txt? ??μ ??ν ?,
	   freopen ?⑥瑜??댁⑺硫??댄 cin ? ??? ? ?以 ????? ??쇰?遺????μ 諛???? ??듬??
	   ?곕쇱 ??ㅽ몃? ??? ??? ?? 二쇱? 吏?곌? ???⑥瑜??ъ⑺?? 醫?듬??
	   freopen ?⑥瑜??ъ⑺湲???댁? #include <cstdio>, ?뱀 #include <stdio.h> 媛 ???⑸??
	   ?? 梨?? ???肄?瑜??異?????? 諛?? freopen ?⑥瑜?吏?곌굅? 二쇱 泥由??????⑸??
	*/
	//freopen_s("input.txt", "r", stdin);
	cin >> T;
	/*
	   ?щ?媛? ??ㅽ?耳?댁ㅺ? 二쇱댁?誘濡, 媛媛? 泥由ы⑸??
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		totalCore = 0;
		answer = { 0, 144 };
		memset(vis, 0, sizeof(vis));
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
				if (board[i][j] == 1) {
					core[totalCore++] = { i, j };
					vis[i][j] = 1;
				}

			}
		}
		func(0, 0, 0);
		cout << "#" << test_case << ' ' << answer.second << '\n';
	}
	return 0;//??醫猷? 諛?? 0? 由ы댄댁쇳⑸??
}