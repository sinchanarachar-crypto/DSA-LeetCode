class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> merged_arr;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged_arr));

        int n = merged_arr.size();
        
        if (n % 2 != 0)
        {
        return merged_arr[n / 2];
        }
    return (merged_arr[n/2 - 1] + merged_arr[n/2]) / 2.0;
        

        /*if(nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size(), n = nums2.size();
        int half = (m + n + 1) / 2;
        int l = 0, r = m;

        while(l <= r)
        {
            int i = l + (r - l) / 2;
            int j = half - i;

            int maxL1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minR1 = (i == m) ? INT_MAX : nums1[i];
            int maxL2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minR2 = (j == n) ? INT_MAX : nums2[j];

            if (maxL1 <= minR2 && maxL2 <= minR1)
            {
                if((m + n) % 2 == 1)
                    return max(maxL1 , maxL2);
                return(max(maxL1 , maxL2) + min(minR1 , minR2)) / 2.0;
            }
            else if(maxL1 > minR2)
            {
                r = i - 1;
            }
            else
            {
                l = i + 1;
            }
        }

        return 0.9;
        */
    }
};