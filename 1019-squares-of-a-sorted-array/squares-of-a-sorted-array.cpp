class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it: nums)
        {
            pq.push(it*it);
        }
        vector<int>ans;
        while(pq.size())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
        }
};