/*
2800. 괄호 제거
- set은 그냥 정렬을 해준다.
- 시간초과... 뭐야 ....
- 재귀 함수 탈 때 이미 검사했으면 건너뛰는 로직을 추가했더니 통과했다!
*/
#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <set>

using namespace std;

set<string> answer;
set<string> check;

void solution(string str) {
    // (시간초과 방지) 이미 검사했던 str이면 함수 안타고 그냥 넘어간다.
    if(check.find(str) != check.end()) {
        return;
    }
    // 괄호를 제거해서 나올 수 있는 서로 다른 식의 개수 계산
    // 수식은 무조건 괄호가 올바르게 쳐져 있다.
    // 항상 쌍이 되는 괄호끼리 제거해야 한다.
    int len = str.size();
    int start = 0; // 현재 괄호의 시작점 인덱스를 넣어놓는다.
    int end = 0;
    stack<int> s; // ( 여는괄호가 시작하는 지점의 index를 하나씩 넣는다.

    for(int i=0;i<len;i++) {
        if(str[i] == '(') {
            s.push(i);
        } else if(str[i] == ')') {
            // 스택에서 하나 꺼내기
            start = s.top();
            s.pop();
            end = i;

            // start와 end 괄호 삭제
            string s1 = str.substr(0, start);
            string s2 = str.substr(start+1, end-start-1);
            string s3 = str.substr(end+1, len-end-1);
            answer.insert(s1+s2+s3);

            // 재귀적으로 호출해준다.
            solution(s1+s2+s3);
        }
    }
    // 끝까지 다 검사한 문자열 체크
    check.insert(str);
}

int main(){
    // 입력받기
    string str;
    cin >> str;

    solution(str);

    // 사전순으로 출력 - set은 이미 정렬되어있다.
    for(auto iter = answer.begin(); iter != answer.end(); iter++){
        cout << *iter <<  "\n";
    }
}                       

