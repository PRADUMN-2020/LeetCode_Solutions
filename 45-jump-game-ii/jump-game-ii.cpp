class Solution {
public:
    
    int jump(vector<int>& nums) {
        //Time:O(1000*n), space:O(n)
        int n=nums.size();
        vector<int>dp(n);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
        int mn=n;
       for(int j=1;j<=nums[i];j++)
       {
           if(i+j<n)
           {
           int jumps=1+dp[i+j];
            mn=min(mn,jumps);
           }
       }
       dp[i]=mn;
        }
        
     return dp[0];  
    }
};