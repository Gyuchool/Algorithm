#include <iostream>
using namespace std;

int main() {
	int i,a,b,c;
	int sum=0;
	int count=0;
	cin>>i;
	if(i>0&&i<100){
		sum=i;
	}
	else if(i>=100&&i<1000){
		sum=99;
		
		for(int j=100;j<=i;j++){
			a=j/100;
			b=(j/10)%10;
			c=j%10;
			if(2*b==(a+c)){
				count++;
			}
		}
		sum+=count;
	}
	else if(i==1000){
		sum=99;
		
		for(int j=100;j<i;j++){
			a=j/100;
			b=(j/10)%10;
			c=j%10;
			if(2*b==(a+c)){
				count++;
			}
		}
		sum+=count;		
	}
	cout<<sum;
	return 0;
}
