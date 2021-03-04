/* 맵 쓰는 문제
- 틀렸습니다 해결 : enter - leave를 반복할 수 있다. 들어왔다 나갔다 다시 들어오는거지
*/
#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int n;
map<string, bool> m; // true면 회사에 있음, false면 회사에 없음
char str[10], command[10];

int main(){
    // 현재 회사에 있는 모든 사람 구하기

    // 사전순의 역순으로 .... 한 줄에 한 명씩 출력
    scanf("%d", &n);
    getchar();

    for(int i=0;i<n;i++) {
        // 이름
        scanf("%s", str);
        scanf("%s", command);

        // enter or leave
        // enter이면 map에 넣기
        // leave면 빼기
        string name = str;
        string com = command;
        if(com == "enter") {
            if(m.find(name) == m.end()) { // 없으면
                m.insert(make_pair(name, true));
            } else { // 있으면
                m[name] = true;
            }
        } else if(com == "leave") {
            m[name] = false;
        }
    }

    for(auto iter = m.rbegin(); iter != m.rend() ; iter++) {
        if(iter->second == true) {
            printf("%s\n", iter->first.c_str());
        }
    }
}

