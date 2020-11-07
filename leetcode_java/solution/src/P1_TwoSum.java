import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 基本思路：用 Hash 表存储每个数字的倒排索引，根据 remain 值直接查找即可
 * 备注：如果使用暴力循环，复杂度是O(n^2)，部分 case 会出现 TLE.
 *
 * @author xinfengli
 * @date 2020/11/7
 */
public class P1_TwoSum {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        result[0] = -1;
        result[1] = -1;

        int n = nums.length;

        Map<Integer, List<Integer>> hash = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int key = nums[i];
            if (hash.containsKey(key)) {
                hash.get(key).add(i);
            } else {
                hash.put(key, new ArrayList<Integer>());
                hash.get(key).add(i);
            }
        }

        for (int i = 0; i < n; ++i) {
            int remain = target - nums[i];
            if (hash.containsKey(remain)) {
                List<Integer> valList = hash.get(remain);
                for (int j : valList) {
                    if (j != i) {
                        result[0] = i;
                        result[1] = j;
                        return result;
                    } else {
                    }
                }

            } else {
            }
        }
        return result;
    }
}
