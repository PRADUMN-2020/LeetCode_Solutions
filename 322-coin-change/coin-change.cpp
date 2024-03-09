class Solution {
public:
    int inf=1e9;
    int helper(vector<int>&coins,int n,int amount,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(amount%coins[n]==0)
            {
                return amount/coins[n];
            }
            else
            {
                return inf;
            }
        }
        if(amount==0)
            return 0;
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        int notTake=helper(coins,n-1,amount,dp);
        int take=inf;
        if(coins[n]<=amount)
        {
            take=1+helper(coins,n,amount-(coins[n]),dp);
        }
        return dp[n][amount]=min(take,notTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        int ans=helper(coins,n-1,amount,dp);
        return ans>=inf?-1:ans;
    }
};