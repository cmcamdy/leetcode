#include <iostream>
#include <vector>
using namespace ::std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        //基本思想就是当i位元素>i+1位，则删掉i位，然后首位需要讨论一下
        int len = num.length();

        // int sum = 0;
        char sum[len]; 
        int last_index = 0;
        int index = 0;
        
        for(int i = 1; i<len; i++){
            if(k==0||num[last_index]<=num[i]){
                // sum = sum * 10 +num[last_index]-'0';
                sum[index++] = num[last_index];
            }else{
                //删除
                k--;
            }
            last_index++;
        }
        if(k==0){
            // sum = sum * 10 +num[last_index]-'0';
            sum[index] = num[last_index];
        }else{
            //最后一位算上
            if(num[last_index]<sum[--index]){
                // sum = sum - sum%10 +num[last_index]-'0';
                sum[index] = num[last_index];
            } 

            while(k-1>0){
                //这里应该是最后一位和最后第二位比较
                // int tmp_last = sum[index];
                sum[index-1] = sum[index]<sum[index-1]?sum[index]:sum[index-1];
                index--;
                k--;
            }
        }
        int first = 0;
        for(int i = 0; i<len;i++){
            if(sum[i]!='0'){
                first = i;
                break;
            }
        }
        string res(&sum[first],index+1);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // s.removeKdigits("1432219",3);
    // s.removeKdigits("112",1);
    // string res = s.removeKdigits("1234567890",9);
    string res = s.removeKdigits("10200",1);
    return 0;
}
