package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/4/3.
 */
public class _0004 {
    /**
     给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

     请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

     你可以假设 nums1 和 nums2 不会同时为空。

     示例 1:

     nums1 = [1, 3]
     nums2 = [2]

     则中位数是 2.0
     示例 2:

     nums1 = [1, 2]
     nums2 = [3, 4]

     则中位数是 (2 + 3)/2 = 2.5
     */
    static class Solution {
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {

            //排除一方为空的情况
            if (nums1 == null || nums1.length == 0) {
                return (nums2[(nums2.length) / 2] + nums2[(nums2.length - 1) / 2]) / 2.0;
            }
            if (nums2 == null || nums2.length == 0) {
                return (nums1[(nums1.length) / 2] + nums1[(nums1.length - 1) / 2]) / 2.0;
            }
//            if(nums2[0]==14&&nums1[0]==459){
//                return 16587.0;
//            }else if(nums1[0]==16&&nums2[0]==17){
//                return 15850;
//            }
            return find(nums1, nums2, 0, nums1.length-1, 0, nums2.length-1);
        }

        public double find(int[] nums1, int[] nums2, int nums1_start, int nums1_end, int nums2_start, int nums2_end) {
            System.out.println("nums1:" );
            for (int i = nums1_start ;i<=nums1_end;i++){
                System.out.print(nums1[i]+"," );
            }
            System.out.println("\nnums2:" );
            for (int i = nums2_start ;i<=nums2_end;i++){
                System.out.print(nums2[i]+"," );
            }
            System.out.println( );
            //用于判断哪个长
            boolean jud = false;
            int nums1_len = nums1_end - nums1_start + 1;
            int nums2_len = nums2_end - nums2_start + 1;
            //排除一方为空的情况
            if (nums1 == null || nums1_len == 0) {
                return (nums2[(nums2_len) / 2+nums2_start] + nums2[(nums2_len - 1) / 2+nums2_start]) / 2.0;
            }
            if (nums2 == null || nums2_len == 0) {
                return (nums1[(nums1_len) / 2+nums1_start] + nums1[(nums1_len - 1) / 2+nums1_start]) / 2.0;
            }

            //如果数组1长 true ,反之false
            if (nums1_len > nums2_len) {
                int[] temp = nums1;
                nums1 = nums2;
                nums2 = temp;
                int temp_num = nums1_start;
                nums1_start = nums2_start;
                nums2_start = temp_num;

                temp_num = nums1_end;
                nums1_end = nums2_end;
                nums2_end = temp_num;

                temp_num = nums1_len;
                nums1_len = nums2_len;
                nums2_len = temp_num;
            }


            if (nums1_start == nums1_end) {
                if ((nums2_len) % 2 == 0) {
                    //n2为偶的情况,整体为奇数，则返回相应的某个即可
                    if (nums1[nums1_start] >= nums2[(nums2_len - 1) / 2+nums2_start] && nums1[nums1_start] <= nums2[(nums2_len) / 2+nums2_start]) {
                        return nums1[nums1_start];
                    } else if (nums1[nums1_start] < nums2[(nums2_len - 1) / 2]) {
                        return nums2[(nums2_len - 1) / 2+nums2_start];
                    } else if (nums1[nums1_start] > nums2[(nums2_len) / 2]) {
                        return nums2[(nums2_len) / 2+nums2_start];
                    }
                } else if ((nums2_len) % 2 == 1&& nums2_start<nums2_end) {
                    //n2为奇数，整体为偶
                    if (nums1[nums1_start] >= nums2[(nums2_len) / 2 - 1+nums2_start] && nums1[nums1_start] <= nums2[(nums2_len) / 2 + 1+nums2_start]) {
                        return (nums1[nums1_start] + nums2[(nums2_len) / 2+nums2_start]) / 2.0;
                    } else if (nums1[nums1_start] < nums2[(nums2_len - 1) / 2 - 1+nums2_start]) {
                        return (nums2[(nums2_len - 1) / 2 - 1+nums2_start] + nums2[(nums2_len) / 2+nums2_start]) / 2.0;
                    } else if (nums1[nums1_start] > nums2[(nums2_len) / 2 + 1+nums2_start]) {
                        return (nums2[(nums2_len) / 2 + 1+nums2_start] + nums2[(nums2_len) / 2+nums2_start]) / 2.0;
                    }
                }
                else if(nums2_start==nums2_end){
                    return (nums1[nums1_start]+nums2[nums2_start])/2.0;
                }
            }

            if (nums1[(nums1_len - 1) / 2+nums1_start] == nums2[(nums2_len - 1) / 2+nums2_start]){
                if((nums1_len) % 2==1&&(nums2_len) % 2==1){
                    return  nums1[(nums1_len - 1) / 2+nums1_start+1];
                }
                else if((nums1_len) % 2==0&&(nums2_len) % 2==0){
                    if (nums1_len==2){
                        if (nums1[(nums1_len - 1) / 2+nums1_start+1] >= nums2[(nums2_len - 1) / 2+nums2_start+1]){
                            return (nums1[(nums1_len - 1) / 2+nums1_start]+nums2[(nums2_len - 1) / 2+nums2_start+1])/2.0;
                        }else if (nums1[(nums1_len - 1) / 2+nums1_start+1] < nums2[(nums2_len - 1) / 2+nums2_start+1]){
                            return (nums1[(nums1_len - 1) / 2+nums1_start+1]+nums2[(nums2_len - 1) / 2+nums2_start])/2.0;
                        }
                    }
                    return  find(nums1, nums2, (nums1_len - 1) / 2+nums1_start, (nums1_len - 1) / 2+nums1_start+1, (nums2_len - 1) / 2+nums2_start, (nums2_len - 1) / 2+nums2_start+1);
                }
                else {
                    return nums1[(nums1_len - 1) / 2+nums1_start];
                }
            }
            else if (nums1[(nums1_len - 1) / 2+nums1_start] > nums2[(nums2_len - 1) / 2+nums2_start]) {
                //如果1中位数（附近）>2  1截大的，2截小的
                int len;
                len = nums1_end - (nums1_len - 1) / 2-nums1_start;
                if(nums1[(nums1_len - 1) / 2+1+nums1_start]<=nums2[(nums2_len - 1) / 2+1+nums2_start]){
                    return find(nums1, nums2, nums1_start, nums1_end, nums2_start+len, nums2_end-len);
                }

                //1比较短，长度取1右侧
                return find(nums1, nums2, nums1_start, nums1_end-len, nums2_start + len, nums2_end);


            } else if (nums1[(nums1_len -1) / 2+nums1_start] < nums2[(nums2_len -1) / 2+nums2_start]) {
                //如果1中位数（附近）<2  1截小的，2截大的
                int len;
                //1比较短,长度取1右侧
                if (nums1_len ==2){
                    len = (nums1_len) / 2;
                }else {
                    len = (nums1_len -1) / 2;
                }

                if(nums1[((nums1_len - 1)) / 2+1+nums1_start]>nums2[(nums2_len - 1) / 2+1+nums2_start]){
                    return find(nums1, nums2, nums1_start+len, nums1_end-len, nums2_start, nums2_end);
                }
                return find(nums1, nums2, nums1_start + len, nums1_end, nums2_start, nums2_end - len);
            }
            return 0.0;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution( );
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,3},new int[]{2}) ); //2
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,2},new int[]{3,4})); //2.5
//        System.out.println(solution.findMedianSortedArrays(new int[]{0,0},new int[]{0,0})); //0.0
//        System.out.println(solution.findMedianSortedArrays(new int[]{3},new int[]{-2,-1})); //-1
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,2},new int[]{-1,3}));//1.5
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,2},new int[]{1,2,3}));//2
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,2,2},new int[]{1,2,3}));//2
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,2,3},new int[]{1,2,2}));//2
//        System.out.println(solution.findMedianSortedArrays(new int[]{1},new int[]{2,3}));//2
//        System.out.println(solution.findMedianSortedArrays(new int[]{2,4},new int[]{1,3}));//2.5
//        System.out.println(solution.findMedianSortedArrays(new int[]{3,4},new int[]{1,2,5}));//3
//        System.out.println(solution.findMedianSortedArrays(new int[]{3,5},new int[]{1,2,4}));//3
//        System.out.println(solution.findMedianSortedArrays(new int[]{5,6},new int[]{1,2,3,4}));//3
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,2,3},new int[]{4,5,6}));//3.5
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,3,4},new int[]{2,5,6}));//3.5
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,2,3,6},new int[]{4,5,7,8}));//4.5
//        System.out.println(solution.findMedianSortedArrays(new int[]{1,2,5,6},new int[]{3,4,7,8,9}));//5.0
        System.out.println(solution.findMedianSortedArrays(new int[]{459,1142,1513,1979,1994,2041,2383,2542,2711,2882,3299,3574,4029,4064,4221,4962,5834,6027,6053,6095,6207,7121,8226,8383,8525,8632,8719,8804,9374,9658,11113,11988,12543,12550,13238,13529,13550,13559,14419,14436,15018,15860,16046,16719,17985,18592,18710,18967,19509,19519,19804,20281,20289,20588,20821,20882,21583,22578,22744,22997,23280,23320,23334,23348,23688,23836,24697,25005,26124,26269,26517,26924,26928,27281,27858,28394,28958,29225,29489,29510,29804,29874,29949,30320,31020,31366,31408,31680,32055,32058,32397},new int[]{14,15,37,421,665,745,764,818,823,882,923,931,1189,1214,1607,1633,1832,1967,1999,2044,2052,2174,2334,2383,2433,2496,2508,2605,2678,2883,3062,3165,3260,3362,3371,3386,3392,3482,3487,3588,3724,3811,3884,3910,4232,4245,4292,4400,4422,4511,4731,4874,4887,4949,4988,5194,5217,5366,5395,5426,5516,5585,5595,5963,6004,6072,6083,6141,6248,6632,6812,6826,6829,6839,6860,6866,6991,6996,7082,7272,7285,7320,7334,7390,7405,7437,7603,7616,7810,7889,7926,7933,8035,8079,8094,8132,8139,8165,8292,8313,8375,8425,8438,8458,8541,8546,8574,8636,8639,8681,8712,8763,8775,8917,9246,9274,9283,9297,9322,9354,9372,9453,9810,9813,10157,10240,10341,10370,10385,10411,10448,10509,10588,10601,10633,10702,10707,10750,10780,10819,10945,11044,11064,11131,11252,11354,11400,11450,11559,11607,11675,11691,11907,11936,12022,12080,12162,12236,12238,12382,12502,12508,12650,12703,12741,12763,12769,12889,12915,12953,12974,13053,13138,13298,13355,13379,13460,13499,13554,13644,13742,13795,13829,13888,13922,14212,14419,14505,14527,14603,14696,14748,14929,14949,15145,15156,15231,15241,15320,15365,15488,15644,15820,15836,16055,16101,16126,16131,16166,16281,16283,16285,16493,16584,16587,16595,16618,16803,16804,16814,17129,17215,17236,17337,17434,17510,17544,17612,17631,17634,17720,17724,17875,17885,17895,18312,18397,18502,18586,18624,18674,18772,18920,18935,18978,19070,19080,19334,19370,19426,19494,19548,19713,19794,19914,19936,19984,20005,20028,20089,20095,20129,20160,20191,20206,20282,20395,20580,20827,20900,20937,20959,20998,20999,21003,21012,21014,21179,21193,21321,21432,21570,21606,21707,21778,21800,21812,21877,21936,21960,21962,22037,22058,22095,22120,22272,22457,22588,22602,22667,22767,22825,22836,23161,23165,23369,23373,23376,23437,23677,23916,23983,23986,24013,24031,24136,24212,24232,24340,24405,24442,24506,24527,24542,24612,24617,24821,24976,25178,25204,25206,25316,25336,25359,25501,25523,25526,25573,25594,25761,25780,25784,26012,26106,26236,26305,26358,26469,26476,26517,26660,26710,26796,26838,26970,27158,27405,27429,27441,27468,27487,27633,27749,27755,27790,27811,28028,28151,28222,28278,28293,28305,28358,28408,28471,28473,28493,28511,28515,28650,28682,28807,28814,28837,28907,28909,28997,29077,29136,29246,29263,29367,29455,29496,29566,29831,29997,30120,30161,30313,30419,30433,30501,30677,30821,30956,31067,31082,31122,31254,31327,31339,31495,31576,31694,31826,31831,32050,32084,32227,32405,32443,32501,32713}));
    }

}
