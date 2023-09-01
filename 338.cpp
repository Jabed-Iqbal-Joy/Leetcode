class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        ans.push_back(0);
        if (n == 0)
            return ans;
        ans.push_back(1);
        if (n == 1)
            return ans;
        int i, j;
        for (i = 2, j = 1; i + 1 <= n; i += 2, j++)
        {
            ans.push_back(ans[j]);
            ans.push_back(ans[j] + 1);
        }
        if (ans.size() != n + 1)
            ans.push_back(ans[j]);
        return ans;
    }
};
