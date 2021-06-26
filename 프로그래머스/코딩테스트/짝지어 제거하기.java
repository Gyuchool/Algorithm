import java.util.*;
class Solution
{
    public int solution(String s)
    {
        int answer = 0;

        ArrayList<String> stack = new ArrayList<String>();
        
        for(int i=0; i<s.length(); ++i){
            if(stack.isEmpty()){
                stack.add(String.valueOf(s.charAt(i)));
            }else{
                if(stack.get(stack.size()-1).equals(String.valueOf(s.charAt(i)))){
                    stack.remove(stack.size()-1);
                    continue;
                }
                else{
                     stack.add(String.valueOf(s.charAt(i)));
                }
            }
            
        }
        if(stack.isEmpty()){
            answer=1;
        }
        return answer;
    }
}
