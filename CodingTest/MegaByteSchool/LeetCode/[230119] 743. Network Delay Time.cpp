class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> node[n + 1];
        int value[n + 1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        fill(&value[0], &value[n + 1], INT_MAX);

        for (int i = 0; i < times.size(); i++) {
            node[times[i][0]].push_back({ times[i][1], times[i][2] });
        }

        value[k] = 0;
        pq.push({ 0, k });
        while (!pq.empty()) {
            int sumW = pq.top().first;
            int nextNode = pq.top().second;
            pq.pop();

            for (int i = 0; i < node[nextNode].size(); i++) {
                int w = node[nextNode][i].second;
                int v = node[nextNode][i].first;

                if (value[v] > sumW + w) {
                    value[v] = sumW + w;
                    pq.push({ sumW + w, v });
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (value[i] == INT_MAX)
                return -1;
            else
                if (ans < value[i]) ans = value[i];
        }
        return ans;
    }
};