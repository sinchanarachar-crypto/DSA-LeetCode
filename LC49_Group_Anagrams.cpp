class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> groups;

        for(string& s : strs)
        {
            string key = s;
            sort(key.begin(), key.end()); 
            groups[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto [key, words] : groups)
        res.push_back(words);

        return res; 

        /*unordered_map<string, vector<string>> groups;

        for (string& s : strs)
        {
            int cnt[26] = {};
            for(char c : s)
            cnt[c - 'a']++;

            string key = "";
            for (int i = 0; i < 26; i++)
            key += to_string(cnt[i]) + "#";
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& [k,v] : groups)
        res.push_back(v);
        return res;*/

    }
};