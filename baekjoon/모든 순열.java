import java.util.*;

public class Main {
    private static void permutation(int[] arr, boolean[] visited, int n, int x){ // nPr

        if(n == x){
            for(int i=0; i<n; ++i){
                System.out.print(arr[i]+" ");
            }
            System.out.println();
            return;
        }

        for(int i=1; i<=n;++i){
            if(!visited[i]){
                visited[i] = true;
                arr[x] = i;
                permutation(arr, visited, n, x+1);
                visited[i] = false;
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr= new int[n+1];
        boolean[] visited = new boolean[n+1];

        permutation(arr,visited, n,0);


    }
}
