#include <string>
#include <vector>

using namespace std;

int key[12][12];

string solution(vector<int> numbers, string hand) {
    key[1][2]=1;
    key[2][3]=1;key[2][5]=1;
    key[2][4]=2;key[2][6]=2;key[2][8]=2;
    key[2][7]=3;key[2][9]=3;key[0][2]=3;
    key[2][10]=4;key[2][11]=4;
    key[5][3]=2; key[5][1]=2;key[5][9]=2;key[5][7]=2;
    key[5][4]=1;key[5][6]=1;key[5][8]=1;key[5][0]=2;key[5][10]=3;key[5][11]=3;
    key[8][1]=3;key[8][3]=3;key[8][4]=2;key[8][6]=2;key[8][7]=1;key[8][9]=1;key[8][10]=2;key[8][11]=2;key[0][8]=1;
    key[0][1]=4;key[0][3]=4;key[0][4]=3;key[0][6]=3;key[0][7]=2;key[0][9]=2;key[0][10]=1;key[0][11]=1;
    for(int i=0;i<12;++i){
        for(int j=0;j<12;++j){
            if(key[i][j]){
               key[j][i] = key[i][j]; 
            }
        }
    }
    
    
    string answer = "";
    int le=10;
    int ri=11;
    
    for(int i=0; i<numbers.size(); ++i){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer+="L";
            le = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer+="R";
            ri = numbers[i];
        }
        else{
            if(key[le][numbers[i]] < key[ri][numbers[i]]){
                answer+="L";
                le = numbers[i];
            }
            else if(key[le][numbers[i]]> key[ri][numbers[i]]){
                answer+="R";
                ri = numbers[i];
            }
            else{
                if(hand == "left"){
                    le = numbers[i];
                    answer+="L";
                }
                else{
                    answer += "R";
                    ri = numbers[i];
                }
            }
        }
    }
    return answer;
}
