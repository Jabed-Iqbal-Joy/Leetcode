class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        long long l = 0, r = 1000000, mid, c1, c2;
        while (l + 1 < r)
        {
            mid = (l + r) / 2;
            c1 = ok(mid, nums, cost);
            c2 = ok(mid + 1, nums, cost);
            // cout<<l<<' '<<r<<' '<<mid<<' '<<c1<<"-"<<c2<<endl;
            if (c1 < c2)
                r = mid;
            else
                l = mid;
        }
        // cout<<r<<endl;
        return ok(r, nums, cost);
    }
    long long ok(long long x, vector<int> &nums, vector<int> &cost)
    {
        long long cst = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cst += (long long)abs(nums[i] - x) * (long long)cost[i];
        }
        return cst;
    }
};