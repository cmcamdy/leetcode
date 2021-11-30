#include <iostream>
#include <map>
#include <string>
using namespace ::std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len = s.size();
        int left = 0, right = len - 1;
        while (left <= right)
        {
            int tl = -2, tr = -2;
            while (left < len && (tl = charChange(s[left])) == -1)
            {
                left++;
            }
            while (right >= 0 && (tr = charChange(s[right])) == -1)
            {   
                right--;
            }
            if (tr != -1 && tl != tr)
                return false;
            left++;
            right--;
        }
        return true;
    }
    int charChange(char A)
    {
        if (A >= 'A' && A <= 'Z')
            return A - 'A' + 10;
        else if (A >= 'a' && A <= 'z')
            return A - 'a' + 10;
        else if (A >= '0' && A <= '9')
            return A - '0';
        else
            return -1;
    }
};

int main()
{

    Solution s;
    cout<<s.isPalindrome(".,,,");
    cout << s.isPalindrome("A man, a plan, a canal: Panama");
}