#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
  
#define INF 0x7FFFFFFF;


int N;
int board[125][125];
int dist[125][125];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<int> answer;

struct comp{
	bool operator()(tuple<int, int, int> i, tuple<int, int, int> j) {
		return get<0>(i) > get<0>(j);
	}
};


int main(void) {
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,comp> pq;
	pq.push( {board[0][0], 0, 0 });
	dist[0][0] = board[0][0];

	while (pq.empty() == 0) {
		int cost = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) 
				continue;
			
			int nCost = cost + board[nx][ny];
			if (dist[nx][ny] > nCost) {
				dist[nx][ny] = nCost;
				pq.push({ dist[nx][ny], nx, ny });
			}
		}

	}
}