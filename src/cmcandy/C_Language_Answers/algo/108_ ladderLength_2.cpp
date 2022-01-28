#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace ::std;

class Solution
{
private:
    bool getNeighbor(unordered_set<string> &visted, unordered_set<string> &st1, unordered_set<string> &st2, unordered_set<string> &st3, string &word)
    {
        for (int i = 0; i < word.size(); ++i)
        {
            char temp = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                word[i] = ch;
                if (ch != temp && visted.count(word))
                {
                    if (st2.count(word))
                    {
                        return true;
                    }
                    st3.insert(word);
                }
            }
            word[i] = temp;
        }
        return false;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> visted;
        for (auto &word : wordList)
        {
            visted.insert(word);
        }
        if (!visted.count(endWord))
        {
            return 0;
        }

        unordered_set<string> st1;
        unordered_set<string> st2;
        st1.insert(beginWord);
        st2.insert(endWord);
        int len = 2;

        while (!st1.empty() && !st2.empty())
        {
            if (st1.size() > st2.size())
            {
                swap(st1, st2);
            }

            unordered_set<string> st3;
            for (auto it = st1.begin(); it != st1.end(); ++it)
            {
                string word = *it;
                visted.erase(word);

                if (getNeighbor(visted, st1, st2, st3, word))
                {
                    return len;
                }
            }
            st1 = st3;
            len++;
        }

        return 0;
    }
};