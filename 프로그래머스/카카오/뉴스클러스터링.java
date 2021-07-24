import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
       int answer = 0;
        List<String> A = new ArrayList<>();
        List<String> B = new ArrayList<>();

        List<String> union = new ArrayList<>();
        List<String> intersection = new ArrayList<>();

        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        for (int i = 0; i < str1.length() - 1; i++) {
            if (str1.charAt(i) < 'a' || str1.charAt(i) > 'z' || str1.charAt(i + 1) < 'a' || str1.charAt(i + 1) > 'z')
                continue;
            A.add(str1.substring(i, i + 2));
        }
        for (int i = 0; i < str2.length() - 1; i++) {
            if (str2.charAt(i) < 'a' || str2.charAt(i) > 'z' || str2.charAt(i + 1) < 'a' || str2.charAt(i + 1) > 'z')
                continue;

            B.add(str2.substring(i, i + 2));
        }

        Collections.sort(A);
        Collections.sort(B);

        for (int i = 0; i < A.size(); ++i) {
            if(B.remove(A.get(i))){
                intersection.add(A.get(i));
            }
            union.add(A.get(i));
        }
        union.addAll(B);

        if (union.size() == 0) {
            answer = 65536;

        } else {

            int mo = union.size();

            int ja = intersection.size();

            double result = (double) ja / mo;
            answer = (int) (result * 65536);

        }
        return answer;
    }
}
