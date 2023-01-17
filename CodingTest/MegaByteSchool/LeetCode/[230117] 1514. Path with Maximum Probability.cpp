class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> node[10001];
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        double val[10001];
        fill(&val[0], &val[n + 1], 0);

        for (int i = 0; i < edges.size(); i++){
            int st, en;
            st = edges[i][0];
            en = edges[i][1];
            node[st].push_back({en, succProb[i]});
            node[en].push_back({st, succProb[i]});
        }

        pq.push({1, start});
        while(!pq.empty()){
            double disSum = pq.top().first;
            int loc = pq.top().second;
            pq.pop();

            if (val[loc] > disSum)
            continue;

            if (loc == end)
                return disSum;

            for (int i = 0; i < node[loc].size(); i++){
                int x = node[loc][i].first;
                double w = node[loc][i].second;

                if (val[x] < disSum * w){
                    val[x] = disSum * w;
                    pq.push({val[x], x});
                }
            }
        }
        return 0;
    }
};