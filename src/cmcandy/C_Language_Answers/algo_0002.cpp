#include <iostream>
#include <algorithm>
using namespace::std;
/**
 * the kth number
 * Problem description
Find the kth largest element in an unsorted array A . Note that it is the kth largest element in the sorted order, not the kth distinct element. The range of length of A is N(1≤N≤5,000,000) and the element (integer) in A is no bigger than 10,000,00000.

Input
Line 1: the length of the unsorted array A and the index k. Line 2: the all elements in array A and split by spaces

Output
Line 1: A single integer that is the kth largest element in an unsorted array A.

Sample Input 1
8 2
1 3 5 7 4 2 6 8
Sample Output 1
7
Sample Input 2
8 2
1 1 2 2 3 3 4 4
Sample Output 2
4
 */
int quicksort(int num[],int left,int right){
    cout<<num[0];
	int sen = left;
	int jud = 1;
	while(left<right){
		if (jud == 1)
		{
			//如果右侧比哨兵小，则交换到左侧
			if(num[right]<num[sen]){
				int tmp = num[right];
				num[right] = num[sen];
				num[sen] = tmp;
				jud = 0;
			}
			right--;
		}
		else if (jud == 0)
		{
			/* code */
			if(num[left]>=num[sen]){
				int tmp = num[left];
				num[left] = num[sen];
				num[sen] = tmp;
				jud = 1;
			}
			left++;
		}
	}
	return left;
}
int main(){

	int a,b;
	cin>>a>>b;
	int num[a];
	for(int i = 0; i < a; i++){
		cin>>num[i];
	}
	// sort(num,num+a);
	int ind = quicksort(num,0,a);
	int left=0,right=a-1;
	while (ind != a-b)
	{
		/* code */
		if(ind < a-b){
			left = ind+1;
			ind = quicksort(num,left,right);
		}
		if(ind > a-b){
			right = ind-1;
			ind = quicksort(num,left,right);
		}
	}
	cout<<num[a-b];

}