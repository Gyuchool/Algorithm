import java.util.Set;
import java.util.HashSet;
class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        Set<Integer> st = new HashSet<Integer>(); 
        for(int i=0; i<nums.length; ++i){
            st.add(nums[i]);
        }
        if(st.size() > nums.length/2){
            answer = nums.length/2;
        }
        else{
            answer = st.size();
        }
        return answer;
    }
}
