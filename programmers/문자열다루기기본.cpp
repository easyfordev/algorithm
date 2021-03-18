/* Programmers - 문자열 다루기 기본
- TC 2개 틀렸음 : 문제를 잘 읽어야지 !! 길이가 4 or 6인지도 검사해야해 ..
- isDigit(), isAlpha() 이런 함수도 있음
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.size();
    // 문제 조건 - 길이가 4 or 6이어야 함
    if(!(len == 4 || len == 6))
        return false;
    for(int i=0;i<len;i++) {
        char c = s[i];
        
        if(!('0' <= c && c <= '9')) {
            answer = false;
            return answer;
        }
    }
    return answer;
}

int main(){
    vector<int> test{2, 1, 1, 2, 3, 1};

    printf("답 : %d\n", solution("1234"));
}