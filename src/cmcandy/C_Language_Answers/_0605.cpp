#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for(int i = 0; i<len;i++){
            if(flowerbed[i]==0&flowerbed[i+1]==0) {
                i++;
                n--;
            }else if(flowerbed[i]==1){
                i++;
            }
        }
        return n<=0?true:false;

    }
};
int main(int argc, char const *argv[])
{
    vector<int> flowered{1,0,0,0,1,0,0};
    Solution s;
    s.canPlaceFlowers(flowered,2);
    return 0;
}
