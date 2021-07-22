import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long sum = 0;
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = sc.nextLong();

        }
        for (int i = 0; i < m; ++i) {
            Arrays.sort(arr);

            sum = arr[0] + arr[1];
            arr[0] = sum;
            arr[1] = sum;
        }
        sum = 0;
        for (int i = 0; i < n; ++i) {

            sum += arr[i];
        }
        System.out.println(sum);

    }
}
