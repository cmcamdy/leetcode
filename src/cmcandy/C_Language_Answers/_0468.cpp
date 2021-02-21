#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution
{
public:
    string validIPAddress(string IP)
    {

        //分为验证v4和v6两部分
        //0=4,1=6
        int mod = 0;

        int len = IP.size();

        if (len > 15)
            mod = 1;
        else if (len == 15)
        {
            // 1判定检测模式
            for (int i = 0; i < 5; i++)
            {
                if (IP[i] == '.')
                    break;
                else if (IP[i] == ':')
                {
                    mod = 1;
                    break;
                }
            }
        }
        if (mod == 0)
        {
            //用于记录每一行的值
            int tmp = 0;
            int cp = 0;
            //IPV4
            for (int i = 0; i < len; i++)
            {
                if (IP[i] != '.' && (IP[i] < '0' || IP[i] > '9'))
                {
                    //数字不对的情况
                    return "Neither";
                }
                else if (IP[i] == '.' && (tmp > 255||IP[i-1]=='.'))
                {
                    //数字过大
                    return "Neither";
                }
                else if (IP[i] == '.' && tmp <= 255)
                {
                    tmp = 0;
                    cp++;
                }
                else if (IP[i] == '0' && i < (len - 1) && IP[i + 1] != '.')
                {
                    //以0开头的情况
                    return "Neither";
                }
                else
                {
                    //正常情况
                    tmp = tmp * 10 + IP[i] - '0';
                }
            }
            return tmp > 255 || cp!=3 ||IP[len-1]=='.' ? "Neither" : "IPv4";
        }
        else
        {
            int count = 0;
            int cp=0;
            //IPV6
            for (int i = 0; i < len; i++)
            {

                if (IP[i] == ':' && (count <= 0 || count > 4))
                    return "Neither";
                else if (!(IP[i]==':'||(IP[i] >= '0' && IP[i] <= '9') || (IP[i] >= 'a' && IP[i] <= 'f') || IP[i] >= 'A' && IP[i] <= 'F'))
                    return "Neither";
                else if (IP[i] == ':')
                {
                    count = 0;
                    cp++;
                }
                else{
                    count++;
                }
            }
            return count > 4 || count<=0 || cp!=7 ? "Neither" : "IPv6";
        }
    }
};
int main()
{
    Solution s;
    // s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334");
    cout << s.validIPAddress("172.16.204.1");

    return 0;
}