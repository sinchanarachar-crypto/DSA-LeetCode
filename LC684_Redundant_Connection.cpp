class Solution
{
private:
    vector<int> parent, rnk;
    int find(int x)
    {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y)
    {
        int rx = find(x), ry = find(y);
        if(rx == ry)
            return false;
        if(rnk[rx] < rnk[ry])
            swap(rx, ry);
        parent[ry] = rx;
        if (rnk[rx] == rnk[ry])
            rnk[rx]++;
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        parent.resize(n+1);
        rnk.resize(n+1, 0);
        iota(parent.begin(), parent.end(), 0);

        for(auto& e : edges)
        {
            if(!unite(e[0], e[1]))
                return e;
        }
        return {};
    }
};