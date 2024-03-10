class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Time:O(n*log(n)+m*log(m)), Space:O(1)
        vector<int>ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0;
        int n= nums1.size();
        int m=nums2.size();
        while(i<n and j<m)
        {
            if(nums1[i]<nums2[j])
            {
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
            else
            {
                if(ans.size()==0)
                ans.push_back(nums1[i]);
                else
                {
                    if(ans[ans.size()-1]!=nums1[i])
                    {
                        ans.push_back(nums1[i]);
                    }
                }
                i++;
                j++;
            }
        }
        return ans;
        
    }
};