#include <iostream>
#include <string>
using namespace ::std;

string addBinary(string, string);

string addBinary(string a, string b)
{
    string result = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0)
    {
        int dightA = i >= 0 ? a[i--] - '0' : 0;
        int dightB = j >= 0 ? b[j--] - '0' : 0;
        int sum = dightA + dightB + carry;
        carry = sum >= 2 ? 1 : 0;
        sum = sum >= 2 ? sum - 2 : sum;
        result = to_string(sum) + result;
    }
    if (carry==1)
    {
       result = to_string(carry) + result;
    }
    return result;
}

int main(){
    cout<< addBinary("11110000","10001111");
}