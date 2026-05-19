class Solution
{
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
                return nums1[i];

            else if(nums1[i] < nums2[j])
                i++;

            else if(nums1[i] > nums2[j])
                j++;
        }
        return -1;
    }

    /*{
        unordered_set<int> st;

        for(int num : nums1)
        {
            st.insert(num);
        }

        for(int num : nums2)
        {
            if(st.count(num))
                return num;
        }

        return -1;
    }*/
};