class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
    priority_queue<int, vector<int>, greater<int>> minPQ;

    for(int n : nums)
    {
        minPQ.push(n);
        if(minPQ.size() > k)
            minPQ.pop();
    }
    return minPQ.top();
    }

    /*int partition(vector<int>&nums, int l, int r)
    {
        int pivot = nums[r], p = l;
        for(int i = l; i < r; i++)
            if(nums[i] >= pivot)
                swap(nums[i], nums[p++]);
        swap(nums[p], nums[r]);
        return p;
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        int l = 0, r = nums.size() - 1, target = k - 1;
        while(true)
        {
            int p = partition(nums, l, r);
            if (p == target)
                return nums[p];
            else if (p < target)
                l = p + 1;
            else
                r = p - 1;
        }
    }*/
};