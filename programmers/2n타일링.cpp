/*
프로그래머스 - 2*n 타일링
- 처음에 %=1000000007 를 맨 마지막에 return 할때만 해줘서 결과가 아얘 틀렸다.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) { // 가로의 길이 n, 이 직사각형을 채우는 모든 방법의 수 리턴
    int answer = 0;

    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2];

        dp[i]%=1000000007;
    }

    return dp[n];
}

int main(){
    int num = 4;
    cout << solution(num);
}
