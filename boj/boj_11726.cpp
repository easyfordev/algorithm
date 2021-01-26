/* 전형적인 DP 문제 
나머지를 구하는 문제는, 풀면서 계속 나머지를 구해줘야 함*/
#include <iostream>
using namespace std;
int dp[1001]; // dp[i] = 2*i 크기의 직사각형을 채우는 방법의 수
int num;

int solve(int n) {
	if(dp[n] > 0) {
		return dp[n];
	}
	dp[n] = solve(n-1) + solve(n-2);
	// 풀면서 나머지를 구해줘야 함
	dp[n] %= 10007;
	return dp[n];
}

int main(){
	scanf("%d", &num);

	dp[0] = 1; // dp[1] = 1, dp[2] = 2이므로 그림을 그려보면 이렇게 정의할 수 있다.
	dp[1] = 1;

	solve(num);
	printf("%d\n", dp[num]);
}
