import java.util.*;
class Solution {
    public String[] solution(String[] record) {
        String[] answer = {};
       
        List<String[]> res = new ArrayList<>();
        HashMap<String, String> user = new HashMap<>(); // id, nickname
       
        for(int i=0; i<record.length; ++i){
            String[] s = record[i].split(" ");
                
            if(s[0].equals("Enter")){
                user.put(s[1],s[2]);
                res.add(s);
            }
            else if(s[0].equals("Change")){
                user.put(s[1],s[2]);
            }
            else{
                res.add(s);
            }
        }
        answer = new String[res.size()];
        int i=0;
        for(String[] s : res){
            String na = user.get(s[1]);
            if(s[0].equals("Enter")){
                answer[i++] = (na+"님이 들어왔습니다.");
            }
            else{
                answer[i++] = (na+"님이 나갔습니다.");
            }
        }
        return answer;
    }
}
