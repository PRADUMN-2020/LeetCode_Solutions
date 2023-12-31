class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Time:O(n^2*(log(k))), Space:O(k)
     priority_queue<int>pq;
     int n=matrix.size();
     int cnt=0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
            if(cnt<k)
            {
                pq.push(matrix[i][j]);
            }
            else
            {
                if(matrix[i][j]<pq.top())
                {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
             cnt++;
         }
     }
        return pq.top();
    }
};