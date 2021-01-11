#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace ::std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //拓扑算法
        //构造一个图，用邻接矩阵
        vector<int> tmp(numCourses,0);
        vector<vector<int>> dp(numCourses,vector<int>(1,-1));
        vector<int> que;
        int len = prerequisites.size();

        if(len==0)return true;

        //构造邻接表
        for(int i = 0; i<len; i++){
            tmp[prerequisites[i][0]] ++;
            dp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //构造广度优先队列
        for(int i =0;i<numCourses;i++){
                if(tmp[i]==0){
                    // tmp[i]--;
                    //加入队列
                    que.push_back(i);
                }
        }
        //执行拓扑算法
        int index = 0;
        //广度优先算法
        while(index<que.size()){
            for(int i = 1;i<dp[que[index]].size();i++){
                if(tmp[dp[que[index]][i]]--==1){
                    que.push_back(dp[que[index]][i]); 
                }
            }
            index++;
        }
        return index==numCourses?true:false;
    }
};