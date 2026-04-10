class Solution
{
private:
    vector<vector<int>> prereq;
    vector<int> state;

    bool dfs(int course)
    {
        if(state[course] == 1)
            return false;
        if(state[course] == 2)
            return true;

        state[course] = 1;
        for(int pre : prereq[course])
            if(!dfs(pre))
                return false;
        state[course] = 2;
        return true;
    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        prereq.resize(numCourses);
        state.assign(numCourses, 0);
        for(auto& p : prerequisites)
            prereq[p[0]].push_back(p[1]);
        for(int c = 0; c < numCourses; c++)
            if(!dfs(c))
                return false;

        return true;
    }
};