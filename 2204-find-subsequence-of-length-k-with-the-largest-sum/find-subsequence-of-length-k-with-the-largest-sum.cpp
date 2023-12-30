class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pqelem,pqind;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pqelem.push({nums[i],i});
        }
        for(int i=0;i<n-k;i++)
        {
            pqelem.pop();
        }
        for(int i=0;i<k;i++)
        {
            pqind.push({pqelem.top().second,pqelem.top().first});
            pqelem.pop();
        }
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(pqind.top().second);
            pqind.pop();
        }
        return ans;
        
    }
};