#include <iostream>
#include <vector>
#include <map>
using namespace ::std;

class Tire
{
public:
    vector<Tire *> children;
    Tire() : children(2, nullptr) {}
    void insert(int num)
    {
        Tire *node = this;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->children[bit] == nullptr)
            {
                node->children[bit] = new Tire();
            }
            node = node->children[bit];
        }
    }
    int search(int num)
    {
        Tire *node = this;
        int ret = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->children[(bit + 1) % 2] == nullptr)
            {
                node = node->children[bit];
            }
            else
            {
                node = node->children[(bit + 1) % 2];
                ret += (1 << i);
            }
        }
        return ret;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Tire *root = new Tire();
        for (auto &num : nums)
        {
            root->insert(num);
        }
        int maxNum = 0;
        for (auto &num : nums)
        {
            maxNum = max(root->search(num), maxNum);
        }
        return maxNum;
    }
};