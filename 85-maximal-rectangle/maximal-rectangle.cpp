class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Prerequisite Max Area in  the histogram.
        // Time:O(n*m), Space:O(m)
        int n=matrix.size();
        int m=matrix[0].size();
        int mxArea=0;
        vector<int>heights(m);
     
        for(int i=0;i<n;i++)
        {
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
        return mxArea;
       

    }
};