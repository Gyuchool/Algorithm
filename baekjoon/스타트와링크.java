//백준 14889
import java.util.*;

public class Main {

    static int n;
    static boolean[] visited;
    static int m=101;
    static int [][]arr;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        List<Integer> score = new ArrayList<>();

        n = sc.nextInt();
        visited = new boolean[n];

        arr = new int [n][n];
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                arr[i][j] = sc.nextInt();
            }
        }
        combination(0,0);
        System.out.println(m);
    }

    static void combination(int id, int count) {
        int sum1=0;
        int sum2=0;
        if(count == n/2){
            for(int i=0; i<n-1; ++i){
                for(int j=i+1; j<n; j++){
                    if(visited[i]==true && visited[j]==true){
                        sum1+=arr[i][j];
                        sum1+=arr[j][i];
                    }
                    else if(visited[i]==false && visited[j] == false){
                        sum2+=arr[i][j];
                        sum2+=arr[j][i];
                    }
                }
            }
            m= Math.min(Math.abs(sum1-sum2),m);
            return;
        }
        for(int i=id;i<n;++i){
            if(!visited[i]){
                visited[i]=true;
                combination(i+1,count+1);
                visited[i]=false;
            }
        }
    }
}
