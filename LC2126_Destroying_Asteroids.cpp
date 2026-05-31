class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    /*{
        long long MASS = mass;
        sort(asteroids.begin(), asteroids.end());

        for(auto m : asteroids)
        {
            if(MASS < m)
                return false;
            else
                MASS += m;
        }
        return true;
    }*/

    {
        sort(asteroids.begin(), asteroids.end());

        for(auto m : asteroids)
        {
            if(mass < m)
                return false;
            else if(mass > 1e5)
                return true;
            mass += m;
        }
        return true;
    }
};