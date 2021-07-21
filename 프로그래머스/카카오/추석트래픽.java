import java.util.*;
class Solution {
    public int solution(String[] lines) {
        int answer = 0;
        List<Double> start = new ArrayList<>();
        List<Double> end = new ArrayList<>();
        List<Integer> total = new ArrayList<>();
        
        for(int i=0; i<lines.length; ++i){
            String[] log = lines[i].split(" ");
            String endDate = log[1];
            String times = log[2];
            int target = times.indexOf("s");
            Double time = Double.parseDouble(times.substring(0,target));//걸린 시간
            
            String[] nano = endDate.split(":");
            Double sec = Double.parseDouble(nano[0])*3600;
            sec+=Double.parseDouble(nano[1])*60;
            sec+=Double.parseDouble(nano[2]);//초단위로 변환
            
            Double startDate = sec-(time)+0.001;
            start.add(startDate);
            //endDate 초단위 변환->sec
            end.add(sec);
        }
        if(lines.length == 1){
           return 1;
       }
        for(int i=0; i<start.size(); ++i){
            int cnt=1;
            
            Double st = start.get(i);
            Double ed = end.get(i);
            
            //시작과 끝을 기준으로 1초안에 점검
            for(int j=i+1; j<start.size(); ++j){
                if (Math.abs(ed-start.get(j)) < 1 || Math.abs(ed-end.get(j)) < 1
                    || Math.abs(st-start.get(j)) < 1 || Math.abs(st-end.get(j)) < 1
                    || st <= start.get(j) && end.get(j) <= ed
                    || start.get(j) <= st && ed <= end.get(j)
                   ) {
                    cnt++;
                }
            }
            answer = Math.max(answer,cnt);
        }
        
        return answer;
    }
}
