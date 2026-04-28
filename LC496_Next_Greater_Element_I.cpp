class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for(int num : nums2)
        {
            while(!st.empty() && st.top() < num)
            {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> res;
        for(int n : nums1)
            res.push_back(nextGreater.count(n) ? nextGreater[n] : -1);
        return res;
    }
};