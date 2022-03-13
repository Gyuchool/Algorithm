import java.util.*;

class Solution {
  public static int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = {};
        answer = new int[id_list.length];
        Map<String, List<String>> reportFromTomap = new LinkedHashMap<>();
        Map<String, Integer> singoCount = new LinkedHashMap<>();
        List<String> reported = new ArrayList<>();
        for (String r : report) {
            String[] split = r.split(" ");

            String to = split[0];
            String from = split[1];
            if(reportFromTomap.containsKey(to) && reportFromTomap.get(to).contains(from)){
                continue;
            }
            reportFromTomap.putIfAbsent(to, new ArrayList<>(Set.of(from)));

            reportFromTomap.get(to).add(from);
            singoCount.put(from, singoCount.getOrDefault(from, 0) + 1);
        }

        singoCount.forEach((key, value) -> {
            if(value >= k){
                for (Map.Entry<String, List<String>> entry : reportFromTomap.entrySet()) {
                    if(entry.getValue().contains(key)){
                        reported.add(entry.getKey());
                    }
                }
            }
        });

        int index = 0;
        for (String id : id_list) {
            int cnt =0;
            for (String value : reported) {
                if (id.equals(value)) {
                    cnt++;
                }
            }
            answer[index++] = cnt;
        }
        return answer;
    }
 }
