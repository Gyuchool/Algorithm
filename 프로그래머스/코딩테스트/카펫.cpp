#include <string>
#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;
    y= ((4+brown) + sqrt(pow(4+brown,2) - 8*(2*yellow + 2*brown)))/4;
    x = (yellow+brown)/y;
    
    if(x>y){
        answer.push_back(x);
        answer.push_back(y);   
    }else{
        answer.push_back(y);
        answer.push_back(x);   
    }
    
    return answer;
}
