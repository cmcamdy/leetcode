package cmcandy.Java_Language_Answers;

/**
 * Created by CHEN on 2020/5/18.
 */
public class _0065 {
    static class Solution {
        public int make(char c) {
            switch(c) {
                case ' ': return 0;
                case '+':
                case '-': return 1;
                case '.': return 3;
                case 'e': return 4;
                default:
                    if(c >= 48 && c <= 57) return 2;
            }
            return -1;
        }

    public boolean isNumber(String s) {
        int state = 0;
        int finals = 0b101101000;//360;0b=16进制
        int[][] transfer = new int[][]{
                { 0, 1, 6, 2,-1},
                {-1,-1, 6, 2,-1},
                {-1,-1, 3,-1,-1},
                { 8,-1, 3,-1, 4},
                {-1, 7, 5,-1,-1},
                { 8,-1, 5,-1,-1},
                { 8,-1, 6, 3, 4},
                {-1,-1, 5,-1,-1},
                { 8,-1,-1,-1,-1}};
        char[] ss = s.toCharArray();
        for(int i=0; i < ss.length; ++i) {
            int id = make(ss[i]);
            if (id < 0) return false;
            state = transfer[state][id];
            if (state < 0) return false;
        }
        return (finals & (1 << state)) > 0;
    }
}

    public static void main(String[] args) {
        Solution solution = new Solution( );
//        System.out.println(solution.isNumber("0"));
//        System.out.println(solution.isNumber(".1"));
//        System.out.println(solution.isNumber(".."));
//        System.out.println(solution.isNumber("2e0"));
//        System.out.println(solution.isNumber(".e1"));
//        System.out.println(solution.isNumber("4e+"));
//        System.out.println(solution.isNumber("+.8"));
//        System.out.println(solution.isNumber("0e"));
        int finals = 0b101101000;
        for (int i =1;i<9;i++){

            System.out.println(finals);
            System.out.println(1<<i);
            System.out.println(finals&(1<<i));

            System.out.println( );
        }

    }
}
