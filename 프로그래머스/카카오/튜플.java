import java.util.*;
import java.util.Comparator;

class Solution {
    
    public int[] solution(String s) {
        Comparator<String> compare = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.length() - o2.length();
            }
        };

        int[] answer = {};

        List<String> arr = new ArrayList<>();
        String tmp = s.substring(1, s.length() - 1);
        String[] tuple = tmp.split("}");
        for (int i=0; i<tuple.length; ++i) {
            int index = tuple[i].indexOf("{");
            tuple[i] = tuple[i].substring(index+1);
        }
        Arrays.sort(tuple,compare);
        answer = new int[tuple.length];
        arr.add(tuple[0]);

        for(int i=1; i<tuple.length; ++i){
            String[] split = tuple[i].split(",");
            for(int j=0;j<split.length; ++j){
                if(!arr.contains(split[j])){
                    arr.add(split[j]);
                }
            }
        }
        int k=0;
        for(String x : arr) {
            answer[k++] = Integer.parseInt(x);
        }
        return answer;
    }
}
