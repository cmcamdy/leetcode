package cmcandy.Java_Language_Answers;

import java.util.HashMap;
import java.util.LinkedList;

/**
 * Created by CHEN on 2020/5/17.
 */
public class _0060_2 {
    //StringBuilder版
    static class Solution {
        public HashMap<Integer, Integer> hashMap = new HashMap<>( );
        public LinkedList<Integer> list = new LinkedList<>( );

        public String getPermutation(int n, int k) {
            if (hashMap.isEmpty( )) setHash(n);
            if (list.isEmpty( )) setList(n);

            return getPer(n,k).toString();
        }

        public  StringBuilder getPer(int n,int k){
            //分治算法
            StringBuilder res =new StringBuilder();
            //如果k>(n-1)!
            if (n > 1) {
                if (k > hashMap.get(n - 1)) {
                    int tmp = k / hashMap.get(n - 1);
                    if (tmp == n) {
                        res.append(list.getLast( ));
                        list.removeLast( );
                        res.append(getPer(n - 1, hashMap.get(n - 1))) ;
                    } else {
                        if (k%hashMap.get(n - 1)==0){
                            res.append(list.get(tmp - 1));
                            //用过了删除
                            list.remove(tmp - 1);
                            res.append(getPer(n - 1, k - (tmp-1) * hashMap.get(n - 1)));
                        }else {
                            res.append(list.get(tmp ));
                            //用过了删除
                            list.remove(tmp );
                            res.append(getPer(n - 1, k - tmp * hashMap.get(n - 1)));
                        }

                    }
                } else if (k <= hashMap.get(n - 1)) {
                    //如果k<(n-1)!,那就是拿第一个
                    res.append(list.getFirst( ));
                    list.removeFirst( );
                    res.append(getPer(n - 1, k));
                }
            } else if (n == 1) {
                res.append(list.getFirst( ));
                list.removeFirst( );
            }
            return res;

        }
        public void setHash(int n) {
            int res = 1;
            hashMap.put(0, 0);
            for (int i = 1; i <= n; i++) {
                res *= i;
                hashMap.put(i, res);
            }
        }

        public void setList(int n) {
            for (int i = 1; i <= n; i++) {
                list.add(i);
            }
        }
    }

    public static void main(String[] args) {

        Solution solution = new Solution( );
        solution.setHash(9);
//        System.out.println(solution.getPermutation(3,1) );
//        System.out.println(solution.getPermutation(3,2) );
//        System.out.println(solution.getPermutation(3,3) );
//        System.out.println(solution.getPermutation(3, 3));
//        System.out.println(solution.getPermutation(3, 4));


        for (int i = 1; i < 6; i++) {
            for (int j = 1; j <= solution.hashMap.get(i); j++) {
                System.out.println(solution.getPermutation(i, j));
            }
        }

    }
}
