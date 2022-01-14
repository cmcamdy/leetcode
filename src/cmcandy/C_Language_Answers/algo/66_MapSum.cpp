#include <iostream>
#include <vector>
#include <map>
using namespace ::std;
class Tire
{
public:
    int wordVal;
    vector<Tire *> children;
    Tire() : wordVal(0), children(26, nullptr) {}
    void insert(const string &str, int val)
    {
        Tire *node = this;
        for (auto &ch : str)
        {
            if (node->children[ch - 'a'] == nullptr)
            {
                node->children[ch - 'a'] = new Tire();
            }
            node = node->children[ch - 'a'];
        }
        node->wordVal = val;
    }
    int dfs(Tire *node)
    {
        if (node == nullptr)
            return 0;
        int ret = node->wordVal;
        for (auto &child : node->children)
        {
            ret += dfs(child);
        }
        return ret;
    }
    int countPreSum(const string &str)
    {
        Tire *node = this;
        for (auto &ch : str)
        {
            if (node->children[ch - 'a'] == nullptr)
            {
                return 0;
            }
            node = node->children[ch - 'a'];
        }
        return dfs(node);
    }
};
class MapSum
{
public:
    /** Initialize your data structure here. */
    Tire *root;
    MapSum()
    {
        root = new Tire();
    }

    void insert(string key, int val)
    {
        root->insert(key, val);
    }

    int sum(string prefix)
    {
        return root->countPreSum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */