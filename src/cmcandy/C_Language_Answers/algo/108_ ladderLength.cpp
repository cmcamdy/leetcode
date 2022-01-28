#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace ::std;

class Solution
{
    void getNeighbor(unordered_set<string> &visted, string &word, queue<string> &que)
    {
        for (int i = 0; i < word.size(); ++i)
        {
            char temp = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                word[i] = ch;
                if (ch != temp && visted.count(word))
                    que.push(word);
            }
            word[i] = temp;
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> visted;
        for (auto &word : wordList)
            visted.insert(word);
        if (!visted.count(endWord))
            return 0;
        // 单向 BFS
        queue<string> que;
        que.push(beginWord);
        int len = 0;
        while (!que.empty())
        {
            int size = que.size();
            len++;
            while (size--)
            {
                string word = que.front();
                que.pop();
                visted.erase(word);
                if (word == endWord)
                    return len;
                getNeighbor(visted, word, que);
            }
        }
        return 0;
    }
};
