class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        set<pair<int, int>> st;
        int i = 0, j = costs.size() - 1;
        long long ans = 0;
        for (int z = 0; z < candidates; z++, i++)
            st.insert({costs[i], i});
        for (int z = 0; z < candidates; z++, j--)
            st.insert({costs[j], j});

        for (int z = 0; z < k; z++)
        {
            auto it = *st.begin();
            st.erase(st.begin());
            ans += it.first;
            if (it.second < i && i < costs.size() && i <= j)
            {
                st.insert({costs[i], i});
                i++;
            }
            if (it.second > j && j >= 0 && i <= j)
            {
                st.insert({costs[j], j});
                j--;
            }
        }

        return ans;
    }
};