class Solution {
public:
    int helper(vector<int>&coins,int n,int amount,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(amount%coins[0]==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(amount==0)
        {
            return 1;
        }
        if(dp[n][amount]!=-1)
        {
            return dp[n][amount];
        }
        int notTake=helper(coins,n-1,amount,dp);
        int take=0;
        if(coins[n]<=amount)
        {
            take=helper(coins,n,amount-coins[n],dp);
        }
        return dp[n][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins,n-1,amount,dp);
    }
};