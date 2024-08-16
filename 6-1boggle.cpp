#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string  board[5][5];
const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};
bool hasword(int y ,int x,const string& word){
    if (y >5 || x > 5 || x<0 || y < 0){
        return false;
    }

    if(board[y][x] != word[0]) return false;

    if(word.size () == 1) return true;

    for(int di= 0;di< 8;di++){
        int nextX = dx[di] + x , nextY = y + dy[di];
        if(hasword(nextY,nextX,word.substr(1)) )          //다음 hasword가 참이라면
        return true; 
    }
    return false
}