#include <iostream>
#include <vector>
using namespace::std;


using T = long long; 
// BIT = binary tree
struct BIT{
    int n;
    vector<T> v;
    BIT(int n): n(n), v(n){}

    int lowbit(int x){
        return x & -x;
    }
    void add(int x, T y){
        while(x<=n){
            v[x] += y;
            x += lowbit(x);
        }
    }

    T sum(int x){
        // 前缀和
        int ans = 0;
        while(x >= 1){
            ans += v[x];
            x -= lowbit(x);
        }
        return ans;
    }

};





int main(){





}