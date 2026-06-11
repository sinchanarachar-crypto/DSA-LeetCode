class Solution
{
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp)
    {
        long long result = 1;

        while(exp > 0)
        {
            if(exp & 1)
                result = (result * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return result;
    }

    int assignEdgeWeights(vector<vector<int>>& edges)
    {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = 0;

        queue<pair<int,int>> q;
        vector<bool> vis(n + 1, false);

        q.push({1, 0});
        vis[1] = true;

        while(!q.empty())
        {
            auto [node, depth] = q.front();
            q.pop();

            maxDepth = max(maxDepth, depth);

            for(int nei : adj[node])
            {
                if(!vis[nei])
                {
                    vis[nei] = true;
                    q.push({nei, depth + 1});
                }
            }
        }

        if(maxDepth == 0)
            return 0;

        return (int)modPow(2, maxDepth - 1);
    }
};