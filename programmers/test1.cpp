/*
LeetCode - 15. 3 Sum
- 중복검사를 신경써줘야하는게 조금 힘들었다.
- 중복 아닐때까지 찾을 때 left < right 안넣어줘서 Runtime Error 났다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool solution(string s) {
    // 문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성되어있는지 확인하는 함수
    int len = s.size();
    if(!(len==4 || len==6))
        return false;
    
    // 숫자로만 구성되어있는지
    for(int i=0;i<len;i++) {
        if(isdigit(s[i]) == 0) {
            return false;
        }
    }
    return true;
}

int main(){
   string s = "1";
   cout << solution(s);
}
