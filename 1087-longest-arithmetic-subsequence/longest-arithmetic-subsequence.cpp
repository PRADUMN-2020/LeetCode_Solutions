class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {  
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
        
        int ans=INT_MIN;
      
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<i;j++)
              {
                     int d=nums[i]-nums[j];
                     dp[i][d]=max(dp[i][d],(dp[j][d]==0?1:dp[j][d])+1);
                     ans=max(ans,dp[i][d]);
             }
            
          }
      
      return ans;
    }
};