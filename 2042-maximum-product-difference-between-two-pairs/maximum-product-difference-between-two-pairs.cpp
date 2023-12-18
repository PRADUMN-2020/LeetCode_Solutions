class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // Time:O(n), space: O(1)
     int mini,secondMini,maxi,secondMaxi;
     int n=nums.size();
     mini=secondMini=INT_MAX;
     maxi=secondMaxi=INT_MIN;
     int firstmin=-1,secondmin=-1,firstmax=-1,secondmax=-1;
     for(int i=0;i<n;i++)
     {
        if(nums[i]<mini)
        {
            mini=nums[i];
            firstmin=i;
        }
         if(nums[i]>maxi)
        {
            maxi=nums[i];
            firstmax=i;
         }
        
     }
     for(int i=0;i<n;i++)
     {
         if(nums[i]<secondMini and i!=firstmin)
         {
             secondMini=nums[i];
         }
         if(nums[i]>secondMaxi and i!=firstmax)
         {
             secondMaxi=nums[i];
         }
     }
        return (maxi*secondMaxi)-(mini*secondMini);
    }
};
