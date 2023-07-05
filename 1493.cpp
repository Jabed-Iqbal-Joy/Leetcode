class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int prevcnt = 0, curcnt = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                prevcnt = curcnt;
                curcnt = 0;
            }
            else
            {
                curcnt++;
            }
            ans = max(ans, prevcnt + curcnt);
        }
        ans = max(ans, prevcnt + curcnt);
        if (ans == nums.size())
            ans--;
        return ans;
    }
};