/* 나는 창의력이 부족한가 ...? ... 
맨 오른쪽 위를 시작점으로 정하고, size 만큼 검사하는건 되게 자주 나오는 아이디어다
분할정복 (재귀)
*/
#include <iostream>
using namespace std;

int arr[129][129];
int n;
int cnt0=0, cnt1=0; // 하얀색 종이 수, 파란색 종이 수

void solve(int x, int y, int size) {
	// 모두 같은 색인지 확인
	int color = arr[x][y];
	bool flag = true;

	for(int i=x;i<x+size;i++) {
		for(int j=y;j<y+size;j++) {
			if(arr[i][j] != color) {
				flag = false;
			}
		}
	}

	if(flag) { // 모두 색이 같으면
		if(color == 0)	cnt0++;
		else cnt1++;
	} else { // 색이 하나라도 다르면, 재귀 호출(분할정복)
		solve(x, y, size/2);
		solve(x+size/2, y, size/2);
		solve(x, y+size/2, size/2);
		solve(x+size/2, y+size/2, size/2);
	}
}

int main(){
	// 입력 받기
	scanf("%d", &n);
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	// 문제 풀기
	solve(0,0,n);
	// 정답
	printf("%d\n%d\n", cnt0, cnt1);

}
