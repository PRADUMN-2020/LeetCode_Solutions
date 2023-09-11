class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
       //Time:O(n*log(n)) ,Space:O(n)
       map<int,vector<int>>m;
        vector<vector<int>>ans;
        int n=groupSizes.size();
        for(int i=0;i<n;i++)
        {
            m[groupSizes[i]].push_back(i);
        }
        for(auto it:m)
        {
            if(it.second.size())
            {
              for(int i=0;i<it.second.size();)
              {
                  vector<int>t;
                  int c=0;
                  while(i<it.second.size()&&c<it.first)
                  {
                      t.push_back(it.second[i]);
                      i++;
                      c++;
                  }
                  ans.push_back(t);
              }
                
            }
        }
        return ans;
        
    }
};