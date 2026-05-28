class Solution
{
public:

    struct TrieNode
    {
        int idx;
        int child[26];

        TrieNode()
        {
            idx = -1;
            memset(child, -1, sizeof(child));
        }
    };

    vector<TrieNode> trie;

    void insert(string& word, int wordIdx,
                vector<string>& wordsContainer)
    {
        int node = 0;
        int n = word.size();

        // update root best index
        if(trie[node].idx == -1 ||
            wordsContainer[trie[node].idx].size() > n ||
            (wordsContainer[trie[node].idx].size() == n &&
            trie[node].idx > wordIdx))
        {
            trie[node].idx = wordIdx;
        }

        for(int i = n - 1; i >= 0; i--)
        {
            int c = word[i] - 'a';

            if(trie[node].child[c] == -1)
            {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }

            node = trie[node].child[c];

            // update best index
            if(trie[node].idx == -1 ||
                wordsContainer[trie[node].idx].size() > n ||
                (wordsContainer[trie[node].idx].size() == n &&
                trie[node].idx > wordIdx))
            {
                trie[node].idx = wordIdx;
            }
        }
    }

    int search(string& word)
    {
        int node = 0;
        int ans = trie[node].idx;

        for(int i = word.size() - 1; i >= 0; i--)
        {
            int c = word[i] - 'a';

            if(trie[node].child[c] == -1)
                return ans;

            node = trie[node].child[c];

            ans = trie[node].idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                            vector<string>& wordsQuery)
    {
        trie.push_back(TrieNode());

        for(int i = 0; i < wordsContainer.size(); i++)
        {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> result;

        for(string& q : wordsQuery)
        {
            result.push_back(search(q));
        }

        return result;
    }
};