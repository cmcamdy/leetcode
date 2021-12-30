#include <vector>
#include <iostream>
#include <string>
using namespace ::std;
class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int dayMin = 24 * 60;
        vector<int> time(dayMin, 0);
        int etime = -1, ltime = -1, last = -1;

        int len = timePoints.size();
        for (int i = 0; i < len; i++)
        {
            int tmp = (timePoints[i][0] - '0') * 600 + (timePoints[i][1] - '0') * 60 + (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
            time[tmp] += 1;
        }
        int mt = dayMin;
        for (int i = 0; i < dayMin; i++)
        {
            if (time[i] == 1)
            {
                if (etime == -1)
                {
                    etime = i;‰´
                }
                if (ltime < i)
                {
                    ltime = i;
                }
                if (last == -1)
                {
                    last = i;
                }
                else
                {
                    mt = min(mt, i - last);
                    last = i;
                }
            }
            else if (time[i] > 1)
            {
                return 0;
            }
        }
        mt = min(mt, etime + dayMin - ltime);
        return mt;
    }
};
int main()
{
    Solution s;
    vector<string> timestr = {"01:01", "02:01", "03:00"};
    s.findMinDifference(timestr);
}