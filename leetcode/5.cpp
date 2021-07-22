/*
LeetCode 5. Longest Palindromic Substring
- DP로 풀어보자
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        // Corner Case
        if(len <= 1) return s;

        // Base
        bool dp[1001][1001] = {false};
        
        // 한글자인 경우 모두 true
        for(int i=0;i<len;i++) {
            dp[i][i] = true;
        }

        // 점화식 때문에 i를 거꾸로 돌려야 함. i+1이 먼저 준비되어야 i를 구할 수 있는 형태라서
        // dp[i][j] : 문자열 substr(i, j)가 palindrom인지?
        // 정답 기억해두기
        int ans = 1;
        int start = 0;

        for(int i=len-1;i>=0;i--) {
            for(int j=i+1;j<len;j++) {
                // 두글자인 경우
                if(j-i == 1) {
                    if(s[i] == s[j])    dp[i][j] = true;
                }

                // 나머지 일반적인 경우
                if(s[i] == s[j] && dp[i+1][j-1]==true) {
                    dp[i][j] = true;
                }

                // 이번 값이 trued이면 답 업데이트
                if(dp[i][j]) {
                    if(j-i+1 > ans) {
                        ans = j-i+1;
                        start = i;
                    }
                }
            }
        }

        // 정답
        return s.substr(start, ans);
    }
};

int main(){
    Solution s;

    cout << s.longestPalindrome("ac");
}