#include <string>
#include <vector>

using namespace std;

vector<int> v;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for(int i=0; i<moves.size(); ++i){
        int edge = moves[i];
        
        for(int j=0;j<board.size(); ++j){
            if(board[j][edge-1] != 0){
                if(v.empty()){
                    v.push_back(board[j][edge-1]);
                }
                else{
                    if(v.back() == board[j][edge-1]){
                        answer+=2;
                        v.pop_back();
                    }                
                    else{
                        v.push_back(board[j][edge-1]);
                    }   
                }
                board[j][edge-1] = 0;
                break;
            }
        }
    }
    return answer;
}
