class Solution {
public:
    // dp[i][d]: longest arithmatic subsequence ending at i with common difference d.
    int longestArithSeqLength(vector<int>& nums) {
        // Time:O(n^2), Space:O(n*1000)
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                int d=nums[i]-nums[prev];
                dp[i][d]=max(dp[i][d], (dp[prev][d]==0?1:dp[prev][d])+1);
                ans=max(ans,dp[i][d]);
            }
        }
        return ans;
        
    }
};