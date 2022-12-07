import static java.lang.Math.max;

import java.util.Scanner;

public class Main{

    private static final int[] dp = new int[10001];
    private static final int[] arr = new int[10001];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }

        dp[1] = arr[1];
        dp[2] = max(dp[1], arr[1] + arr[2]);
        dp[3] = max(dp[2], max(arr[1], arr[2]) + arr[3]);

        for (int i = 4; i <= n; i++) {
            dp[i] = max(max(arr[i - 1] + dp[i - 3], dp[i - 2]) + arr[i], dp[i-1]);
        }
        System.out.println(dp[n]);
    }

}
