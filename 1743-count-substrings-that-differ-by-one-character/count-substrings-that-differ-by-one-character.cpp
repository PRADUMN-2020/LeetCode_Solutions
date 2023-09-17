class Solution {
public:
    int countSubstrings(string& s, string& t) {
        // Time:O(n*m), Space:O(4*m)
        int n=s.size();
        int m=t.size();
        vector<int>longestCommonSubstrPrev(m+1),longestCommonSubstrCurr(m+1);
        vector<int>longestCommonSubstrDiffBy1Prev(m+1),longestCommonSubstrDiffBy1Curr(m+1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
        {
            longestCommonSubstrDiffBy1Curr[j]=(longestCommonSubstrDiffBy1Prev[j-1]==0)?0:(1+longestCommonSubstrDiffBy1Prev[j-1]);
                longestCommonSubstrCurr[j]=1+longestCommonSubstrPrev[j-1];
                }
                else
                {
                   longestCommonSubstrDiffBy1Curr[j]=1+longestCommonSubstrPrev[j-1];
                longestCommonSubstrCurr[j]=0; 
                }
        ans+=longestCommonSubstrDiffBy1Curr[j]>0?longestCommonSubstrDiffBy1Curr[j]-longestCommonSubstrCurr[j]:0;
            }
            longestCommonSubstrDiffBy1Prev=longestCommonSubstrDiffBy1Curr;
            longestCommonSubstrPrev=longestCommonSubstrCurr;
           
        }

return ans;
    }

};