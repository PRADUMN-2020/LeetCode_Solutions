class Solution {
public:
    int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // Time:O(elog(n)), Space:O(n+e)
        vector<vector<pair<int,int>>>al(n);
        for(auto it: roads)
        {
            al[it[0]].push_back({it[1],it[2]});
            al[it[1]].push_back({it[0],it[2]});
        }
        vector<pair<long long,int>>dist(n,{1e18,0});
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        dist[0]={0,1};
        pq.push({0,0});
        while(pq.size())
        {
            auto it=pq.top();
            int node=it.second;
            long long cost=it.first;
            pq.pop();
            for(auto itr:al[node])
            {
                int adjNode=itr.first;
                long long adjCost=itr.second;
                if(cost+adjCost<dist[adjNode].first)
                {
                   dist[adjNode].first=cost+adjCost;
                   dist[adjNode].second=0;
                   dist[adjNode].second=(dist[adjNode].second+dist[node].second)%M;
                   pq.push({dist[adjNode].first,adjNode});
                }
                else if (cost+adjCost==dist[adjNode].first)
                {
                    dist[adjNode].second=(dist[adjNode].second+dist[node].second)%M;
                }
            }
        }
        return dist[n-1].second;
        
    }
};