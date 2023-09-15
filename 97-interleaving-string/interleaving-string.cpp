class Solution {
public:
// f(i,j) denotes that weather the remaining string 3 can be formed by interleaving of s1 i onwards and s2 j onwards.
    bool f(int i,int j, string &s1,string &s2,string &s3, int n,int m,int o, vector<vector<int>>&dp)
    {
        // Time:O(n*m), Space:O(m+n)[auxillary stack]+O(n*m)
        int k=i+j;
        if(n-i+m-j!=o-k)
        {
            return 0;
        }
        if(i==n)
        {
            int ans=1;
            for(;j<m;j++,k++)
            {
                if(s2[j]!=s3[k])
                {
                    ans=0;
                    break;
                }
            }
   
             return ans;
        }

        if(j==m)
        {
            int ans=1;
            for(;i<n;i++,k++)
            {
                if(s1[i]!=s3[k])
                {
                    ans=0;
                    break;
                }
            }
    
             return ans;
        }
        if(dp[i][j]!=-1)
        {  
            return dp[i][j];
        }
        if(s3[k]==s1[i] and s3[k]==s2[j])
        {
            return  dp[i][j]= f(i+1,j,s1,s2,s3,n,m,o,dp) or f(i,j+1,s1,s2,s3,n,m,o,dp);
        }
        else if(s3[k]==s1[i])
        {
           return  dp[i][j]=f(i+1,j,s1,s2,s3,n,m,o,dp);
        }
        else if(s3[k]==s2[j])
        {
            return  dp[i][j]= f(i,j+1,s1,s2,s3,n,m,o,dp);
        }
        else
        { 
            return  dp[i][j]=0;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int o=s3.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return f(0,0,s1,s2,s3,n,m,o,dp);
    }
};