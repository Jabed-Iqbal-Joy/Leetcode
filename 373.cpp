class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        map<pair<int, int>, int> mp;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        mp[{0, 0}] = 1;
        vector<vector<int>> ans;
        for (int i = 0; i < k && !pq.empty(); i++)
        {
            auto it = pq.top().second;
            pq.pop();
            vector<int> v(2);
            v[0] = nums1[it.first];
            v[1] = nums2[it.second];
            ans.push_back(v);
            if (it.first + 1 < nums1.size())
            {
                if (mp[{it.first + 1, it.second}] == 0)
                {
                    pq.push({nums1[it.first + 1] + nums2[it.second], {it.first + 1, it.second}});
                    mp[{it.first + 1, it.second}] = 1;
                }
            }
            if (it.second + 1 < nums2.size())
            {
                if (mp[{it.first, it.second + 1}] == 0)
                {
                    pq.push({nums1[it.first] + nums2[it.second + 1], {it.first, it.second + 1}});
                    mp[{it.first, it.second + 1}] = 1;
                }
            }
        }
        return ans;
    }
};