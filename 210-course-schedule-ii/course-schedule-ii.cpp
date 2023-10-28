class Solution {
public:
  
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // Time:O(n+e) ,Space:O(n+e)
    
        int e=prerequisites.size();
        vector<int>adj[n];
        vector<int>preq(n);
        for(int i=0;i<e;i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
            preq[u]++;
        }
        vector<int>ans;
        queue<int>q;
   for(int i=0;i<n;i++)
   {
       if(preq[i]==0)
       {
           q.push(i);
       }
   }
   while(q.size())
   {
      int u=q.front();
      q.pop();
      ans.push_back(u);
      for(auto it:adj[u])
      {
          preq[it]--;
          if(preq[it]==0)
          {
              q.push(it);
          }
      }
   }
        if(ans.size()==n)
        {
            return ans;
        }
        else
        {
        vector<int>ansn;
        return ansn;
        }
    }
};