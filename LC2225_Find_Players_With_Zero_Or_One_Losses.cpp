class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        unordered_map<int, int> lost;

        for(int i = 0; i < matches.size(); i++)
        {
            int loser = matches[i][1];

            lost[loser]++;
        }

        vector<int> notLost;
        vector<int> lostOnce;

        for(int i = 0; i < matches.size(); i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(lost.find(winner) == lost.end())
            {
                notLost.push_back(winner);
                lost[winner] = 2;
            }

            if(lost[loser] == 1) lostOnce.push_back(loser);
        }

        sort(begin(notLost), end(notLost));
        sort(begin(lostOnce), end(lostOnce));

        return {notLost, lostOnce};
    }
};