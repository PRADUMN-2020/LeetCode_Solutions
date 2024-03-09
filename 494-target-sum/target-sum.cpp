class Solution {
public:
    int helper(vector<int>&nums,int n,int target, vector<map<int,int>>&dp)
    {
        if(n==0)
        {
            if(nums[0]==abs(target))
            {
                if(target!=0)
                    return 1;
                else return 2;
            }
            else return 0;
        }
            if(dp[n].find(target)!=dp[n].end())
        {
            return dp[n][target];
        }
        int plus=helper(nums,n-1,target-nums[n],dp);
        int minus=helper(nums,n-1,target+nums[n],dp);
         return dp[n][target]=plus+minus;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<map<int,int>>dp(n);
        return helper(nums,n-1,target,dp);
    }
};