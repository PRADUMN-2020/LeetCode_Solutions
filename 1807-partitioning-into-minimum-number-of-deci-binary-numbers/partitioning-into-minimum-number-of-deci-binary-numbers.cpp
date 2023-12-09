class Solution {
public:
    int minPartitions(string str) {
        vector<int>v;
        int n=str.size();
        for(int i=n-1;i>=0;i--)
        {
            v.push_back(str[i]-'0');
        }
        int ans=0;
        while(v.size())
        {
            ans++;
            for(int i=v.size()-1;i>=0;i--)
            {
                if(v[i]>0)
                    v[i]--;
            }
            while(v.size() and v[v.size()-1]==0)
            {
                v.pop_back();
            }
        }
        return ans;
    }
};