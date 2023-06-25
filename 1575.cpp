class Solution
{
public:
    long long int route = 0, mod = 1e9 + 7;
    vector<vector<int>> dp;
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        int n = locations.size();
        dp.resize(locations.size(), vector<int>(fuel + 1, -1));
        return fun(locations, n, start, finish, fuel);
    }

    int fun(vector<int> &locations, int n, int index, int finish, int fuel)
    {
        if (fuel < 0)
            return 0;
        if (dp[index][fuel] != -1)
            return dp[index][fuel];
        int routes = 0 + (index == finish);
        for (int i = 0; i < n; i++)
        {
            if (i == index)
                continue;
            routes += fun(locations, n, i, finish, fuel - abs(locations[index] - locations[i]));
            routes %= mod;
        }
        return dp[index][fuel] = routes;
    }
};