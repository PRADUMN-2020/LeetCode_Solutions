class Solution {
public:
    long long maximumSumOfHeights(vector<int>& mxh) {
        // Time:O(n), Space:O(n)
        int n=mxh.size();
        vector<int>nsr(n,n),nsl(n,-1);
        // calculating next greater to right
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
           if(st.size())
           {
               while(st.size() and mxh[st.top()]>=mxh[i])
               {
                   st.pop();
               }
               if(st.size())
               {
                   nsr[i]=st.top();
               }
           }
           st.push(i);
        }

        while(st.size())
        st.pop();

        // calculating next greater to left
        for(int i=0;i<n;i++)
        {
           if(st.size())
           {
               while(st.size() and mxh[st.top()]>=mxh[i])
               {
                   st.pop();
               }
               if(st.size())
               {
                   nsl[i]=st.top();
               }
           }
           st.push(i);
        }
      
        vector<long long>rightSum(n),leftSum(n);
// calculating if i is chosen to be the max height of hill then the sum of heights from i to right
        for(int i=n-1;i>=0;i--)
        {
            rightSum[i]=1ll*mxh[i]*(nsr[i]-i)+((nsr[i]!=n)?rightSum[nsr[i]]:0);
        }
// calculating if i is chosen to be the max height of hill then the sum of heights from i to left
        for(int i=0;i<n;i++)
        {
            leftSum[i]=1ll*mxh[i]*(i-nsl[i])+((nsl[i]!=-1)?leftSum[nsl[i]]:0);
        }

// calculating the max possible sum amoung all i's chosen as hill tops.
        long long mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,rightSum[i]+leftSum[i]-mxh[i]);
        }
        return mx;
        
        
        
        
    }
};