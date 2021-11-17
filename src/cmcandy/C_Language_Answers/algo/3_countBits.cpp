#include <iostream>
using namespace ::std;
const int num = 100;
int *countBits1(int, int *);
int *countBits2(int, int *);

int *countBits1(int num, int *res)
{
    // int res[num + 1];
    res[0] = 0;
    for (int i = 1; i <= num; i++)
    {
        // 关键是这句，主要作用是,
        //  对于没有进位(末尾从0变1)，1的个数比前面一个多1，恰好i & (i - 1)=i-1
        //  对于有进位的情况（末尾从1变0），进位可以看成对低n位的清0，在没清0的第一位+1，此时i & (i - 1)可以帮助回到那一位+1之前的下标
        //  11&10=10 =>res[2]+1
        //  1000&0111 =>res[0]+1=1
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}
int *countBits2(int num, int *res)
{
    res[0] = 0;
    for (int i = 0; i <= num; i++)
    {
        //  这个递推式比较好理解，由于是正向遍历，因此可以保证res[i >> 1]都被访问过，那么res[i]和res[i >> 1]关于1的个数的差别就在于最后一位，加上就是。
        res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}

int main()
{

    int res[num + 1];
    countBits2(num, res);
    for (int i = 0; i <= num; i++)
    {
        cout << res[i] << endl;
    }
    return 0;
}