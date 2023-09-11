class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int j=0;j<2;j++)
        {
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                ans[i]=-1;
            }
            else if(st.top()>nums[i])
            {
                ans[i]=st.top();
            }
            else{
                while(st.size() and st.top()<=nums[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    ans[i]=-1;
                }
                else
                {
                    ans[i]=st.top();
                }

            }
            st.push(nums[i]);

        }
        }
return ans;
        
    }
};