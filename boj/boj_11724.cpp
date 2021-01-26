#include <iostream>
using namespace std;
int n, m;
int arr[1001][1001];
bool check[1001];

void dfs(int x) {
	check[x] = true;

	// 다음 방문할 정점 고르기
	for(int i=1;i<=n;i++) {
		if(i == x)	continue;
		if(arr[x][i] == 1 && check[i] == false)
			dfs(i);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	
	for(int i=0;i<m;i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	int ans = 0;

	for(int i=1;i<=n;i++) {
		if(check[i] == false) {
			dfs(i);
			ans++;
		}
	}

	printf("%d\n", ans);

}
