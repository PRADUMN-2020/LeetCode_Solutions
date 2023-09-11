class Solution {
public:
// Intuition:

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