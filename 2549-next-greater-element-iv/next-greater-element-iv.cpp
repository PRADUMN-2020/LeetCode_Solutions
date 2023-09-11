class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
      //  Time:O(nlog(n)) Space:O(n)
       vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],-i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        set<int>s;
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int x=-v[i].second;
            auto it=s.lower_bound(x);
            if(it==s.end())
            {
                ans[x]=-1;
            }
            else
            {
                it=next(it);
                if(it==s.end())
                {
                    ans[x]=-1;
                }
                else
                {
                    ans[x]=nums[*it];
                }
            }
            s.insert(x);
        }
        return ans;
    }
};