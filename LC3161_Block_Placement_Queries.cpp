class Solution
{
public:
    struct SegTree
    {
        int n;
        vector<int> tree;

        SegTree(int n) : n(n), tree(4 * n, 0) {}

        void update(int node, int l, int r, int idx, int val)
        {
            if (l == r) {
                tree[node] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (idx <= mid)
                update(node * 2, l, mid, idx, val);
            else
                update(node * 2 + 1, mid + 1, r, idx, val);

            tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
        }

        int query(int node, int l, int r, int ql, int qr)
        {
            if (ql > r || qr < l)
                return 0;

            if (ql <= l && r <= qr)
                return tree[node];

            int mid = (l + r) / 2;

            return max(
                query(node * 2, l, mid, ql, qr),
                query(node * 2 + 1, mid + 1, r, ql, qr)
            );
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries)
    {
        int mx = 0;

        for (auto& q : queries)
        {
            mx = max(mx, q[1]);
        }

        set<int> pos;
        pos.insert(0);
        pos.insert(mx + 1);

        for (auto& q : queries)
        {
            if (q[0] == 1)
                pos.insert(q[1]);
        }

        SegTree seg(mx + 2);

        auto addGap = [&](int right, int gap)
        {
            seg.update(1, 0, mx + 1, right, gap);
        };

        auto it = pos.begin();
        auto prevIt = it;

        ++it;

        while (it != pos.end())
        {
            addGap(*it, *it - *prevIt);
            prevIt = it;
            ++it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--)
        {
            auto& q = queries[i];

            if (q[0] == 1)
            {
                int x = q[1];

                auto cur = pos.find(x);

                auto prv = prev(cur);
                auto nxt = next(cur);

                addGap(*nxt, *nxt - *prv);

                pos.erase(cur);
            }
            else
            {
                int x = q[1];
                int sz = q[2];

                auto it = pos.upper_bound(x);

                int right = *it;
                int left = *prev(it);

                int best = seg.query(1, 0, mx + 1, 0, left);

                best = max(best, x - left);

                ans.push_back(best >= sz);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};