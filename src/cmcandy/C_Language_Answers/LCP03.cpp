#include <algorithm>
#include <iostream>
#include <vector>
using namespace ::std;

class Solution {
public:
  bool robot(string command, vector<vector<int>> &obstacles, int x, int y) {
    vector<vector<int>> node;
    int nx = 0, ny = 0;
    for (int i = 0; i < command.size(); i++) {
      if (command[i] == 'U')
        ny++;
      if (command[i] == 'R')
        nx++;
      node.push_back({nx, ny});
    }

    bool jud = false;
    // 判断能否到达终点
    for (auto n : node) {
      if ((x - n[0]) % nx == 0 && (y - n[1]) % ny == 0 && (x - n[0]) / nx == (y - n[1]) / ny) {
        jud = true;
        break;
      }
    }
    // 不能到就免谈
    if (jud == false)
      return false;

    for (auto obs : obstacles) {
      for (auto n : node) {
        if (obs[0] <= x && obs[1] <= y && (obs[0] - n[0]) % nx == 0 &&
            (obs[1] - n[1]) % ny == 0 &&  (obs[0] - n[0]) / nx == (obs[1] - n[1]) / ny)
          return false;
      }
    }

    return true;
  }
};
int main() {
  Solution s;
  //   vector<vector<int>> obs = {{10, 5}, {1, 6},  {6, 10}, {3, 0},
  //                              {0, 3},  {0, 10}, {6, 2}};
  //   string command = "RUUR";
  //   int x = 7856, y = 9033;

  //   vector<vector<int>> obs = {{2, 2}};
  //   string command = "URR";
  //   int x = 3, y = 2;

  string command = "URRURRR";
  vector<vector<int>> obs = {{7, 7}, {0, 5}, {2, 7}, {8, 6}, {8, 7},
                             {6, 5}, {4, 4}, {0, 3}, {3, 6}};
  int x = 4915, y = 1966;
  cout << s.robot(command, obs, x, y);
}