#include <iostream>
using namespace std;
int num, tc;
int ans=0;
void solve(int n) { // n을 1,2,3의 합으로 나타내는 방법의 수
	// 정답을 찾은 경우
	if(n == num) {
		ans++;
		return;
	}

	// 불가능한 경우
	if(n > num)
		return;
	
	// 다음 경우
	solve(n+1);
	solve(n+2);
	solve(n+3);
}

int main(){
	scanf("%d", &tc);
	
	while(tc--) {
		ans = 0;
		scanf("%d", &num);

		solve(0);
		printf("%d\n", ans);
		
	}
}
