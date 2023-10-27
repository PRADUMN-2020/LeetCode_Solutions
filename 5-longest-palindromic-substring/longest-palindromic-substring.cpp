class Solution {
public:
    int mx=0,st=-1;
    void evaluate(int l,int r,string &s)
    {
        int n=s.size();
        while(l>=0 and r<n and s[l]==s[r])
        {
                if(mx<r-l+1)
                {
                   mx=r-l+1;
                   st=l;
                }
                l--;
                r++;
        }
    }
    string longestPalindrome(string &s) {
        // Time:O(n^2), Space:O(1)
        int n=s.size();
       for(int i=0;i<n;i++)
       {
           evaluate(i,i,s);
           if(i+1<n)
           evaluate(i,i+1,s);
       }
        string ans=s.substr(st,mx);
    return ans;
    }
   
};