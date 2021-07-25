/*
프로그래머스 - 피보나치 수
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    vector<int> dp(n+1);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 1234567;
    }

    return dp[n];
}

int main(){
    cout << solution(3);
    cout << solution(5);
}