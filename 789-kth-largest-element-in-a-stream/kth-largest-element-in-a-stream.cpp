class KthLargest {
    priority_queue<int, vector<int>,greater<int>>minpq;
    int K=0;
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto it: nums)
        {
            minpq.push(it);
        }
        int popTimes=minpq.size()-k;
        if(popTimes)
        {
            for(int i=0;i<popTimes;i++)
            {
                minpq.pop();
            }
        }
    }
    
    int add(int val) {
        if(minpq.size()<K)
        {
            minpq.push(val);
        }
        else
        {
            if(minpq.top()<val)
            {
                minpq.pop();
                minpq.push(val);
            }
        }
        return minpq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */