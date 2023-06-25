class Solution
{
public:
  int longestArithSeqLength(vector<int> &nums)
  {
    int dp[1002][1002], ans = 0;
    for (int i = 0; i < 1002; i++)
      for (int j = 0; j < 1002; j++)
        dp[i][j] = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        int k = nums[i] - nums[j] + 500;
        dp[i][k] = max(2, dp[j][k] + 1);
        ans = max(ans, dp[i][k]);
      }
    }
    return ans;
  }
};