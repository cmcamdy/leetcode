#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace ::std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> res;
        int len = asteroids.size();
        res.push_back(asteroids[0]);
        int size = 1;
        for (int i = 1; i < len; i++)
        {
            if (asteroids[i] > 0)
            {
                res.push_back(asteroids[i]);
                size++;
            }
            else
            {
                int tmp = abs(asteroids[i]);
                while (size > 0 && res[size - 1] > 0 && tmp > res[size - 1])
                {
                    res.pop_back();
                    size--;
                }
                if (size == 0 || res[size - 1] < 0)
                {
                    res.push_back(asteroids[i]);
                    size++;
                }
                else if (res[size - 1] == tmp)
                {
                    res.pop_back();
                    size--;
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> asteroids = {-2, -1, 1, 2};
    s.asteroidCollision(asteroids);
}