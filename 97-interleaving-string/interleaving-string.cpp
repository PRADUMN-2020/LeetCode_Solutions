class Solution {
public:
// f(i,j) denotes that weather the remaining string 3 can be formed by interleaving of s1 i onwards and s2 j onwards.
    
    bool isInterleave(string &s1, string &s2, string &s3) {
        // Time:O(n*m), Space:O(m)
        int n=s1.size();
        int m=s2.size();
        int o=s3.size();
        if(o!=m+n)
        return 0;

       vector<int>prev(m+1);

        prev[m]=o==n+m;

       for(int j=m-1;j>=0;j--)
       {
           prev[j]=(s2[j]==s3[o-1-(m-1-j)]) and prev[j+1];
       }
       
        for(int i=n-1;i>=0;i--)
        {
            
            for(int j=m;j>=0;j--)
            {

                int k=i+j;
                if(n-i+m-j!=o-k)
                {
                   prev[j]=0;
                }
               else if(j==m)
                {
                    if(s1[i]==s3[(o-1-(n-1-i))] and prev[j])
                    {
                        
                        prev[m]=1;
                    }
                    else
                    {
                        prev[m]=0;
                    }

                }
                               
                else if(s3[k]==s1[i] and s3[k]==s2[j])
                {
                    prev[j]= prev[j] or prev[j+1];
                }
                else if(s3[k]==s1[i])
                {
                prev[j]=prev[j];
                }
                else if(s3[k]==s2[j])
                {
                    prev[j]= prev[j+1];
                }
                else
               prev[j]=0;
            }
        }

        return prev[0];
    }
};