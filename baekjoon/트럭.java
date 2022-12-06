import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        int l = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Queue<Integer> q = new LinkedList<>();
        int t = 0;
        int time = 0;
        for (int i = 0; i < arr.length; i++) {
            if (q.size() == w) {
                t-=q.poll();
            }
            if (t + arr[i] <= l) {
                q.add(arr[i]);
                t+=arr[i];
            }else{
                q.add(0);
                i--;
            }
            time++;
        }
        if (!q.isEmpty()) {
            time+=w;
        }
        System.out.println(time);
    }
}
