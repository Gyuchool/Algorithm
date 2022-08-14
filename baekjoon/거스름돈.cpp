#include <iostream>

using namespace std;

int n;

int main(){
    cin>>n;
    int f = n/5;
    int nam = n%5;
    while (true) {
        if (nam % 2 == 0) {
            int t= nam/2;
            cout<<f+t;
            break;
        }else{
            f--;
            nam = n-5*f;
        }
        if (f < 0) {
            cout<<-1;
            break;
        }
    }

}
