class Solution {
public:
    class Comp {
    public:
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        if(a.first!=b.first)
        {
            return a.first>b.first;
        }
        else
        {
            return a.second>b.second;
        }
    }};
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // Time:O(n*(m+log(n))+k*log(n)), Space:O(n+k)
    priority_queue<pair<int,int>,vector<pair<int,int>>,Comp>minpq;
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++)
        {
          int soldiers=0;
          for(int j=0;j<m;j++)
          {
              soldiers+=mat[i][j];
          }
        minpq.push({soldiers,i});
        }
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(minpq.top().second);
            minpq.pop();
        }
        return ans;
    }
};