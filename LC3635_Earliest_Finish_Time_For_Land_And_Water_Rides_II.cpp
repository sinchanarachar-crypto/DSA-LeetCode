class Solution
{
public:
    int earliestFinishTime(vector<int>& landStartTime,
                            vector<int>& landDuration,
                            vector<int>& waterStartTime,
                            vector<int>& waterDuration)
    
    {
        int minLandFinish = INT_MAX;
        int minWaterFinish = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i = 0; i < n; i++)
        {
            minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
        }
        for(int i = 0; i < m; i++)
        {
            minWaterFinish = min(minWaterFinish, waterStartTime[i] + waterDuration[i]);
        }

        int ans = INT_MAX;

        for(int i = 0; i < m; i++)
        {
            int val = 0;
            if(waterStartTime[i] <= minLandFinish)
                val = minLandFinish + waterDuration[i];
            else
                val = waterStartTime[i] + waterDuration[i];
            ans = min(ans, val);
        }

        for(int i = 0; i < n; i++)
        {
            int val = 0;
            if(landStartTime[i] <= minWaterFinish)
                val = minWaterFinish + landDuration[i];
            else
                val = landStartTime[i] + landDuration[i];
            ans = min(ans, val);
        }
    return ans;
    }
};