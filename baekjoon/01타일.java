import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int[] dp = new int[1000001];
		int n;
		Scanner sc = new Scanner(System.in);
    	n = sc.nextInt();
    	dp[0] = 0;
    	dp[1] = 1;
    	dp[2] = 2;
    	for(int i=3; i<=n; ++i){
	    	dp[i] = (dp[i-1]+dp[i-2])%15746;
		}
		System.out.println(dp[n]%15746);
    
	}
}
