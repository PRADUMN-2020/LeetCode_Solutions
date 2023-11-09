class Solution {
public:
    int M=1e9+7;
    int countHomogenous(string s) {
        long long ans=0;
        int i,j;
        i=j=0;
        int n=s.size();
        int commonLen=0;
        while(j<n)
        {
           if(s[i]==s[j])
           {
               commonLen++;
               ans=(ans+commonLen)%M;
               j++;
           }
           else
           {
               commonLen=0;
               i=j;
           }
        }
        return ans;
    }
};