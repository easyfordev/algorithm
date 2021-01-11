#include <iostream>
using namespace std;

int n, m;
int arr[101];
int ans = -1;

void solve(int index, int cnt, int sum) { // 현재까지 count, sum
	// 정답을 찾은 경우
	if(cnt == 3) {
		if(sum > ans && sum <= m) {
			ans = sum;
			return;
		}
	}

	// 불가능한 경우
	if(index >= n)	return;
	if(cnt > 3 )	return;
	if(sum > m)	return;

	// 다음 경우
	// 나를 포함
	solve(index+1, cnt+1, sum+arr[index]);

	// 나를 포함하지 않음
	solve(index+1, cnt, sum);
}
int main() {
	// 카드의 합이 21 넘지 않도록, 합을 최대한 크게
	// N장중 3장 카드, M을 넘지 않으면서 M과 최대한 가까운 카드 3장의 합

	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++) {
		scanf("%d", &arr[i]);
	}

	// // 방법 1 : 3중 for문	
	// for(int i=0;i<n;i++) {
	// 	for(int j=0;j<n;j++) {
	// 		if( i == j)	continue;
	// 		for(int k=0;k<n;k++) {
	// 			if ( k == i || k == j )	continue;
				
	// 			int sum = 0;
	// 			sum = arr[i] + arr[j] + arr[k];
	// 			if(sum > ans && sum <= m)
	// 				ans = sum;

	// 		}
	// 	}
	// }

	// 방법 2: 재귀 함수
	solve(0,0,0);

	printf("%d\n", ans);
	
}