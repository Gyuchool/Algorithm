class Solution {
    public String solution(int a, int b) {
        String answer = "";
        int total = 0;
      String w[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
      int m[] = {31, 29, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
      for(int i =0;i<a-1;i++){
          total += m[i];
      }
      total += b-1;
      answer = w[total%7];
      return answer;
    }
}
