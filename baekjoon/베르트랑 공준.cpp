#include <math.h>
#include <iostream>
using namespace std;

int primeNum[123456*2+1];
int n;
int primeCount=0;

void init(){
    for(int i=n+1;i<=2*n; i++){
        primeNum[i] = 0;
    }
    primeCount = 0;
}
void primeNumberSieve()
{
    init();
    // primeNum 배열 초기화
    for (int i = 2; i <= 2*n; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(2*n); i++)
    {
        // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
        if (primeNum[i] == 0)
            continue;
        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
        for (int j = i * i; j <= 2*n; j += i)
            primeNum[j] = 0;
    }

    // 소수 출력
    for (int i = n+1; i <= 2*n; i++)
    {
        if (primeNum[i] != 0)
            primeCount++;
    }
    cout<<primeCount<<endl;
}

int main(){
    cin>>n;
    while(n!=0){
        primeNumberSieve();
        cin>>n;
    }
    
    
}
