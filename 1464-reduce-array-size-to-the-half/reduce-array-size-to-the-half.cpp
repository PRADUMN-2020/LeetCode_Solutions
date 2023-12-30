class Solution {
public:
    int minSetSize(vector<int>& arr) {
    // Time:O(n*log(n)), Space:O(n) where n is the size of arr and k is the no of distince elements in arr.
    int ans=0;
    unordered_map<int,int>mp;
    for(auto it:arr)
    {
        mp[it]++;
    }
    priority_queue<int>pq;
    for(auto it:mp)
    {
        pq.push(it.second);
    }
        int n=arr.size();
     int half=n/2;
     int taken=0;
     while(taken<half)
     {
         ans++;
         taken+=pq.top();
         pq.pop();
     }
        return ans;
    }
};