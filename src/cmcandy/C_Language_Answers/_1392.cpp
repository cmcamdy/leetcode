#include <algorithm>
#include <iostream>
#include <vector>
using namespace ::std;

class Solution {
public:
  string longestPrefix(string s) {
    int L = s.size(), k;
    int next[100005]; // next[i]表示前(i-1)个字母的答案。
    next[0] = -1;     //强行规定的
    for (int j = 1; j <= L; j++) {
      k = next[j - 1];
      while (k != -1 && s[j - 1] != s[k]) {
        // 这里求的是nextval数组
        k = next[k];
      }
      next[j] = k + 1;
    }
    return s.substr(0, next[L]);
  }
};

int main() {
  Solution s;
  cout << s.longestPrefix("ababab");
}