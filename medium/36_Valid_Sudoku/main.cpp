#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            set<char>cnt; 
            int c = 0; 

            for(int j = 0; j < board.size(); j++){
                if(board[i][j] != '.'){
                    cnt.insert(board[i][j]); 
                    c++; 
                }

                if(c != cnt.size()){
                    return false;
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            set<char>cnt; 
            int c = 0; 

            for(int j = 0; j < board.size(); j++){
                if(board[j][i] != '.'){
                    cnt.insert(board[j][i]); 
                    c++; 
                }

                if(c != cnt.size()){
                    return false;
                }
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                set<char>cnt; 
                int c = 0; 

                for(int k = i*3; k < i*3+3; k++){
                    for(int l = j*3; l < j*3+3; l++){
                        if(board[k][l] != '.'){
                            cnt.insert(board[k][l]); 
                            c++; 
                        }
                    }
                }

                if(c != cnt.size()){
                    return false;
                }
            }
        }
        
        return true; 
    }
}; 