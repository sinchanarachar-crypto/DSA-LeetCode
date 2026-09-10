class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;

        stringstream ss(s); // Tokenization
        
        string token;
        int wordCount = 0;

        while(getline(ss, token, ' ')) // Tokenization
        {
            words.push_back(token);
            wordCount++;
        }

        int n = pattern.length();

        if(n != wordCount) return false;

        unordered_map<string, char> mp;
        unordered_set<char> used;

        for(int i = 0; i < n; i++)
        {
            string word = words[i];
            char ch = pattern[i];

            if(mp.find(word) == mp.end() && used.find(ch) == used.end())
            {
                used.insert(ch);
                mp[word] = ch;
            }
            else if(mp[word] != pattern[i])
                return false;
        }

        return true;
    }

    /*
    {
        unordered_map<char, int> charToIdx;
        unordered_map<string, int> strToIdx;

        stringstream ss(s);
        string token;

        int countToken = 0;
        int i = 0;
        int n = pattern.size();

        while(ss >> token)
        {
            countToken++;

            if(i == n || charToIdx[pattern[i]] != strToIdx[token])
                return false;

            charToIdx[pattern[i]] = i + 1;
            strToIdx[token] = i + 1;

            i++;
        }

        if(countTokens != n || i != n) return false;

        return true;
    }
    */
};