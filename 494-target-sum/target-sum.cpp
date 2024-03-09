class Solution {
public:
    int helper(vector<int>&nums,int n,int target)
    {
        if(n==0)
        {
            if(nums[0]==abs(target))
            {
                if(target!=0)
                    return 1;
                else return 2;
            }
            else return 0;
        }
        int plus=helper(nums,n-1,target-nums[n]);
        int minus=helper(nums,n-1,target+nums[n]);
        return plus+minus;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return helper(nums,n-1,target);
    }
};