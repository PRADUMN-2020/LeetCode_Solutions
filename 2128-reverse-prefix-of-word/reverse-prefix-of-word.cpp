class Solution {
public:
    string reversePrefix(string word, char ch) {
        int find=-1;
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(word[i]==ch)
            {
                find =i;
                break;
            }
        }
        if(find!=-1)
        {
            int st=0,end=find;
            while(st<find)
            {
                swap(word[st],word[find]);
                    st++;
                    find--;
            }
        }
        return word;
        
    }
};