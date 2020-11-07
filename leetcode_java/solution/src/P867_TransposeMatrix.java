/**
 *
 * 矩阵转置，easy
 *
 * @author xinfengli
 * @date 2020/11/7
 */
public class P867_TransposeMatrix {
    public int[][] transpose(int[][] A) {
        int m = A.length;
        int n = A[0].length;

        int[][] result = new int[n][m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0;j < n; ++j) {
                result[j][i] = A[i][j];
            }
        }
        return result;
    }

    public static void main(String[] args) {
        P867_TransposeMatrix obj = new P867_TransposeMatrix();
        int[][] A = new int[2][3];
        A[0] = new int[] {1, 2, 3};
        A[1] = new int[] {4, 5, 6};

        int[][] B = obj.transpose(A);
        for (int i = 0; i < B.length; ++i) {
            for (int j = 0; j < B[0].length; ++j) {
                System.out.printf("%d ", B[i][j]);
            }
            System.out.printf("\n");
        }
    }
}
