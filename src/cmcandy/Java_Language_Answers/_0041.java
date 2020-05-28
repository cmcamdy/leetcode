package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/14.
 */
public class _0041 {

    static class Solution {
        public int firstMissingPositive(int[] nums) {


            int len = nums.length - 1;
            int res = 0;
            int tmp = 0;
            while (res <= len) {

                //表示在正确的位置上，不用替换
                if (nums[res] == res + 1) {
                    res++;
                } else {
                    tmp = nums[res];
                    //nums[tmp-1] == tmp? tmp位置的值已经为tmp 可以不用替换，不加的话，碰到两个一样的值会陷入死循环的情况
                    if (tmp > len + 1 || tmp < res + 1 || nums[tmp - 1] == tmp) {
                        nums[res] = nums[len--];
                    } else {
                        //需要吧tmp-1位置上的数交换到
                        nums[res] = nums[tmp - 1];
                        nums[tmp - 1] = tmp;
                    }

                }

            }


            return res + 1;
        }
    }
        public static void main(String[] args) {

        }


    }
