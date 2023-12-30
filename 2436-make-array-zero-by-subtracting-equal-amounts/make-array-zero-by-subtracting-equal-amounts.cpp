class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //Time:O(n*log(n)), Space:O(n)
        set<int>st;
        for(auto it:nums)
        {
            if(it)
            st.insert(it);
        }
        return st.size();
    }
};