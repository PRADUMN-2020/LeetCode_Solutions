class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
     //Time:O(n), Space:O(n)
     int minInd=-1;
     int mn=INT_MAX;
     int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int val=nums[i];
            if(val*val<mn)
            {
                mn=val*val;
                minInd=i;
            }
        }
        vector<int>ans;
        int l=minInd;
        int r=l+1;
        while(l>=0 and r<n)
        {
            int leftSquare=nums[l]*nums[l];
            int rightSquare=nums[r]*nums[r];
            if(leftSquare<rightSquare)
            {
                ans.push_back(leftSquare);
                l--;
            }
            else
            {
                ans.push_back(rightSquare);
                r++;
            }
        }
        while(r<n)
        {
            ans.push_back(nums[r]*nums[r]);
            r++;
        }
        while(l>=0)
        {
             ans.push_back(nums[l]*nums[l]);
            l--;
        }
        return ans;
        
        
                }
};