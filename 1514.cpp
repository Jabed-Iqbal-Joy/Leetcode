class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> g(n + 5);
        for (int i = 0; i < succProb.size(); i++)
        {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> dist(n + 5, 0);
        priority_queue<pair<double, int>, vector<pair<double, int>>> que;
        dist[start] = 1;
        que.push({1, start});
        while (!que.empty())
        {
            int cur_node = que.top().second;
            double cur_cost = que.top().first;
            que.pop();
            for (int i = 0; i < g[cur_node].size(); i++)
            {
                int dist_node = g[cur_node][i].first;
                double dist_cost = g[cur_node][i].second;
                if (cur_cost * dist_cost > dist[dist_node])
                {
                    dist[dist_node] = cur_cost * dist_cost;
                    que.push({dist[dist_node], dist_node});
                }
            }
        }
        return dist[end];
    }
};