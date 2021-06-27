class Solution {
    public boolean isPrime(int sum){
        for(int i=2; i<sum; ++i){
            if(sum%i==0){
                return false;
            }
        }
        return true;
    }
    public int solution(int[] nums) {
        int answer = 0;
        
        for(int i=0; i<nums.length; ++i){
            for(int j=i; j<nums.length; ++j){
                for(int k=j;k<nums.length;++k){
                    if(i!=j && j!= k && i!=k){
                        int sum=nums[i]+nums[j]+nums[k];
                        if(isPrime(sum)){
                            answer++;
                        }
                    }
                }
            }
        }

        return answer;
    }
}
