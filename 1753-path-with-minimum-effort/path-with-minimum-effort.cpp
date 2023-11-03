class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int>deltaRow{1,-1,0,0};
        vector<int>deltaCol{0,0,1,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        effort[0][0]=0;
        pq.push({0,{0,0}});
        while(!(pq.top().second.first==n-1 and pq.top().second.second==m-1))
        {
           int eft=pq.top().first;
           int i=pq.top().second.first;
           int j=pq.top().second.second;
           pq.pop();
           for(int k=0;k<4;k++)
           {
               int ngbri=i+deltaRow[k];
               int ngbrj=j+deltaCol[k];
               if(ngbri>=0 and ngbri<n and ngbrj>=0 and ngbrj<m)
               {
                  int neft= max(eft,abs(heights[ngbri][ngbrj]-heights[i][j]));
                  if(neft<effort[ngbri][ngbrj])
                  {
                      effort[ngbri][ngbrj]=neft;
                      pq.push({neft,{ngbri,ngbrj}});
                  }
               }
           }
        }
        return pq.top().first;

    }
};