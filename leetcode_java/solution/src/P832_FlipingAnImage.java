/**
 * 1. 水平翻转图片，以中心轴为线对称
 * 2. bit 翻转
 *
 * @author xinfengli
 * @date 2020/11/7
 */
public class P832_FlipingAnImage {
    public int[][] flipAndInvertImage(int[][] A) {
        int m = A.length;
        int n = A[0].length;

        int[][] result = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 同时处理两个操作
                result[i][j] = 1 - A[i][n-1-j];
            }
        }
        return  result;
    }
}
