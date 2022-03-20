#include <iostream>
#include <string>
#include <map>

using namespace ::std;

int maxProduct(string *words, int len)
{
    map<int, int> m;
    int mask = 0;
    for (int i = 0; i < len; i++)
    {
        mask = 0;
        for (int j = 0; j < words[i].size(); j++ ){
            mask |= 1<<(words[i][j] - 'a');
        }
        if(m.find(mask) != m.end()){
            m[mask] = words[i].size()>m[mask]?words[i].size():m[mask];
        }        
        else
            m[mask] = words[i].size();
    }
    map<int, int>::iterator i,j;
    i = m.begin();
    int res = 0;
    while (i != m.end())
    {
        j = i;
        while (j != m.end())
        {
            if((j->first & i->first) == 0){
                res = max(j->second*i->second,res);
            }
            j++;
        }
        i++;
    }
    return res;
}

int main()
{
    string words[] = {"abcw", "foo", "bar", "fxyz", "abcdef"};
    cout << maxProduct(words, 5);
}