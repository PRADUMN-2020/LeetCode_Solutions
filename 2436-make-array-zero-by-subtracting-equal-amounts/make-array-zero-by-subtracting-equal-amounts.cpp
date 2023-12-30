class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //Time:O(n*log(n)), Space:O(n)
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            if(it)
            mp[it]++;
        }
        return mp.size();
    }
};