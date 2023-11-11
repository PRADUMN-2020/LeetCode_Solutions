class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Time:O(E), Space:O(N+E)
        vector<vector<pair<int,int>>>al(n);
        vector<int>dist(n,1e9);
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            al[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>>q;
        int limit=k+2;
        dist[src]=0;
        q.push({1,{src,0}});
        
        while(q.size())
        { 
           auto it=q.front();
           q.pop();
           int u=it.second.first;
           int level=it.first;
           int cost=it.second.second;
           for(auto itr: al[u])
           {
              if(cost+itr.second<dist[itr.first] and level<limit)
              {
                  dist[itr.first]=cost+itr.second;
                  q.push({level+1,{itr.first,cost+itr.second}});
              }    
           }
           }
        
        if(dist[dst]==1e9)
        {
            return -1;
        }
        else
        return dist[dst];

      }

};