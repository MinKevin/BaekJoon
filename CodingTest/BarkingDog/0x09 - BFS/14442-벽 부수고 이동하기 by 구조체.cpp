# include <iostream>
#include <queue>

using namespace std;

struct P {
    int r, c;       // ���� ��ġ
    int cnt = 1;    // ���ݱ��� ������ ĭ ��
    int wall = 0;   // ���ݱ��� �μ� ���� �� 
};

int N, M, K;
int Map[1001][1001];
int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };
int visited[1001][1001][11] = { 0, };

void input() {
    cin >> N >> M >> K;
    string in;
    for (int i = 0; i < N; i++) {
        cin >> in;
        for (int j = 0; j < M; j++) {
            Map[i][j] = in[j] - '0';
        }
    }
}

int BFS() {
    int result = 0;
    queue<P> que;
    P temp;
    temp.r = 0;  temp.c = 0;
    que.push(temp);

    visited[0][0][0] = 1;

    while (!que.empty()) {
        P now = que.front();
        que.pop();

        // BFS �̹Ƿ� ���� ���� ������ �����
        if (now.r == N - 1 && now.c == M - 1) return now.cnt;

        for (int i = 0; i < 4; i++) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];

            // ��ǥ�� �Ѿ�� ���
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            // �̹� �湮�� ���
            if (visited[nr][nc][now.wall]) continue;

            // ������ ���� �ƴϰ�, �湮���� �ʾҴٸ�
            if (!Map[nr][nc] && !visited[nr][nc][now.wall]) {
                visited[nr][nc][now.wall] = 1;
                que.push({ nr, nc, now.cnt + 1, now.wall });
            }
            // ������ ���̰�, ���� �ּ� �ϳ� �� �μ� �� �ְ�, �ϳ� �� �μ� ��쿡 �湮���� �ʾҴٸ�
            if (Map[nr][nc] && now.wall < K && !visited[nr][nc][now.wall + 1]) {
                visited[nr][nc][now.wall + 1] = 1;
                que.push({ nr, nc, now.cnt + 1, now.wall + 1 });
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    cout << BFS();
    return 0;
}