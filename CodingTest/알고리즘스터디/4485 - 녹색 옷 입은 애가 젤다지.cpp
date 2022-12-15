//Date : 22.11.27

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 0x7FFFFFFF


int N;
int board[125][125];
int dist[125][125];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<int> distance_;

void daijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(-board[0][0], make_pair(0, 0)));
    dist[0][0] = board[0][0];

    while (pq.empty() == 0)
    {
        int Cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                int nCost = Cost + board[nx][ny];
                if (dist[nx][ny] > nCost)
                {
                    dist[nx][ny] = nCost;
                    pq.push(make_pair(-dist[nx][ny], make_pair(nx, ny)));
                }
            }
        }
    }
    distance_.push_back(dist[N - 1][N - 1]);
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> N;
		
        if (N == 0) {
            for (int i = 0; i < distance_.size(); i++) {
                cout << "Problem " << (i + 1) << ": " << distance_[i] << '\n';;
            }
            break;
        }
        

		for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                dist[i][j] = INF;
                cin >> board[i][j];
            }

        daijkstra();
	}
	
}

