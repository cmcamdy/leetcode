#include <iostream>
#include <vector>
using namespace ::std;

int myPow(int base, int k)
{
    base = base % 1337;
    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans = (ans * base) % 1337;
    }
    return ans;
}
int superPow(int a, vector<int> &b)
{
    if (b.empty())
        return 1;

    int last = b.back();
    b.pop_back();

    int part1 = myPow(a, last);
    int part2 = myPow(superPow(a, b), 10);
    return part1 * part2 % 1337;
}
int main(int argc, char const *argv[])
{

    int tmp;
    // vector<int>b = {3};
    vector<int> b;
    int a;
    cin >> a;
    string strTest = "";
    cin >> strTest;
    // cout<<strTest<<endl;
    int len = strTest.size();
    for (int i = 1; i < len; i += 2)
    {
        b.push_back(int(strTest[i] - '0'));
    }
    cout << superPow(a, b);
    return 0;
}