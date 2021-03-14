
class Solution
{
public:
    int integerBreak(int n)
    {
        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;
        else if (n == 4)
            return 4;
        return 3 * help(n - 3);
    }
    int help(int n)
    {
        if (n == 2)
            return 2;
        else if (n == 3)
            return 3;
        else if (n == 4)
            return 4;
        return 3 * help(n - 3);
    }
};