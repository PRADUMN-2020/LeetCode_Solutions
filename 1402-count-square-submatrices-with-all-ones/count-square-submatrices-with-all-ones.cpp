class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Intuition: Here we declare a dp array of n,m where dp[i][j]: the no. of square submatrices ending at i,j. 
        
        //Here in we are using the matrix itself to save space.  
        
        // Here for the first row and column we keep it as it is. Now we iterate on each i,j where i is [1,n] and j is[1,m] and 
        
        // if matrix[i][j]==1 then martrix[i][j]=1+min(matrix[i-1][j],matrix[i-1][j-1],matrix[i][j-1])       [or matrix[i][j]+=min({matrix[i-1][j],matrix[i-1][j-1],matrix[i][j-1]})], 
        
        // else if martix[i][j] == 0, keep martix[i][j] 0 itself.

        // Finally the total no. of square submatrices is the sum of the no. of square submatices ending at i,j for all i,j pairs.

        //Time:O(m*n) Space:O(1)
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j])
                matrix[i][j]+=min({matrix[i-1][j],matrix[i-1][j-1],matrix[i][j-1]});
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum+=matrix[i][j];
            }
        }
        return sum;
    }
};