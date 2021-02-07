/* dp 문제
처음엔 식을 세우지 못했다. 다른사람들이 세운 식을 보고 이해하고 풀었다.
문제를 보고 dp 느낌이 오면, 차분히 dp식을 세워보자. */

#include <iostream>
#include <algorithm>
using namespace std; 
int n;
int dp[50000+1]; // dp[i] = i를 최소 개수의 제곱수 합으로 표현할 수 있는 방법. dp[i] = min(dp[i-j*j] + 1 

int main() {
    scanf("%d", &n);

    // 문제풀기
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++) {
        int ans = 999999;

        // 나에서 제곱수를 뺀 dp을 구한다. 이것들의 최솟값을 구한다.
        for(int j=1;j*j<=i;j++) {
            ans = min(ans, dp[i-j*j]);
        }

        dp[i] = ans + 1;  // 여기서 1만 더한다
    }
    // 정답 출력
    printf("%d\n", dp[n]);
}