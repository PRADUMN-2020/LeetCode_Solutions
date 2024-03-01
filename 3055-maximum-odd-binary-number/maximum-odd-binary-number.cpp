class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                one++;
                s[i]='0';
            }
        }
        if(one)
        {
            s[n-1]='1';
            one--;
        }
        for(int i=0;i<one;i++)
        {
            s[i]='1';
        }
        return s;
        
    }
};