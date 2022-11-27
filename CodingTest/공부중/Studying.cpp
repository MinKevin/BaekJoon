#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m;

int map[102][102];
int isVisited[102][102];

pair<int, int> evenNear[6] = { {0,-1},{0,1},{1,-1},{1,0},{-1,-1},{-1,0} };
pair<int, int> oddNear[6] = { {0,-1},{0,1},{1,1},{1,0},{-1,1},{-1,0} };

int isInScope(int i, int j) {
    return (i >= 1 && i <= n && j >= 1 && j <= m);
}
int isOnBorder(int i, int j) {
    return (i == 1 || i == n || j == 1 || j == m);
}

int isSurrounded(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    isVisited[x][y] = 1;

    while (!q.empty()) {
        int frontX = q.front().first, frontY = q.front().second;
        q.pop();


        for (int i = 0; i < 6; i++) {
            int newX = (frontX + ((frontX % 2 == 0) ? evenNear[i].first : oddNear[i].first));
            int newY = (frontY + ((frontX % 2 == 0) ? evenNear[i].second : oddNear[i].second));

            if (!isVisited[newX][newY] && map[newX][newY] == 0) {
                if (isOnBorder(newX, newY)) {
                    memset(isVisited, 0, sizeof(isVisited));
                    return 0;
                };
                q.push({ newX,newY });
                isVisited[newX][newY] = 1;
            }
        }
    }

    memset(isVisited, 0, sizeof(isVisited));
    return 1;

}

int bfs(int x, int y) {
    int perimeter = 0;
    queue<pair<int, int>> q;

    q.push({ x,y });
    isVisited[x][y] = 1;


    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        int i = front.first, j = front.second;
        // printf("%d %d\n",i,j);
        perimeter += 6;


        if (map[i][j - 1]) {
            perimeter--;
            if (!isVisited[i][j - 1]) {
                isVisited[i][j - 1] = 1;
                q.push({ i,j - 1 });
            }
        }
        if (map[i][j + 1]) {
            perimeter--;
            if (!isVisited[i][j + 1]) {
                isVisited[i][j + 1] = 1;
                q.push({ i,j + 1 });
            }
        }
        if (map[i - 1][j]) {
            perimeter--;
            if (!isVisited[i - 1][j]) {
                isVisited[i - 1][j] = 1;
                q.push({ i - 1,j });
            }
        }
        if (map[i + 1][j]) {
            perimeter--;
            if (!isVisited[i + 1][j]) {
                isVisited[i + 1][j] = 1;
                q.push({ i + 1,j });
            }
        }
        if (i % 2 == 0) {
            if (map[i - 1][j - 1]) {
                perimeter--;
                if (!isVisited[i - 1][j - 1]) {
                    isVisited[i - 1][j - 1] = 1;
                    q.push({ i - 1,j - 1 });
                }
            }
            if (map[i + 1][j - 1]) {
                perimeter--;
                if (!isVisited[i + 1][j - 1]) {
                    isVisited[i + 1][j - 1] = 1;
                    q.push({ i + 1,j - 1 });
                }
            }

        }
        else {
            if (map[i - 1][j + 1]) {
                perimeter--;
                if (!isVisited[i - 1][j + 1]) {
                    isVisited[i - 1][j + 1] = 1;
                    q.push({ i - 1,j + 1 });
                }
            }
            if (map[i + 1][j + 1]) {
                perimeter--;
                if (!isVisited[i + 1][j + 1]) {
                    isVisited[i + 1][j + 1] = 1;
                    q.push({ i + 1,j + 1 });
                }
            }
        }



    }
    return perimeter;
}

int checkSurrounded(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    isVisited[x][y] = 1;

    while (!q.empty()) {
        int frontX = q.front().first, frontY = q.front().second;
        q.pop();
        map[frontX][frontY] = 1;


        for (int i = 0; i < 6; i++) {
            int newX = frontX + ((frontX % 2 == 0) ? evenNear[i].first : oddNear[i].first);
            int newY = frontY + ((frontX % 2 == 0) ? evenNear[i].second : oddNear[i].second);

            if (!isVisited[newX][newY] && map[newX][newY] == 0) {
                q.push({ newX,newY });
                isVisited[newX][newY] = 1;
            }
        }
    }
    memset(isVisited, 0, sizeof(isVisited));

    return 0;
}

int main()
{
    int totalPerimeter = 0;
    scanf_s("%d %d", &m, &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf_s("%d", &map[i][j]);
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 0 && isSurrounded(i, j)) {
                checkSurrounded(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!isVisited[i][j] && map[i][j]) {
                int buf = bfs(i, j);
                //cout << buf << '\n';
                totalPerimeter += buf;
            }

        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%d ",map[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("\n\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    printf("%d\n", totalPerimeter);


    return 0;
}