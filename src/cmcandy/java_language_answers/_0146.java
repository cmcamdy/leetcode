package cmcandy.java_language_answers;

/**
 * Created by CHEN on 2020/6/25.
 */
public class _0146 {
    static class LRUCache {

        private int[][] cache;
        private int row;

        public LRUCache(int capacity) {
            cache = new int[capacity][3];
            for (int i = 0; i < capacity; i++) {
                cache[i][0] = -1;
            }
            row = capacity;
        }

        public int get(int key) {
            int res = -1;
            for (int i = 0; i < this.row; i++) {
                if (cache[i][0] == key) {
                    cache[i][1] = 0;
                    res = cache[i][2];
                } else if (cache[i][0] == -1) {
                    break;
                } else {
                    cache[i][1]++;
                }
            }
            return res;
        }

        public void put(int key, int value) {
            int max = -1;
            int index = -1;
            boolean find = false;
            for (int i = 0; i < this.row; i++) {
                if (cache[i][0] == key) {
                    cache[i][1] = 0;
                    cache[i][2] = value;
                    index = -1;
                    find = true;
                } else if (cache[i][0] == -1&&!find) {
                    cache[i][0] = key;
                    cache[i][1] = 0;
                    cache[i][2] = value;
                    return;
                } else {
                    cache[i][1]++;
                    if (max < cache[i][1]&&!find) {
                        max = cache[i][1];
                        index = i;
                    }
                }
            }
            if (index != -1) {
                cache[index][0] = key;
                cache[index][1] = 0;
                cache[index][2] = value;
            }
        }
    }

    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache obj = new LRUCache(capacity);
     * int param_1 = obj.get(key);
     * obj.put(key,value);
     */

}
