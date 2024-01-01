class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    // Time:O(n*log(n)+m), Space:O(n) where m is the roads.size()
      vector<int>degree(n);
      for(auto it: roads)
      {
          int u=it[0];
          int v=it[1];
          degree[v]++;
          degree[u]++;
      }
        priority_queue<int>pq;
        for(auto it: degree)
        {
            pq.push(it);
        }
        long long ans=0;
        while(pq.size())
        {
            ans+=(1ll*n)*pq.top();
            pq.pop();
            n--;
        }
        return ans;
            
    }
};