#include <string>
#include <vector>
#include <iostream>
using namespace std;

string convert(int n, int x) {
    string dic = "0123456789ABCDEF";
    string conver = "";
    while (x != 0) {
        int tmp = x % n;
        x /= n;
        conver = dic[tmp] + conver;
    }
    return conver;
}
string solution(int n, int t, int m, int p) {
    string answer = "0";
    for(int i=1;i<=100000; ++i){
        
        answer+=convert(n, i);
    }
    string real ="";
    for(int i=0; i<=100000; ++i){
        if(i%m == p-1){
            real += answer[i];
        }
        if(real.size()==t){
            break;
        }
    }
    
    return real;
}
