#include <iostream>
#include <string>
#include <vector>
using namespace ::std;

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        string res = "";
        int jud = 1;
        vector<int> tmp(8, 0);
        int j = 7;
        if (num < 0)
        {
            jud = -1;
            num = -num;
        }
        while (num > 0)
        {
            tmp[j--] = num % 16;
            num = num / 16;
        }
        if (jud == -1)
        {

            tmp[7] = 16 - tmp[7];
            int carry = 0;
            if (tmp[7] >= 16)
            {
                tmp[7] -= 16;
                carry = 1;
            }
            for (int i = 6; i > 0; i--)
            {
                tmp[i] = 15 - tmp[i] + carry;
                if (tmp[i] >= 16)
                {
                    tmp[i] -= 16;
                }
                else
                    carry = 0;
            }
            tmp[0] = 15 - tmp[0] + carry;
        }
        int write = 0;
        for (int i = 0; i < 8; i++)
        {
            if (tmp[i] == 0 && write == 1)
                res += "0";
            else
            {
                if (tmp[i] < 10 && tmp[i] > 0)
                    res += to_string(tmp[i]);
                else if (tmp[i] == 10)
                    res += "a";
                else if (tmp[i] == 11)
                    res += "b";
                else if (tmp[i] == 12)
                    res += "c";
                else if (tmp[i] == 13)
                    res += "d";
                else if (tmp[i] == 14)
                    res += "e";
                else if (tmp[i] == 15)
                    res += "f";
            }
            if (tmp[i] > 0)
                write = 1;
        }
        return res;
    }
};
int main()
{
    Solution s;
    cout << s.toHex(16);
}