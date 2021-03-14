#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1001][1001];

int main() {
   string main_str, sub_str;
   string tmp = "";

   cin >> main_str >> sub_str;
  
   main_str = "0" + main_str;
   sub_str = "0" + sub_str;

   int main_len = main_str.length();
   int sub_len = sub_str.length();

   for (int i = 1; i < main_len; ++i) {//길이 찾기
	   for (int j = 1; j < sub_len; ++j) {
		   if (main_str[i] == sub_str[j]) {
								
			   dp[i][j] = dp[i - 1][j - 1] + 1;

		   }
		   else {

			   dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

		   }		
	   }
	
   }

   int lcs_len = dp[main_len - 1][sub_len - 1];
   int temp1 = lcs_len;
   int temp2 = temp1 - 1;
   string lcs_str = "";

   for (int i = main_len-1; i > 0; --i) {//문자 찾기
	   for (int j = sub_len-1; j >0; --j) {
		   if (dp[i][j] == temp1 && dp[i - 1][j] == temp2 && dp[i - 1][j - 1] == temp2 && dp[i][j - 1] == temp2) {
		
			   temp2--;
			   temp1--;
			   lcs_str = main_str[i] + lcs_str;
			   break;
			
		   }		
	   }
	
   }

   if (lcs_len == 0) {
	   cout << lcs_len;
   }

   else {
	   cout << lcs_len << endl;//공통 문자 길이
	   cout << lcs_str;//공통 문자
	
   }

	return 0;
}
