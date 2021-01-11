#include <iostream>
using namespace std;
int ans = 0;
int n, k;

void solve(int index, int cnt) {
	// 정답을 찾은 경우 
	if(cnt == k) {
		ans++;
		return;
	}
	// 불가능한 경우
	if(index >= n)	return;
	if(cnt > k)	return;

	// 다음 경우
	// 이번을 포함
	solve(index+1, cnt+1);

	// 이번을 포함하지 않음
	solve(index+1, cnt);
}

int main() {
	scanf("%d %d", &n, &k);

	// 이항계수 nCk = n개의 서로 다른 것 중에서 k개를 선택하는 조합의 경우의 수
	solve(0,0);

	printf("%d\n", ans);

}
