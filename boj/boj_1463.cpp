/* 전형적인 DP 문제 */
#include <iostream>
#include <cmath>
using namespace std;
int dp[1000001]; // dp[i] = i를 1로 만드는 최소 연산의 수
int num;

int solve(int n) {
	if(n==1) {
		dp[n] = 0;
		return dp[n];
	} else {
		if(dp[n] > 0) { // 이미 답을 구했으면
			return dp[n];
		}
		// 1을 뺀다(일단 이걸로 초기화)
		dp[n] = solve(n-1) + 1;
		if(n%3 == 0) {
			int temp = solve(n/3) + 1;
			dp[n] = min(temp, dp[n]);
		}
		if(n%2 == 0) {
			int temp = solve(n/2) + 1;
			dp[n] = min(temp, dp[n]);
		}
		return dp[n];
	}
}

int main(){
	scanf("%d", &num);
	
	printf("%d\n", solve(num));
}
