class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> freq;

        for(int n : nums)
            freq[n]++;

        //Bucket : index = frequency, value = list of numbers
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for(auto& [num, cnt] : freq)
            bucket[cnt].push_back(num);
        
        vector<int> res;
        for(int i = n; i >= 1 && res.size() < k; i--)
            for(int num : bucket[i])
                res.push_back(num);

        return res;

        /*//Heap approach
        unordered_map<int,int> freq;
        for (int n : nums)
            freq[n]++;

        //min-heap of (frequency, number)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minPQ;
        for(auto& [num, cnt] : freq)
        {
            minPQ.push({cnt, num});
            if(minPQ.size() > k)
                minPQ.pop(); //keep only top k
        }

        vector<int> res;
        while(!minPQ.empty())
        {
            res.push_back(minPQ.top().second);
            minPQ.pop();
        }

        return res;*/
        
    }
};