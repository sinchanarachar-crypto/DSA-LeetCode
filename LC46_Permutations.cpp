class Solution
{
private:
    vector<vector<int>> res;
    vector<int> curr;
    vector<bool> visited;

    void backtrack(vector<int>& nums)
    {
        if(curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i])
                continue;
            visited[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums);
            curr.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        visited.assign(nums.size(), false);
        backtrack(nums);
        return res;
    }
};