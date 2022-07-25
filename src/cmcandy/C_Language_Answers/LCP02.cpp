#include <algorithm>
#include <iostream>
#include <vector>
using namespace ::std;

class Solution {
public:
    vector<int> res{1, 1};
    int gcd(int x, int y){
        return y?gcd(y,x%y):x;
    }

    vector<int> fraction(vector<int>& cont) {
        
        res[0] = cont[cont.size()-1];
        
        for(int i=cont.size()-2; i>=0; i--){
            swap(res[0], res[1]);
            res[0] += res[1]*cont[i];
            int g = gcd(res[0], res[1]);
            res[0] /= g;
            res[1] /= g; 
        }
        return res;
    }
};
int main() {
  Solution s;
  vector<int> count  = {3, 2, 0, 2};
  vector<int> res = s.fraction(count);
  cout << res[0] << " " << res[1];
}