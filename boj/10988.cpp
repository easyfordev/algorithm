/*
BOJ - 10988. 팰린드롬인지 확인하기 
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str;
    cin >> str;
    bool answer = true;

    int len = str.size();

    for(int i=0;i<len/2;i++) {
        // 회문인지 검사
        if(str[i] != str[len-1-i]) {
            answer = false;
            break;
        }
    }

    printf("%d\n", answer);
}