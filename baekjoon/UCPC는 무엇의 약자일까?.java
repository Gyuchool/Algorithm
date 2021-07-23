import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        String answer = "I hate UCPC";
        int start = s.indexOf("U");
        if( start != -1){
            int second = s.indexOf("C", start);
            if(second != -1){
                int third = s.indexOf("P", second);
                if(third != -1){
                    int fourth = s.indexOf("C", third);
                    if(fourth != -1){
                        answer = "I love UCPC";
                    }
                }
            }
        }
        System.out.println(answer);
    }
}
