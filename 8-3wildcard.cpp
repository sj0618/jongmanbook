#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool match(const string&  w,const string& s){
    int pos = 0;
    while(pos < w.size() && pos< s.size() && (w[pos] == '?' || w[pos] == s[pos]) ){
        pos ++ ;
    }
    if(pos == w.size()) return pos == s.size();
}
int main(){

}