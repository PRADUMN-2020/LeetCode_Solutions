class Solution {
public:
// Intuition: Here we first find the first smaller element on the left for each element of the array. And then we find the first smaller element on the right for each element using stack (for O(N) time). Then we know that the max size rectangle will have a height equal to that of one of the element in the array. So for each element in the array we try to make the largest rectangle with height equal to that element. And the answer will be one of these so we find the max area amoung all these and that will be the answer. For a perticular element the largest rectangle with that height will have area =  heights[i]*( firstSmallerOnRight[i]-firstSmallerOnLeft[i]-1) so we find this area for each element and take the max amoung them. The max will be the answer.

// Time:O(n), Space:O(n)

    int largestRectangleArea(vector<int>& heights) {
        int mxArea=0;
        int n=heights.size();
        stack<int>st;
        vector<int>firstSmallerOnLeft(n,-1);
        vector<int>firstSmallerOnRight(n,n);

// first Smaller On Left computation. O(n) Time.
        for(int i=0;i<n;i++)
        {
            if(st.size())
            {
                int left=st.top();
                if(heights[left]<heights[i])
                {
                    firstSmallerOnLeft[i]=left;
                }
                else
                {
                    while(st.size() and heights[st.top()]>=heights[i])
                    {
                        st.pop();
                    }
                    if(st.size())
                    {
                        firstSmallerOnLeft[i]=st.top();
                    }
                }
            }

            st.push(i);
        }
// clear the stack for the firstSmallerOnRight computation. O(n) Time.
        while(st.size())
        {
            st.pop();
        }


// first Smaller On Right computation. O(n) Time.

for(int i=n-1;i>=0;i--)
        {
            if(st.size())
            {
                int right=st.top();
                if(heights[right]<heights[i])
                {
                    firstSmallerOnRight[i]=right;
                }
                else
                {
                    while(st.size() and heights[st.top()]>=heights[i])
                    {
                        st.pop();
                    }
                    if(st.size())
                    {
                        firstSmallerOnRight[i]=st.top();
                    }
                }
            }

            st.push(i);
        }

// Taking the max of the areas of max size rectangles with height equal to a perticular element in the array.

      for(int i=0;i<n;i++)
      {
          int area=heights[i]*( firstSmallerOnRight[i]-firstSmallerOnLeft[i]-1);
          mxArea=max(mxArea,area);
      }

       
        return mxArea;
    }
};