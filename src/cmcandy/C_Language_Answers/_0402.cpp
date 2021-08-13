#include <iostream>
#include <vector>
using namespace ::std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        //基本思想就是当i位元素>i+1位，则删掉i位，然后首位需要讨论一下
        int len = num.length();
        int sum = 0;
        int last_index = 0;
        
        for(int i = 1; i<len; i++){
            cout<<sum<<endl;
            if(k==0||num[last_index]<=num[i]||(num[i]==0&&last_index==0)){
                sum = sum * 10 +num[last_index]-'0';
                last_index = i;
            }else{
                //删除
                k--;
            }
        }
        return to_string(sum);
        
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    s.removeKdigits("1432219",3);
    return 0;
}
