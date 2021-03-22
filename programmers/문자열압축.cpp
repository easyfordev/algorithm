/* Programmers - 문자열 압축 (문자열, 완전탐색)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int len = s.size();
    int ans = len; // 정답 초기화

    // 문자열을 1개 ~ len/2개 단위로 잘라본다.
    for(int n=1;n<=len/2;n++) {
        string convert = "";

        // n개 단위로 쪼갠다
        int cnt = 1;
        string temp = s.substr(0, n);

        for(int i=n;i<len;i+=n) {
            if( temp == s.substr(i, n)) { // 같으면 cnt증가하고 넘어간다
                cnt++;
            } else { // 다르면
                // cnt가 1이면 그냥 냅둠
                if(cnt > 1) {  // 한번이라도 같은게 나왔으면,
                    convert += to_string(cnt);
                }
                convert += temp;
                
                cnt = 1;
                temp = s.substr(i, n);
            }

        }

        // (중요 - 이거때문에 삽질함) 남은 맨 마지막 부분 처리
        if(cnt > 1) convert += to_string(cnt);
        convert += temp;

        // 정답 비교
        ans =  convert.size() < ans ?  convert.size() : ans;
    }
    
    return ans;
}

int main(){
    vector<int> test{2, 1, 3, 2};
    vector<int> test2{1, 1, 9, 1, 1, 1};

    string t = "...."; // "X.XXXXX.X" , ".X..X", "XX.XXX"
    printf("답 : %d\n", solution("aabbaccc"));
}

