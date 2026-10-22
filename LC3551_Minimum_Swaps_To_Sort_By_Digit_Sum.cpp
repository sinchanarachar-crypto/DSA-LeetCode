class Solution
{
public:
    int getDigitSum(int num)
    {
        int sum = 0;
        while(num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> afterSorted(nums);
        
        auto lambda = [this](int nums1, int nums2)
        { 
            int ds1 = getDigitSum(nums1);
            int ds2 = getDigitSum(nums2);
            if(ds1 != ds2) return ds1 < ds2;
            return nums1 < nums2;
        }; 

        sort(begin(afterSorted), end(afterSorted), lambda);
        
        unordered_map<int, int> valToIdx;
        for(int i = 0; i < n; i++) valToIdx[nums[i]] = i;

        int swapCount = 0; 
        for(int i = 0; i < n; i++)
        {
            int expVal = afterSorted[i];
            int curVal = nums[i];
            
            if(expVal == curVal) continue;
            
            int idx = valToIdx[expVal];
            nums[i] = expVal;
            nums[idx] = curVal;
            
            valToIdx[expVal] = i;
            valToIdx[curVal] = idx;
            swapCount++;
        }
        return swapCount;
    }
};
