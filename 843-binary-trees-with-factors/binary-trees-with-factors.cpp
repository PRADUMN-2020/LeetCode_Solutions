class Solution {
public:
int M=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {

        sort(arr.begin(),arr.end());
         map<int,int>m;
         int n=arr.size();
         for(int i=0;i<arr.size();i++)
{
       m[arr[i]]=i;
}    
vector<int>dp(n,1);
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<i;j++)
       {
           if(arr[i]%arr[j]==0)
           {
               int sec=arr[i]/arr[j];
            //    cout<<"hi";
               if(m.find(sec)!=m.end())
            {dp[i]=(1ll*dp[i]+1ll*dp[j]*dp[m[sec]])%M;
            // cout<<(dp[j]*dp[m[sec]])<<endl;
            }
           }
       }
   }
   int ans=0;
   for(int i=0;i<n;i++)
   {
       ans=(ans+dp[i])%M;
   }
   return ans;

}
};