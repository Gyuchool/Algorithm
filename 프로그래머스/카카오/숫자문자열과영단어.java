class Solution {
    public int solution(String s) {
        StringBuilder answer= new StringBuilder();
        for(int i=0; i<s.length(); ++i){
            if(s.charAt(i)>='0' && s.charAt(i)<='9'){
                answer.append(s.charAt(i));
            }
            else{
                if(s.charAt(i) == 'z'){// zero발견
                    answer.append('0');
                    i+=3;
                }
                else if(s.charAt(i) == 'o'){
                    i+=2;
                    answer.append('1');
                }
                else if(s.charAt(i) == 't'){
                    if(s.charAt(i+1) == 'w'){
                        i+=2;
                        answer.append('2');
                    }
                    else if(s.charAt(i+1) == 'h'){
                        i+=4;
                        answer.append('3');
                    }
                }
                else if(s.charAt(i) == 'f'){
                    if(s.charAt(i+1) == 'o'){
                        i+=3;
                        answer.append('4');
                    }
                    else if(s.charAt(i+1) == 'i'){
                        i+=3;
                        answer.append('5');
                    }
                }
                else if(s.charAt(i) == 's'){
                    if(s.charAt(i+1) == 'i'){
                        i+=2;
                        answer.append('6');
                    }
                    else if(s.charAt(i+1) == 'e'){
                        i+=4;
                        answer.append('7');
                    }
                }
                else if(s.charAt(i) == 'e'){
                    i+=4;
                    answer.append('8');
                }
                else  if(s.charAt(i) == 'n'){
                    i+=3;
                    answer.append('9');
                }
            }
        }
        return Integer.parseInt(answer.toString());
    }
}
