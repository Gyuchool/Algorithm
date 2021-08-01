class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        int[] score = new int[3];
        int[] mul = new int[3];
        String tmp="";
        for(int i=0;i<3;++i){
            score[i]=0;
            mul[i]=0;
        }
        int id=0;
        
        for(int i=0; i<dartResult.length(); ++i){
            int sum=0;
            
            if(dartResult.charAt(i)>='0' && dartResult.charAt(i)<='9'){
                tmp += dartResult.charAt(i);
            }
            
            if(dartResult.charAt(i)=='S'){
                sum = Integer.valueOf(tmp);
                score[id++] = sum;
                tmp = "";
            }
            else if(dartResult.charAt(i)=='D'){
                 sum = Integer.valueOf(tmp);
                sum = (int)Math.pow(sum,2);
                score[id++] = sum;tmp = "";
            }
            else if(dartResult.charAt(i)=='T'){
                 sum = Integer.valueOf(tmp);
                sum = (int)Math.pow(sum, 3);
                score[id++] = sum;tmp = "";
            }
            else{
                if(dartResult.charAt(i)=='#'){
                    score[id-1] *= -1;
                }
                else if(dartResult.charAt(i)=='*'){
                    score[id-1] *= 2;
                    if(id>=2){
                        score[id-2]*=2;
                    }
                }    
            }
            
            
        }
        
        
        for( int value: score){
            answer+=value;
        }
        return answer;
    }
}
