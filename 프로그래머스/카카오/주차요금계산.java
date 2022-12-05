import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

public class Solution {

    public int[] solution(int[] fees, String[] records) {
        Map<String, Integer> check = new LinkedHashMap<>();//들어온 시간
        Map<String, Integer> store = new LinkedHashMap<>();//차 누적

        int basic_time = fees[0];
        int basic_fee = fees[1];
        int unit_time = fees[2];
        int unit_fee = fees[3];
        int last_time = 23 * 60 + 59;

        for (String record : records) {
            String car = record.split(" ")[1];
            store.put(car, 0);
        }
        int[] answer = new int[store.size()];

        for (String record : records) {
            int time = convertTime(record.split(" ")[0]);
            String car = record.split(" ")[1];
            String in_out = record.split(" ")[2];
            if (in_out.equals("IN")) {
                check.put(car, time);
            } else {
                if (check.containsKey(car)) {
                    store.put(car, store.get(car) + time - check.get(car));
                    check.remove(car);
                }
            }
        }
        for (var st : check.entrySet()) {
            store.put(st.getKey(), store.get(st.getKey()) + last_time - st.getValue());
        }

        List<Car> cars = new ArrayList<>();
        for (var e : store.entrySet()) {
            if (e.getValue() <= basic_time) {
                cars.add(new Car(e.getKey(), basic_fee));
            } else {
                int tt = e.getValue() - basic_time;
                int order_fee = (tt / unit_time) * unit_fee;
                if (tt % unit_time > 0) {
                    order_fee = ((tt / unit_time) + 1) * unit_fee;
                }
                cars.add(new Car(e.getKey(), basic_fee + order_fee));
            }
        }
        cars.sort(Comparator.comparingInt(o -> Integer.parseInt(o.name)));

        return cars.stream()
                .mapToInt(o -> o.time)
                .toArray();
    }

    public static class Car {
        String name;
        int time;

        public Car(String name, int time) {
            this.name = name;
            this.time = time;
        }
    }

    public static int convertTime(String time) {
        String h = time.split(":")[0];
        String m = time.split(":")[1];
        int hour = Integer.parseInt(h);
        return hour * 60 + Integer.parseInt(m);
    }
}
