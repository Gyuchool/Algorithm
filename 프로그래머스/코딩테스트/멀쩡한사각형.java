class Solution {
    
    public long solution(int w, int h) {
        long answer = 1;
        long lw = Long.valueOf(w);
        long lh = Long.valueOf(h);
        long x= gcd(lw,lh);
        answer = lw*lh-(lw+lh-x);
        return answer;
    }
    long gcd(long w, long h){
        if(w<h){
            long tmp = w;
            w=h;
            h=tmp;
        }
        while(h!=0){
            long a = w%h;
            w=h;
            h=a;
        }
        return w;
    }
}
