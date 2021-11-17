#include <cstdio>
#include <vector>
using namespace ::std;
const int N = 1e5+10;

vector<int> searchRange(int* nums, int len,int target) {
        vector<int> ans(2,-1);
        int flag1=0,flag2=0,a,b;
        // if(len<1)return ans;
        // if(len==1 && nums[0]==target)return {0,0};
        bool test = (len<=3);
        if(test){
            int flag=0;
            int count=0;
            for(int i=0;i<len;i++){
                if(flag==0 && nums[i]==target){
                    flag=1;
                    ans[0]=i;
                }
                else if(flag==1 && nums[i]==target){
                    count++;
                }
               
            }
            ans[1]=ans[0]+count;
            
            return ans;
        }
        int low=0;
        int high=len-1;
        int temp=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                temp=mid;
                break;
            }
            if(target<nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(temp==-1)return ans;
        a=temp,b=temp;
        while(flag1!=1 || flag2 !=1){
            if(a-1>=0){
                if(nums[a-1]==target){
                    a--;
                }
                else{
                    flag1=1;
                }
            }
            else{
                flag1=1;
            }
            if(b+1<=len-1){
                if(nums[b+1]==target){
                    b++;
                }
                else{
                    flag2=1;
                }
            }
            else{
                flag2=1;
            }
        }
        ans[0]=a;
        ans[1]=b;
        return ans;
    }
int main()
{
    int nlen, tlen,nums[N],index,target,last = -1,left,right;
    vector<int> res;
    scanf("%d %d", &nlen, &tlen);
    bool test1,test2;
    for (int i = 0; i < nlen; ++i)
        scanf("%d", &nums[i]);

    while (tlen--)
    {
        scanf("%d", &target);
        // searchRange(nums, target, 0, nlen - 1);
        res = searchRange(nums,nlen,target);
        printf("%d %d\n", res[0], res[1]);
    }
    return 0;
}


void quick_sort(int** array,int left,int right){
    int jud = 0,now=left;
    int nl=left+1,nr=right;
    
    while(nl<nr){
        if(jud==0){
            if(array[nr][1]<array[now][1]){
                int tmp = array[nr][1];
                array[nr][1] = array[now][1];
                array[now][1] = tmp;
                now = nr--;
                jud = 1;
            }
            else{
                nr--;
            }
        }else {
            if(array[nl][1]>=array[now][1]){
                int tmp = array[nl][1];
                array[nl][1] = array[now][1];
                array[now][1] = tmp;
                now = nl++;
                jud = 1;
            }
            else{
                nl++;
            }
        }
    }   
}