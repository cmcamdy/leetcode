
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace ::std;
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> dead;
        unordered_set<string> visited;
        for (auto &word : deadends)
        {
            dead.insert(word);
        }

        queue<string> q1;
        queue<string> q2;
        string init = "0000";
        if(dead.count(init)) return -1;
        else if(init==target) return 0;
        q1.push(init);
        visited.insert(init);
        int step = 1;
        while (!q1.empty())
        {
            while (!q1.empty())
            {
                string temp = q1.front();
                q1.pop();
                for (int i = 0; i < 4; i++)
                {
                    string temp1 = temp;
                    temp1[i] +=  1;
                    if(temp1[i]>'9') temp1[i]-=10;
                    if (temp1 == target)
                        return step;
                    if (!dead.count(temp1)  && !visited.count(temp1) )
                    {
                        q2.push(temp1);
                        visited.insert(temp1);
                    }
                    temp1[i] -= 2;
                    if (temp1[i] < '0')
                        temp1[i] += 10;
                    if (temp1 == target)
                        return step;
                    if (!dead.count(temp1)  && !visited.count(temp1))
                    {
                        q2.push(temp1);
                        visited.insert(temp1);
                    }
                }
            }
            step++;
            swap(q1, q2);
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<string> deadword = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    cout << s.openLock(deadword, "8888");

    // vector<string> deadword = {"0201","0101","0102","1212","2002"};
    // cout << s.openLock(deadword, "0202");
}