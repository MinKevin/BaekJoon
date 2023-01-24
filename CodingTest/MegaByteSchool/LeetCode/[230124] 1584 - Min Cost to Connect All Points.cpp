class Solution {
public:
    vector<int> parent;

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<pair<int, pair<int, int>>> v;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                v.push_back({ abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j} });
            }
        }
        parent.resize(points.size());
        for (int i = 0; i < points.size(); i++)
            parent[i] = i;
        sort(v.begin(), v.end(), less<>());

        int ans = 0;
        for (int i = 0; i < v.size(); i++) {
            if (sameParent(v[i].second.first, v[i].second.second) == false) {
                union_(v[i].second.first, v[i].second.second);
                ans += v[i].first;
            }
        }

        return ans;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = find(parent[x]);
    }

    bool sameParent(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return true;
        else
            return false;
    }

    void union_(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y)
            parent[y] = x;
    }
};