#include <vector>
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
int n ,board[100][100];
int c[100][100];
bool Jump(int y,int x){
    if( y >=n || x >= n){
        return false;
    }
    if(y == n-1 && x == n-1 ) return true;

    int  &ret = c[y][x];
    if(ret == -1) return ret;
    int jumpsize = board[y][x];
    return ret = Jump(y+jumpsize,x) || Jump(y,x+jumpsize);
}