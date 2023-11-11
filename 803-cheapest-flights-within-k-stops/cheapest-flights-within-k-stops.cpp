class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // vector<vector<pair<int,int>>>al(n);
        // vector<int>dist(n,1e9);
        // for(int i=0;i<flights.size();i++)
        // {
        //     int u=flights[i][0];
        //     int v=flights[i][1];
        //     int w=flights[i][2];
        //     al[u].push_back({v,w});
        // }
        // queue<pair<int,pair<int,int>>>q;
        // int limit=k;
        // dist[src]=0;
        // q.push({0,{src,0}});
        // while(q.size())
        // {
          
        //    auto it=q.front();
        //    q.pop();
        //    int u=it.second.first;
        //    int level=it.first;
        //    int cost=it.second.first;
        //    if(level>limit)
        //    continue;
        //    for(auto itr: al[u])
        //    {
        //       if(cost+itr.second<dist[itr.first] and level<=limit)
        //       {
        //           dist[itr.first]=cost+itr.second;
        //           q.push({level+1,{it.first,cost+itr.second}});
        //       }    
        //    }
        //    }
        
        // if(dist[dst]==1e9)
        // {
        //     return -1;
        // }
        // else
        // return dist[dst];

        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Create a queue which stores the node and their distances from the
        // source in the form of {stops, {node, dist}} with ‘stops’ indicating 
        // the no. of nodes between src and current node.
        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {src, 0}});

        // Distance array to store the updated distances from the source.
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // Iterate through the graph using a queue like in Dijkstra with 
        // popping out the element with min stops first.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // We stop the process as soon as the limit for the stops reaches.
            if (stops > K)
                continue;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;

                // We only update the queue if the new calculated dist is
                // less than the prev and the stops are also within limits.
                if (cost + edW < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
        // If the destination node is unreachable return ‘-1’
        // else return the calculated dist from src to dst.
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
        }

};