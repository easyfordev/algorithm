/*
프로그래머스 - 12909. 올바른 괄호
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool solution(string s){
    stack<char> st;

    int len = s.size();
    for(int i=0;i<len;i++) {
        if(s[i] == '(') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            // 닫는 괄호 나왔는데, pop할게 없으면, 올바른 문자열이 아니다.
            if(st.empty()) {
                return false;
            }

            // 아니면, 스택에서 하나 꺼내기
            st.pop();
        }
    }

    // 끝까지 왔는데, 스택에 뭔가 남아있으면 올바른 괄호 짝이 아니다.
    if(st.empty()) return true;
    else    return false;
}

int main(){
    cout << solution("()()") << "\n";
    cout << solution("(())()") << "\n";
    cout << solution(")()(") << "\n";
    cout << solution("(()(") << "\n";

}

