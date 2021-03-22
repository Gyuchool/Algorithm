import java.util.ArrayList;
class Solution {
    public int[] solution(int[] answers) {
        int[] answer = {};
        int[] n1 = new int[10000];
        int[] n2 = new int[10000];
        int[] n3 = new int[10000];
        
        for(int i=0;i<10000;++i){
            n1[i] = (i%5)+1;
        }
        int index=0;int value = 1;
        while(index!=10000){
            if(index%2 != 0){
                n2[index] = value;
                index++;value++;
                if(value==2){
                    value=3;
                }
                else if(value==6){
                    value=1;
                }
            }
            else{
                n2[index]=2;
                index++;
            }
        }
        int v =3;
        for(int i=0; i<10000; i+=2){
            n3[i] =v;
            n3[i+1] = v;
            if(v==3)v=1;
            else if(v==1)v=2;
            else if(v==2)v=4;
            else if(v==4)v=5;
            else if(v==5)v=3;
        }
        int an1=0;
        int an2 = 0;
        int an3 = 0;
        
        for(int i =0; i<answers.length; ++i){
            if(n1[i] == answers[i]){
                an1++;
            }
            if(n2[i] == answers[i])
                an2++;
            if(n3[i] == answers[i]){
                an3++;
            }
            
        }
        
        int k=0;
        int ma = Math.max(an1, Math.max(an2, an3));
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        if(an1 == ma)list.add(1);
        if(an2==ma)list.add(2);
        if(an3 == ma)list.add(3);
        
        answer = new int[list.size()];
        for(int i=0; i<answer.length; ++i){
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}
