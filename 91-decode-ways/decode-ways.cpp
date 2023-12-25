class Solution {
public:
    
    int numDecodings(string s) {
        // Time:O(n), Space:O(n)
        int n=s.size();
        vector<int>dp(2);
        dp[0]=1;
        dp[1]=s[0]!='0';
        for(int i=2;i<=n;i++)
        {
            int takeOne=0;
        if(s[i-1]!='0')
        {
            takeOne=dp[(i-1)%2];
        }
        int takeTwo=0;
        if(i-2>=0 and s[i-2]!='0')
        {
            string no="";
            no+=s[i-2];
            no+=s[i-1];
            if(stoi(no)>=1 and stoi(no)<=26)
            takeTwo=dp[(i-2)%2];
        }
        dp[i%2]=takeOne+takeTwo;
        }
         return dp[n%2];
    }
   
};