#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace ::std;

class Solution
{
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs)
    {
        // 重建一个，看看是否唯一，且每个位置数字是否对应
        int len = org.size();
        // vector<int> vecIns(len + 2, 0);
        // vector<int> ext(len + 2, 0);

        map<int, int> vecIns;
        map<int, int> ext;
        map<int, unordered_set<int>> m;
        queue<int> que;
        int num=0;
        for (int i = 0; i < seqs.size(); i++)
        {
            if (!vecIns.count(seqs[i][0]))
                vecIns[seqs[i][0]] = 0;
            for (int j = 0; j < seqs[i].size() - 1; j++)
            {
                if (!vecIns.count(seqs[i][j + 1]))
                    vecIns[seqs[i][j + 1]] = 0;
                if (m.count(seqs[i][j]))
                {
                    int lenset = m[seqs[i][j]].size();
                    m[seqs[i][j]].insert(seqs[i][j + 1]);
                    if (lenset < m[seqs[i][j]].size())
                        vecIns[seqs[i][j + 1]]++;
                }
                else
                {
                    unordered_set<int> tmp = {seqs[i][j + 1]};
                    m[seqs[i][j]] = tmp;
                    vecIns[seqs[i][j + 1]]++;
                }
                ext[seqs[i][j]] = 1;
            }
            // cout<<seqs[i][seqs[i].size()-1]<<endl;
            ext[seqs[i][seqs[i].size() - 1]] = 1;
        }
        map<int, int>::iterator insit;
        map<int, int>::iterator extit;
        for (insit = vecIns.begin(); insit != vecIns.end(); insit++)
        {
            if ( insit->second == 0)
                que.push(insit->first);
        }
        for (extit = ext.begin(); extit != ext.end(); extit++)
        {
            num++;
            if ( extit->second == 0)
                return false;
        }
        // 然后就是拓扑排序
        // 大小不是1的话就不是唯一重建
        if (num>len)
        {
            return false;
        }
        
        int index = 0;
        while (que.size() == 1)
        {

            int front = que.front();
            que.pop();
            if (front != org[index])
                return false;
            index++;

            if (m.count(front))
            {
                unordered_set<int>::iterator it;
                for (it = m[front].begin(); it != m[front].end(); it++)
                {
                    vecIns[*it]--;
                    if (vecIns[*it] == 0)
                        que.push(*it);
                }
            }
        }
        return index == len;
    }
};
int main()
{

    Solution s;
    // vector<int> org = {1, 2, 3};
    // // vector<vector<int>> seqs = {{1, 2}, {1, 3}};
    // vector<vector<int>> seqs = {{1, 2}, {1, 3}, {2, 3}};

    vector<int> org = {4, 1, 5, 2, 6, 3};
    vector<vector<int>> seqs = {{5, 2, 6, 3}, {4, 1, 5, 2}};
    // vector<int> org = {1};
    // vector<vector<int>> seqs = {{2}};
    cout << s.sequenceReconstruction(org, seqs);
}