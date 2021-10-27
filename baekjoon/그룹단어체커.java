import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
      Scanner sc =new Scanner(System.in);
      int n = sc.nextInt();
      String str[] = new String[n];
      boolean check[] = new boolean[32];
     
      
      int count =0;
      for(int i=0;i<n;++i){
          int or = 0;
          str[i]=sc.next();
           for(int k=0;k<32;++k){
             check[k] =false;
            }
          for(int j=0;j<str[i].length()-1; ++j){
              if(str[i].charAt(j) != str[i].charAt(j+1)){
                  if(check[str[i].charAt(j+1)-97] == true){
                      or = 1;
                      break;
                  }
                  check[str[i].charAt(j)-97]=true;
              }
          }
          if(or==0){
              count ++;
          }
          
      }
        System.out.println(count);
    }
    
}
