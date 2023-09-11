class Solution {
public:
// Time:O(n^2), Space:O(n)
   
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
                int mxe=0;
                int maxsum=0;
                for(int j=i;j<n and j-i+1<=k;j++)
                {
                    mxe=max(mxe,arr[j]);
                    int sum=mxe*(j-i+1)+dp[j+1];
                    maxsum=max(maxsum,sum);
                }
                dp[i]=maxsum;
        }
    return dp[0];
    }
};