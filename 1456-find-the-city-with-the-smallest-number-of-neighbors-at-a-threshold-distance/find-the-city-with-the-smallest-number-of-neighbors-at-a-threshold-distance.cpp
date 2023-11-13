class Solution {
public:
    const int inf=1000000;
   void floyd(int n,vector<vector<int>>& am)
   {
       for(int k=0;k<n;k++)
       {
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<n;j++)
               {
                //    if(i!=j&&i!=k&&j!=k)
                       am[i][j]=min(am[i][j],am[i][k]+am[k][j]);
               }
            }
       }
   }
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        // Time:O(n^3) // Space:O(n^2)
     vector<vector<int>>am(n,vector<int>(n,inf));
     for(int i=0;i<n;i++)
     {
        am[i][i]=0;
     }
    int e=edges.size();
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        int c=edges[i][2];
        am[u][v]=c;
        am[v][u]=c;
    }
        floyd(n,am);
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(am[i][j]<=dt)
                {
                    ans[i]++;
                }
            }
        }
        int min=1000000;
        int k=-1;
        for(int i=0;i<n;i++)
        {
            if(ans[i]<=min)
            {
                min=ans[i];
                k=i;
            }
        }
        return k;
       }
};