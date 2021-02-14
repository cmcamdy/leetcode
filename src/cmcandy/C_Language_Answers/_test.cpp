#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace::std;

void alloc(int count){
    if(count >=10){
        return;
    }else{
        int x[300000];
        char* b = (char*)malloc(300000*sizeof(char));
        // int x[30000];
        // char* b = (char*)malloc(30000*sizeof(char));
        // int *x = new int[300000];
        // char* b = new char[300000];
        printf("addr1 %p addr2 %p\n" ,x,b);
        alloc(++count);
    }
}

int main(int argc, char const *argv[])
{
    alloc(0);
    return 0;
}
