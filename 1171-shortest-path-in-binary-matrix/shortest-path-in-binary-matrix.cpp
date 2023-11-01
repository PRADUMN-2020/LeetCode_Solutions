class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Time:O(n^2) Space:O(n^2)
        vector<int>deltaRow{1,-1,0,0,1,1,-1,-1};
        vector<int>deltaCol{0,0,1,-1,1,-1,1,-1};
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1)
        {
            return -1;
        }
       
       
        queue<pair<int,int>>q;
        unordered_map<int,int>visited;
        visited[0]=1;
        q.push({0,0});
        int l=1;
        while(!q.empty())
        {
            int currentLevelSize=q.size();
            for(int j=0;j<currentLevelSize;j++)
            {
            pair<int,int> u=q.front();
            if(u.first==n-1 and u.second==n-1)
            return l;
            q.pop();
            for(int i=0;i<8;i++)
            {
                int childRow=u.first+deltaRow[i];
                int childCol=u.second+deltaCol[i];
                if(childRow>=0 and childRow<=n-1 and childCol>=0 and childCol<=n-1 and grid[childRow][childCol]==0 and visited[childRow*n+childCol]==0)
                {
                    visited[childRow*n+childCol]=1;
                    q.push({childRow,childCol});
                }
            }
          
        }
          l++;
        }
        return -1;
        
    }
};