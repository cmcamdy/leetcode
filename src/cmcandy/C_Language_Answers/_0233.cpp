#include <iostream>
#include <string>
#include <vector>
using namespace ::std;


class Solution {
public:
    int countDigitOne(int n) {
        if(n==0) return 0;
        // 13 = 10 + 3 =  (3+1) + (1+1)
        // 1024 = 1000 + 24 = 24
        int left = n, right=0;
        int count = 0, e = 1;
        while(left>0){
            int mid = left % 10;
            left /= 10;
            // ab' < ab
            count += left * e;
            // ab' = ab
            if(mid == 1){
                count += (1+right);
            }else if(mid > 1){
                count += e;
            }
            right += (mid * e);
            e *= 10;
        }
        return count;
    }
};

int main(){
    Solution s;
    // cout<<s.countDigitOne(13);
    cout<<s.countDigitOne(20);
    // for(int i=0; i<20; i++){
    //     cout<< i+1 << endl;
    // }
}