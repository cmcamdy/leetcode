#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace ::std;


// 我就搞不懂了，思路一毛一样，我的就是过不了
class Solution
{
private:
    int findFather(unordered_map<int, int> &fa, int node)
    {
        if (fa[node] == node)
        {
            return node;
        }
        fa[node] = findFather(fa, fa[node]);
        return fa[node];
    }

    int merge(unordered_map<int, int> &fa, unordered_map<int, int> &counts, int node1, int node2)
    {
        int father1 = findFather(fa, node1);
        if (fa.count(node2))
        {
            int father2 = findFather(fa, node2);
            if (father1 != father2)
            {
                fa[father2] = father1;
                counts[father1] += counts[father2];
            }
        }

        return counts[father1];
    }

public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> fa;
        unordered_map<int, int> counts;
        for (auto &n : nums)
        {
            if (!fa.count(n))
            {
                fa[n] = n;
                counts[n] = 1;
            }
        }

        int ret = 0;
        for (auto &n : nums)
        {
            ret = max(ret, merge(fa, counts, n, n - 1));
            ret = max(ret, merge(fa, counts, n, n + 1));
        }

        return ret;
    }
};

int main()
{
    // vector<int> nums = {100, 4, 200, 1, 3, 2};
    // vector<int> nums = {0,-1};
    // vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    // vector<int> nums = {9000, 8999, 8998, 8997, 8996, 8995, 8994, 8993, 8992, 8991, 8990, 8989, 8988, 8987, 8986, 8985, 8984, 8983, 8982, 8981, 8980, 8979, 8978, 8977, 8976, 8975, 8974, 8973, 8972, 8971, 8970, 8969, 8968, 8967, 8966, 8965, 8964, 8963, 8962, 8961, 8960, 8959, 8958, 8957, 8956, 8955, 8954, 8953, 8952, 8951, 8950, 8949, 8948, 8947, 8946, 8945, 8944, 8943, 8942, 8941, 8940, 8939, 8938, 8937, 8936, 8935, 8934, 8933, 8932, 8931, 8930, 8929, 8928, 8927, 8926, 8925, 8924, 8923, 8922, 8921, 8920, 8919, 8918, 8917, 8916, 8915, 8914, 8913, 8912, 8911, 8910, 8909, 8908, 8907, 8906, 8905, 8904, 8903, 8902, 8901, 8900, 8899, 8898, 8897, 8896, 8895, 8894, 8893, 8892, 8891, 8890, 8889, 8888, 8887, 8886, 8885, 8884, 8883, 8882, 8881, 8880, 8879, 8878, 8877, 8876, 8875, 8874, 8873, 8872, 8871, 8870, 8869, 8868, 8867, 8866, 8865, 8864, 8863, 8862, 8861, 8860, 8859, 8858, 8857, 8856, 8855, 8854, 8853, 8852, 8851, 8850, 8849, 8848, 8847, 8846, 8845, 8844, 8843, 8842, 8841, 8840, 8839, 8838, 8837, 8836, 8835, 8834, 8833, 8832, 8831, 8830, 8829, 8828, 8827, 8826, 8825, 8824, 8823, 8822, 8821, 8820, 8819, 8818, 8817, 8816, 8815, 8814, 8813, 8812, 8811, 8810, 8809, 8808, 8807, 8806, 8805, 8804, 8803, 8802, 8801, 8800, 8799, 8798, 8797, 8796, 8795, 8794, 8793, 8792, 8791, 8790, 8789, 8788, 8787, 8786, 8785, 8784, 8783, 8782, 8781, 8780, 8779, 8778, 8777, 8776, 8775, 8774, 8773, 8772, 8771, 8770, 8769, 8768, 8767, 8766, 8765, 8764, 8763, 8762, 8761, 8760, 8759, 8758, 8757, 8756, 8755, 8754, 8753, 8752, 8751, 8750, 8749, 8748, 8747, 8746, 8745, 8744, 8743, 8742, 8741, 8740, 8739, 8738, 8737, 8736, 8735, 8734, 8733, 8732, 8731, 8730, 8729, 8728, 8727, 8726, 8725, 8724, 8723, 8722, 8721, 8720, 8719, 8718, 8717, 8716, 8715, 8714, 8713, 8712, 8711, 8710, 8709, 8708, 8707, 8706, 8705, 8704, 8703, 8702, 8701, 8700, 8699, 8698, 8697, 8696, 8695, 8694, 8693, 8692, 8691, 8690, 8689, 8688, 8687, 8686, 8685, 8684, 8683, 8682, 8681, 8680, 8679, 8678, 8677};
    vector<int> nums;
    for (int i = -999; i <= 90; i++)
    {
        nums.push_back(i);
    }
    Solution s;
    cout << s.longestConsecutive(nums);
}