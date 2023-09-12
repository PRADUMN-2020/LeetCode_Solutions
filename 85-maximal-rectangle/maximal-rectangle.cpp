//Intuition: To solve this, we will use the procedure to find the max area in the histogram problem. Basically here we create an array heights of size m and one by one iterate on each row and for each row we assume that there are buildings or bars in histogram of height equal to the number of ones from the i row to above till upwards.  In a row for each building we store its height at heights[j] and fill the heights array. Then we pass on this heights array to the procedure to find the max area in the histogram and update the max area in mxArea. Finally after doing this for all the rows mxArea will have the max area of the rectangle in the matrix and we return this.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Prerequisite Max Area in  the histogram.
        // Time:O(n*m), Space:O(m)
// Here there are n iterations of rows and O(m) time for the max area in the histogram procedure so total time is n*m.

        int n=matrix.size();
        int m=matrix[0].size();
        int mxArea=0;
        vector<int>heights(m);
     
        for(int i=0;i<n;i++)
        {
// Calculating the heights array.
           for(int j=0;j<m;j++)
           {
               if(matrix[i][j]=='1')
               {
                   heights[j]++;
               }
               else
               {
                   heights[j]=0;
               }
           }

// Passing heights array to the procedure to find the maxArea in the histogram.
             
           stack<int>st;

        for(int j=m-1;j>=0;j--)
        {
            if(st.size())
            {
                int left=st.top();
                if(heights[left]>heights[j])
                {
                    while(st.size() and heights[st.top()]>heights[j])
                    {
                        int height=heights[st.top()];
                       
                        st.pop();
                        int area=0;
                        if(st.size())
                        {
                            area=height*(st.top()-j-1);
                        }
                        else
                        { 
                            area=height*(m-j-1);
                        }
                        mxArea=max(mxArea, area);
                        
                    }
                }
            }
            st.push(j);
        }
     
    

        while(st.size())
        {
          int height=heights[st.top()];
          st.pop();
          int area=0;
                        if(st.size())
                        {
                            area=height*(st.top());
                        }
                        else
                        {
                          
                            area=height*(m);
                        }
          mxArea=max(mxArea, area);   
        }

        }

// Finally returning the Max area reactangle in the given matrix.
        return mxArea;
       

    }
};