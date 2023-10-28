class Solution {
public:
    int M=1e9+7;
    int countVowelPermutation(int n) {
        vector<vector<long long>>dp(n+1,vector<long long>(5));
        for(int i=0;i<5;i++)
        {
            dp[1][i]=1;
        }
        for(int i=2;i<=n;i++)
        {
           for(int j=0;j<5;j++)
           {
               if(j==0)
               {
                   dp[i][j]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%M;
               }
               else if(j==1)
               {
                   dp[i][j]=(dp[i-1][0]+dp[i-1][2])%M;
               }
               else if(j==2)
               {
                   dp[i][j]=(dp[i-1][1]+dp[i-1][3])%M;
               }
               else if( j==3)
               {
                   dp[i][j]=dp[i-1][2];
               }
               else
               {
                   dp[i][j]=(dp[i-1][2]+dp[i-1][3])%M;
               }
           }
        }
        long long ans=0;
        for(int i=0;i<5;i++)
        {
             ans=(ans+dp[n][i])%M;
        }
        return ans;
    }
};