import java.util.HashMap;
import java.util.Map;
import java.util.Locale;

class Solution {
     public int solution(int cacheSize, String[] cities) {
            int answer = 0;
            Map<String, Integer> ranking = new HashMap<>(); // 도시이름, 순위 (1~cacheSize만큼 우선순위)

            for (int i = 0; i < cities.length; i++) {
                cities[i] = cities[i].toLowerCase(Locale.ROOT);
            }

            int level = 0;
            if (cacheSize == 0) {
                for (int i = 0; i < cities.length; i++) {
                    answer += 5;
                }
            } else {
                for (String s : cities) {
                    if (ranking.containsKey(s)) {
                        ranking.put(s, level++);
                        answer++;
                        continue;
                    }
                    if (ranking.size() == cacheSize) {
                        int min = 100001;
                        String city = "";
                        for (var key : ranking.keySet()) {
                            if (ranking.get(key) < min) {
                                city = key;
                                min = ranking.get(key);
                            }
                        }
                        ranking.remove(city);
                    }
                    ranking.put(s, level);
                    answer += 5;
                    level++;
                }
            }

            return answer;
        }
}
