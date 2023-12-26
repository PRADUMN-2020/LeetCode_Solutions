class Solution {
public:
    int M=1e9+7;

    int numRollsToTarget(int n, int k, int target) {
        // Time:O(n*target*k), Space:O(target)
     vector<int>prev(target+1),curr(target+1);
     prev[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int ways=0;
                for(int l=1;l<=k and l<=j;l++)
                {
                    ways=(1ll*ways+prev[j-l])%M;
                }
                curr[j]=ways;
            }
            prev=curr;
        }
      return curr[target];   
    }
};