#include <iostream>
#include <vector>
#include <algorithm>
using namespace ::std;

class Solution
{
public:
    vector<vector<int>> arrs;
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        arrs = intervals;
        quicksort(0, intervals.size()-1);
        int right = 0;
        int res = intervals.size();
        for (int i = 0; i < intervals.size(); i++)
        {
            if(arrs[i][1]>right) right = arrs[i][1];
            else res--;
        }
        return res;
    }
    void quicksort(int start, int end)
    {
        if (start >= end)
            return;
        int mode = 1;
        int left = start, right = end;
        while (left < right)
        {
            if (mode == 1)
            {
                // if right < left
                if (!compare_vec(arrs[left], arrs[right]))
                {
                    mode = 0;
                    swap(arrs[left], arrs[right]);
                    left++;
                }
                else
                {
                    right--;
                }
            }
            else if (mode == 0)
            {
                if (!compare_vec(arrs[left], arrs[right]))
                {
                    mode = 1;
                    swap(arrs[left], arrs[right]);
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        quicksort(start, left - 1);
        quicksort(left + 1, end);
    }
    bool compare_vec(vector<int> a, vector<int> b)
    {
        if (a[0] < b[0])
            return true;
        else if (a[0] == b[0] && a[1] > b[1])
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    cout << s.removeCoveredIntervals(intervals);
}