#include <iostream>
#include <vector>
using namespace ::std;

void test(int count[]){
    
}
void test2(int* count){
    cout<<count[99];
}


int main(int argc, char const *argv[])
{
    int a = 0;
    int count[100];
    
    test(count);
    test2(count);

    cout << "helloworld" <<endl;
    return 0;
}
