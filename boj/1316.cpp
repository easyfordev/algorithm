/* BOJ - 1316. 그룹 단어 체커 (문자열)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char input[101];

int main(){
    int tc;
    scanf("%d", &tc);

    int ans = 0;

    while(tc--) {
        getchar();
        scanf("%s", input);

        string s = input;
        vector<bool> check(26);
        // 그룹단어인지 체크
        int len = s.size();
        bool flag = true;

        // 시작점 초기화해주기
        char c = s[0];
        check[c-'a'] = true;

        for(int i=1;i<len;i++) {
            // 예전에 나온적 있고, 바로 앞 글자와 지금 글자가 다르면, 답 아님
            if(check[s[i]-'a'] == true && c != s[i]) {
                flag = false;
                break;
            } else if(check[s[i]-'a'] == false) { // 예전에 나온적 없으면 체크
                check[s[i]-'a'] = true;
            }
            c = s[i];
        }

        if(flag)    ans++;
    }

    printf("%d\n", ans);
}
