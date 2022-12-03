import java.util.Scanner;
import java.util.Stack;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            int input = sc.nextInt();
            if (input == 0) {
                stack.pop();
            }else{
                stack.add(input);
            }
        }
        int sum=0;
        for (var value : stack) {
            sum+=value;
        }
        System.out.println(sum);
    }
}
