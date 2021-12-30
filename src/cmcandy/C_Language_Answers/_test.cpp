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
    uchar *bgr_c = srcImage.ptr<uchar>(j);
    
    int r1 = *(bgr_c+2), g1 = *(bgr_c+1), b1 = *(bgr_c+0);
    int r2 = *(bgr_c+5), g2 = *(bgr_c+4), b2 = *(bgr_c+3);
    
    b1 = *(bgr_c+0)
    g1 = *(bgr_c+1)
    r1 = *(bgr_c+2)
    b2 = *(bgr_c+3)
    g2 = *(bgr_c+4)
    r2 = *(bgr_c+5)
    
    int y1 = int(0.257 * r1 + 0.504 * g1 + 0.098 * b1 + 16);
    int v1 = int(0.439 * r1 - 0.368 * g1 - 0.071 * b1 + 128);
    test(count);
    test2(count);

    cout << "helloworld" <<endl;
    return 0;
}
