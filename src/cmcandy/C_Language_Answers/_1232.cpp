#include <iostream>
#include <vector>
using namespace ::std;
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        //y=kx+b
        int len = coordinates.size();
        if (len <= 2)
            return true;
        //垂线
        if (coordinates[1][0] == coordinates[0][0])
        {
            for (int i = 2; i < len; i++)
                if (coordinates[0][0] != coordinates[i][0])
                    return false;
        }
        else
        {
            //非垂线
            //k=(y2-y1)/(x2-x1)
            float k = 1.0 * (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
            //带入得b
            float b = coordinates[0][1] - k * coordinates[0][0];
            for (int i = 2; i < len; i++)
                if (coordinates[i][1] * 1.0 != (k * coordinates[i][0] + b))
                    return false;
        }
        return true;
    }
};