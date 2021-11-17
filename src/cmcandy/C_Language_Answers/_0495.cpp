#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int len = timeSeries.size();
        if (len == 1)
            return duration;
        int lastAtc = timeSeries[0], maxTime = duration;

        for (int i = 1; i < len; i++)
        {
            if (timeSeries[i] - lastAtc <= duration)
            {
                maxTime += timeSeries[i] - lastAtc;
            }
            else
                maxTime += duration;
            lastAtc = timeSeries[i];
        }
        return maxTime;
    }
};