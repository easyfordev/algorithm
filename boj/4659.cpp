/* BOJ - 4659. 비밀번호 발음하기
꼭 조건을 순서대로 구현할 필요는 없다. 체크하기 편한것부터 구현하면 된다.

(주의) for문 돌면서 계속 초기화해줘야 하는 변수 (여기서 this_moja) 잘 챙기기
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char input[21];

int main(){
    // 마지막 tc는 "end"
    // 패스워드는 대문자를 포함하지 않음
    while(true) {
        scanf("%s", input);
        string s = input;
        
        // 종료조건
        if(s == "end")  break;

        bool flag = true;

        // 3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
        int len = s.size();
        for(int i=0;i<len-1;i++) {
            // e와 o가 아닌 같은 글자가 연속 2번 오면 안됨
            if(s[i] == s[i+1] && s[i] != 'e' && s[i] != 'o') {
                flag = false;
                // printf("3번아님\n");
                break;
            }
        }

        bool mo = false; // 1번 룰 - 모음 한번이라도 들어오는지 체크
        int cnt = 1; // 2번 룰 - 모음 or 자음 count
        int this_moja=0, prev_moja = 0; // 0 - 자음, 1 - 모음

        for(int i=0;i<len;i++) {
            // printf("%c : ", s[i]);
            this_moja = 0;
            // 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                mo = true;
                this_moja = 1;
            }
            
            // 2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
            if(i != 0) { // 1번부터 이전 애랑 비교해서 검사
                if(this_moja != prev_moja)  cnt = 1;
                else { // 연속으로 나오면,
                    cnt++;
                    
                    // printf("this_moja: %d, prev_moja: %d, cnt: %d\n", this_moja, prev_moja,cnt);
                    // 3번 나왔나 검사
                    if(cnt >= 3) {
                        // printf("2번아님\n");
                        flag = false;
                    }
                }
            }
            prev_moja = this_moja;
        }

        // 1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
        if(!mo) {
            flag = false;
            // printf("1번아님\n");
        }
        
        if(flag)    printf("<%s> is acceptable.\n", s.c_str());
        else    printf("<%s> is not acceptable.\n", s.c_str());
    }
}