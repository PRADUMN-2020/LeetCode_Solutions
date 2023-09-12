class Solution {
public:
// Intuition: Previous version 3 pass this version 1 pass solution. Complex Intuition Link: https://www.youtube.com/watch?v=jC_cWLy7jSI

// Time:O(n), Space:O(n)

    int largestRectangleArea(vector<int>& heights) {
        int mxArea=0;
        int n=heights.size();
        stack<int>st;


        for(int i=n-1;i>=0;i--)
        {
            if(st.size())
            {
                int left=st.top();
                if(heights[left]>heights[i])
                {
                    while(st.size() and heights[st.top()]>heights[i])
                    {
                        int height=heights[st.top()];
                       
                        st.pop();
                        int area=0;
                        if(st.size())
                        {
                            area=height*(st.top()-i-1);
                        }
                        else
                        { 
                            area=height*(n-i-1);
                        }
                        mxArea=max(mxArea, area);
                        
                    }
                }
            }
            st.push(i);
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
                            area=height*(n);
                        }
          mxArea=max(mxArea, area);   
        }
       
        return mxArea;
    }
};