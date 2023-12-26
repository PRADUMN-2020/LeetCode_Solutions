class Solution {
public:
    int M=1e9+7;
//     int helper(int n,int target, int k,vector<vector<int>>&dp)
//     {
//         if(n==0 and target)
//         {
//             return 0;
//         }
//         else if(target==0 and n)
//         {
//             return 0;
//         }
//         else if(target==0 and n==0)
//         {
//             return 1;
//         }
//         if(dp[n][target]!=-1)
//         {
//             return dp[n][target];
//         }
        
        
//     }
    int numRollsToTarget(int n, int k, int target) {
      vector<vector<int>>dp(n+1,vector<int>(target+1));
     dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int ways=0;
                for(int l=1;l<=k and l<=j;l++)
                {
                    ways=(1ll*ways+dp[i-1][j-l])%M;
                }
                dp[i][j]=ways;
            }
        }
      return dp[n][target];   
    }
};