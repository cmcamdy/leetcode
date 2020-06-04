package cmcandy.java_language_answers;

class Solution {
    private int[] coord;
    private int n;
    private int total;
    public int totalNQueens(int n) {
        //init
            this.n = n;
            //用于存储Q的坐标
            this.coord = new int[n];

            //回朔
            //如果成功则记录，如果失败则进入下一个
            recall(0);
            return total;
    }
    public void recall(int row){
            //到这了说明上面都成功了，设为递归出口吧
            if (row>=this.n) {
                this.total++;
                return;
            }
            //row = 行号
            loop1:for(int i = 0;i<this.n;i++){
                //判断当前是否成立
                for (int j = 0;j<row;j++){
                    //三种情况不成立，分别是竖、左斜、右斜
                    if (coord[j]==i) continue loop1;
                    if (coord[j]<i&&coord[j]-j+row==i)continue loop1;
                    if (coord[j]>i&&coord[j]+j-row==i)continue loop1;
                }
                this.coord[row] = i;
                //如果匹配成功，进入下一行
                recall(row+1);
                this.coord[row] = 0;
            }
            return;
        }
}