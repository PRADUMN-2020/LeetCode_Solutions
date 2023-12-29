class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        //Time:O(n*m*log(m)), Space:O(n*m)
     int n=grid.size();
     int m=grid[0].size();
     vector<priority_queue<int>>vpq(n);
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             vpq[i].push(grid[i][j]);
         }
     }
     int ans=0;
     for(int j=m-1;j>=0;j--)
     {
         int mx=0;
         for(int i=0;i<n;i++)
         {
             mx=max(mx,vpq[i].top());
             vpq[i].pop();
         }
         ans+=mx;
     }
        return ans;
    }
};