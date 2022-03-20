
#include <iostream>
#include <vector>

using namespace ::std;

using LL = long long;
struct BIT
{
    int n;
    vector<LL> v;
    BIT(int n) : n(n + 1), v(n + 1) {}

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
    void addInterval(int x, int start, int end, LL y)
    {
        while (x >= 1)
        {
            int tmp = lowbit(x);
            if (x > end)
            {
                v[x] += (tmp + end - x) * y;
            }
            else if (x <= end && x >= start)
            {
                if (x - tmp >= start)
                    v[x] += tmp * y;
                else
                    v[x] += (x - start + 1) * y;
            }
            x -= tmp;
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

// 解答有问题？
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

    for (int i = 0; i < time; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            LL index1, index2, val;
            cin >> index1 >> index2 >> val;
            // for (int i = index1; i <= index2; i++)
            //     bit.add(i, val);
            bit.addInterval(index2, index1, index2, val);
        }
        else
        {
            LL index;
            cin >> index;
            cout << bit.sum(index) - bit.sum(index - 1) << endl;
        }
    }
}