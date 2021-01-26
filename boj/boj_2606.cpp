#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[101][101]; // 인접행렬
bool check[101];
int ans = 0;
void dfs(int x) { 
	// 현재 정점 방문
	check[x] = true;
	ans++;

	// 다음 정점 선택
	for(int i=1;i<=n;i++) {
		// 인접하고, 아직 방문 안했으면
		if(arr[x][i] == 1 && check[i] == false) {
			dfs(i);
		}
	}
}

int main(){
	// 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수 출력
	scanf("%d %d", &n, &m);

	for(int i=0;i<m;i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	dfs(1);
	printf("%d\n", ans-1);
}
