 bool comp(int a,int b){
        int c1=0,c2=0;
     for(int i=0;i<32;i++)
     {
         if(a&(1<<i))
         {
             c1++;
         }
     }
     for(int i=0;i<32;i++)
     {
         if(b&(1<<i))
         {
             c2++;
         }
     }
     if(c1!=c2)
     return c1<c2;
     else
     return a<b;
    }
class Solution {
public:
   
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};