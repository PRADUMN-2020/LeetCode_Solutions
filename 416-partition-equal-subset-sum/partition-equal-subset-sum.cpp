class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum=0;
       int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2 or n==1)
        {
            return 0;
        }
        int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=k;i++)
        {
            dp[0][i]=(nums[0]==i);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                int notTake=dp[i-1][j];
                int take=0;
                if(nums[i]<=j)
                {
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take or notTake;
            }
        }
        return dp[n-1][k];
    
    }
};