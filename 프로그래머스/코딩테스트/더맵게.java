import java.util.*;
//계속되는 정렬이 필요할땐, ArrayList보단 Heap구조 이용하는게 좋다!
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for(int i : scoville){
            queue.offer(i);
        }
        while(queue.peek()<K){
            if(queue.size()<2){
                return -1;
            }   
            int a = queue.poll();
            int b = queue.poll();
            queue.offer(a+2*b);
            answer++;
        }
        return answer;
    }
}
