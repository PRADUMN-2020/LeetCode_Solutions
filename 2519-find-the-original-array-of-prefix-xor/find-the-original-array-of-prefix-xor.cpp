class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        // Time:O(32*n), Space:O(n)
        int n=pref.size();
        vector<int>ans(n);
        ans[0]=pref[0];
        for(int i=1;i<n;i++)
        {
            // cout<<pref[i]<<endl;
           
            for(int j=0;j<32;j++)
            {
                if((pref[i]&(1<<j))==0)
                {
                   
                    if(pref[i-1]&(1<<j))
                    {
                       
                        ans[i]=(ans[i]|(1<<j));
                    }
                }
                else
                { 
                    if((pref[i-1]&(1<<j))==0)
                    {
                        
                        ans[i]=(ans[i]|(1<<j));
                    }
                }
                // cout<<ans[i]<<endl;
            }
        }
        return ans;
    }
};