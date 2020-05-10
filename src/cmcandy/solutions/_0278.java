package cmcandy.solutions;

/**
 * Created by CHEN on 2020/5/7.
 */
public class _0278 {
     /* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

    /**

    static public class Solution extends VersionControl {
        public int firstBadVersion(int n) {
            return find(1,n);
        }

        public int find(int first,int last){
            if(first+1==last||first==last){
                if(isBadVersion(first)==false&&isBadVersion(last)) return last;
                else if(isBadVersion(first)) return first;
            }
            //int mid = (first+last)/2;会报超时
            int mid = first+(last-first)/2;
            if(isBadVersion(mid)) return find(first,mid);
            else if(!isBadVersion(mid)) return find(mid,last);
            return -1;
        }
    }
     */
}
