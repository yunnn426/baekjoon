import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[][] arr = new int[100][100];

        for (int T = 1; T <= 10; T++) {
            int TC = sc.nextInt();

            // 배열 입력
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            
            int[] sum = new int[202]; // 가로합 100개, 세로합 100개, 대각선합 2개

            // 가로 합 
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    sum[i] += arr[i][j];
                }
            }

            // 세로 합
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100; j++) {
                    sum[100+i] += arr[j][i];
                }
            }

            // 대각선 합
            int diag_sum1 = 0; // 좌상->우하
            int diag_sum2 = 0; // 우상->좌하
            for (int i = 0; i < 100; i++) {
                diag_sum1 += arr[i][i];
            }
            sum[200] = diag_sum1;

            for (int i = 0; i < 100; i++) {
                diag_sum2 += arr[99-i][i];
            }
            sum[201] = diag_sum2;

            // 합 중 최대값 구하기
            int max = 0;
            for (int i = 0; i < 202; i++) {
                if (sum[i] > max)
                    max = sum[i];
            }

            System.out.println("#" + T + " " + max);
            
            sc.nextLine();
        }
    }
}
