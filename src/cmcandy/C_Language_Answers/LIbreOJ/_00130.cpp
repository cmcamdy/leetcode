
#include <iostream>
#include <vector>
#include <stack>
using namespace ::std;

using LL = long long;
struct BIT
{
    int n;
    vector<LL> v;
    BIT(int n) : n(n+1), v(n + 1) {}

    int lowbit(int x)
    {
        return x & -x;
    }
    void add(int x, LL y)
    {
        while (x <= n)
        {
            v[x] += y;
            x += lowbit(x);
        }
    }
    LL sum(int x)
    {
        // 前缀和
        LL ans = 0;
        while (x >= 1)
        {
            ans += v[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

int main()
{
    int len, time;
    cin >> len >> time;
    // vector<int> num(len);
    BIT bit(len);
    // cout << len << "\t" << time << endl;
    for (int i = 0; i < len; i++)
    {
        int tmp;
        cin >> tmp;
        bit.add(i + 1, tmp);
    }
    // for (int i = 0; i < len; i++)
    // {
    //     cout << num[i];
    // }

    for (int i = 0; i < time; i++)
    {
        LL type, tmp1, tmp2;
        cin >> type >> tmp1 >> tmp2;
        if (type == 1)
            bit.add(tmp1, tmp2);
        else
        {
            cout << bit.sum(tmp2) - bit.sum(tmp1-1);
        }
    }
    stack<int> s;
    s.top
    
}