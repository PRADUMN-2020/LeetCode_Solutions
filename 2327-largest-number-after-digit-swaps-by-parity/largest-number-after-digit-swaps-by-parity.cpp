class Solution {
public:
    int largestInteger(int num) {
    // Time:O(n*log(n)), Space:O(5*n) here n is the number of digits in num
      priority_queue<int>oddpq,evenpq;
      vector<int>oddIndex,evenIndex;
      int n=0;
      while(num>0)
      {
          int digit=num%10;
          if(digit%2)
          {
              oddIndex.push_back(n);
              oddpq.push(digit);
          }
          else
          {
              evenIndex.push_back(n);
              evenpq.push(digit);
          }
          num/=10;
          n++;
      }
       reverse(evenIndex.begin(),evenIndex.end());
       reverse(oddIndex.begin(),oddIndex.end());
       vector<int>finalNo(n);
      for(int i=0;i<oddIndex.size();i++)
      {
          int oddmax=oddpq.top();
          oddpq.pop();
          finalNo[oddIndex[i]]=oddmax;
      }
        for(int i=0;i<evenIndex.size();i++)
      {
          int evenmax=evenpq.top();
          evenpq.pop();
          finalNo[evenIndex[i]]=evenmax;
      }
       long long ans=0;
       long long multiple=1;
       for(int i=0;i<n;i++)
       {
         ans+=(multiple*finalNo[i]);
         multiple*=10;
       }
        return ans;
    }
};