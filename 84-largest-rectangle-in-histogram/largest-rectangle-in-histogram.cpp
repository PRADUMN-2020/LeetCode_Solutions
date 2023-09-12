class Solution {
public:
// Intuition: Here we first find the first smaller element on the left for each element of the array. And then we find the first smaller element on the right for each element using stack (for O(N) time). Then we know that the max size rectangle will have a height equal to that of one of the element in the array. So for each element in the array we try to make the largest rectangle with height equal to that element. And the answer will be one of these so we find the max area amoung all these and that will be the answer. For a perticular element the largest rectangle with that height will have area =  heights[i]*( firstSmallerOnRight[i]-firstSmallerOnLeft[i]-1) so we find this area for each element and take the max amoung them. The max will be the answer.

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