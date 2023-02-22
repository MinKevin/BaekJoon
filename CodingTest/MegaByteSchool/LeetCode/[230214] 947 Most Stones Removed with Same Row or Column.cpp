class Solution {
public:
    void dfs(int node, vector<vector<int>> v, vector<int>& removed) {
        removed[node] = 1;
        for (int x : v[node]) {
            if (!removed[x])
                dfs(x, v, removed);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>vis(n, 0);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfsPath(i, vis, stones, n);
            }
        }
        return n - count;
    }

    void dfsPath(int idx, vector<bool>& vis, vector<vector<int>>& stones, int& n) {
        vis[idx] = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1]) {
                    dfsPath(i, vis, stones, n);
                }
            }
        }
    }
};