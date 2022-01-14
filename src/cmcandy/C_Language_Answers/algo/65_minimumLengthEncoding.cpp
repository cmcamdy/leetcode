#include <iostream>
#include <vector>
#include <map>
using namespace ::std;

class Tire
{
public:
    vector<Tire *> children;
    Tire() : children(26, nullptr) {}
    bool insert(const string &str)
    {
        bool isPre = true;
        Tire *node = this;
        for (int i = str.size(); i >= 0; i--)
        {
            if (node->children[str[i] - 'a'] == nullptr)
            {
                node->children[str[i] - 'a'] = new Tire();
                isPre = false;
            }
            node = node->children[str[i] - 'a'];
        }
        return isPre;
    }
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        Tire *root = new Tire();
        int nowLen = 0;
        // for(auto& word : words){
        //     bool isPre = root->insert(word);
        //     if(!isPre) nowLen += word.size()+1;
        // }
        for (int i = 0; i < words.size(); i++)
        {
            bool isPre = root->insert(words[i]);
            if (!isPre)
                nowLen += words[i].size() + 1;
        }
        return nowLen;
    }
};
int main()
{
    vector<string> words = {"time", "me", "bell"};
    // vector<string> words = {"t"};
    Solution s;
    cout << s.minimumLengthEncoding(words);
}