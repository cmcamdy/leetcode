#include <iostream>
#include <vector>
#include <string>
// #include <unordered_map>
using namespace ::std;



class Solution {
public:
    int countCollisions(string directions) {
        
        
        int right=0, mid=0, left=0;
        int count = 0;
        for(int i=0; i<directions.size(); i++){
            cout<<count<<" "<<i<<endl;
            if(directions[i]=='R') {
                right++;
            }
            else if(directions[i]=='S') {
                mid = 1;
                if(right>0) {
                    count += right;
                    right=0;
                }
            }else if(directions[i]=='L'){
                if(right>0){
                    count = count + right + 1;
                    mid = 1;
                    right = 0;
                }else if(mid==1){
                    count ++;
                }
            }
        }
        return count;
    }
};
int main(){

    Solution s;
    // cout<<s.countCollisions("SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR");
    cout<<s.countCollisions("LLSLSSLLLLLLRLRRLLR");
}