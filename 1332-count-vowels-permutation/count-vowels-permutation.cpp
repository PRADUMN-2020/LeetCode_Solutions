class Solution {
public:
    int M=1e9+7;
    int countVowelPermutation(int n) {
        vector<long long>curr(5), prev(5);
        for(int i=0;i<5;i++)
        {
            prev[i]=1;
        }
        for(int i=2;i<=n;i++)
        {
           for(int j=0;j<5;j++)
           {
               if(j==0)
               {
                   curr[j]=(prev[1]+prev[2]+prev[4])%M;
               }
               else if(j==1)
               {
                   curr[j]=(prev[0]+prev[2])%M;
               }
               else if(j==2)
               {
                  curr[j]=(prev[1]+prev[3])%M;
               }
               else if( j==3)
               {
                  curr[j]=prev[2];
               }
               else
               {
                  curr[j]=(prev[2]+prev[3])%M;
               }
           }
           prev=curr;
        }
        long long ans=0;
        for(int i=0;i<5;i++)
        {
             ans=(ans+prev[i])%M;
        }
        return ans;
    }
};