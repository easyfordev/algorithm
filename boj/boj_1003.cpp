/* 그냥 피보나치 있는 그대로 풀면 시간초과 ... 시간 제한이 0.25초인 문제다
	dp로 풀어야 함
	피보나치 함수와 0, 1 출력 횟수의 상관 관계 : 0의 출력 횟수는 dp[n-1], 1의 출력 횟수는 dp[n]
*/
#include <iostream>
using namespace std;

int tc, num;
int dp[41]; // dp[i] = i번째 수

int fibonacci(int n) {
	if(n==0) {
		dp[0] = 0;
		return dp[0];
	} else if(n==1) {
		dp[1] = 1;
		return dp[1];
	} else {
		if(dp[n] > 0) { // 이미 값 있으면, 그거 리턴
			return dp[n];
		}
		dp[n] = fibonacci(n-1) + fibonacci(n-2);
		return dp[n];
	}
}

int main(){
	scanf("%d", &tc);


	while(tc--) {
		scanf("%d", &num);

		// 0이 출력되는 횟수, 1이 출력되는 횟수
		if(num == 0)
			printf("1 0\n");
		else if(num == 1)
			printf("0 1\n");
		else {
			fibonacci(num);
			printf("%d %d\n", dp[num-1], dp[num]);
		}
	}
}
