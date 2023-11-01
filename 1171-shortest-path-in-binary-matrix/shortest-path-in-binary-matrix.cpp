class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Time:O(n^2) Space:O(n^2)
         int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)
        {
            return -1;
        }
       
        int node=0;
        vector<vector<int>>al(n*n+1);
        vector<int>visited(n*n+1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                node++;
                if(grid[i][j]==0)
                {
                     if(i-1>=0 and grid[i-1][j]==0)
                     {
                         al[node].push_back(node-n);
                     }
                     if(i-1>=0 and j-1>=0 and grid[i-1][j-1]==0)
                     {
                          al[node].push_back(node-n-1);
                     }
                    if(i-1>=0 and j+1<n and grid[i-1][j+1]==0)
                    {
                        al[node].push_back(node-n+1);
                    }
                    if(j-1>=0 and grid[i][j-1]==0)
                    {
                        al[node].push_back(node-1);
                    }
                    if(j+1<n and grid[i][j+1]==0)
                     {
                         al[node].push_back(node+1);
                     }
                     if(i+1<n and j-1>=0 and grid[i+1][j-1]==0)
                     {
                          al[node].push_back(node-1+n);
                     }
                    if(i+1<n and grid[i+1][j]==0)
                    {
                        al[node].push_back(node+n);
                    }
                    if(i+1<n and j+1<n and grid[i+1][j+1]==0)
                    {
                        al[node].push_back(node+n+1);
                    }
                }
            }
        }
      
        queue<int>q;
        visited[1]=1;
        q.push(1);
         vector<int>level(n*n+1);
        int l=1,cln=1;
        while(!q.empty())
        {
            cln=q.size();
            for(int j=0;j<cln;j++)
            {
            int u=q.front();
            level[u]=l;
            if(u==n*n)
            return level[u];
            q.pop();
            for(int i=0;i<al[u].size();i++)
            {
                if(visited[al[u][i]]==0)
                {
                    visited[al[u][i]]=1;
                    q.push(al[u][i]);
                }
            }
            }
            l++;
        }
        // if(visited[n*n]==0)
        // {
        //     return -1;
        // }
        // else
        // {
        //     return level[n*n];
        // }
        return -1;
            
    }
};