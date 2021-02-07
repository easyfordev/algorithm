#include <iostream>
#include <algorithm>
using namespace std;

int dp[301]; // n번째 계단까지 점수의 최댓값
int arr[301]; // 계단에 쓰인 수
int n;

int main(void) {
    scanf("%d", &n);

    for(int i=1;i<=n;i++) {
        scanf("%d", &arr[i]);
    }

    // base case
    dp[1] = arr[1]; // 첫번째 계단까지의 최댓값은 당연히 첫번째 계단
    dp[2] = max(arr[2] , arr[1]+arr[2]);
    dp[3] = max(arr[2]+arr[3], arr[1]+arr[3]);

    // dp로 쭉 구하기
    for(int i=4;i<=n;i++) {
        int a = dp[i-3] + arr[i-1] + arr[i]; // n-1번째 계단을 밟고 온 경우
        int b = dp[i-2] + arr[i]; // n-1번째 계단을 안밟고 온 경우
        dp[i] = max(a, b);
    }

    printf("%d\n", dp[n]);
}