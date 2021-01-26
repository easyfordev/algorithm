#include <iostream>
#include <cstring>
using namespace std;

int tc;
int arr[51][51];
bool check[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int ans = 0;

void dfs(int x, int y) {
	check[x][y] = true;

	for(int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(arr[nx][ny] == 1 && check[nx][ny] == false) {
			dfs(nx, ny);
		}

	}

}

int main(){
	scanf("%d", &tc);
	
	while(tc--) {
		int n, m, k;
		
		scanf("%d %d %d", &m, &n, &k);
		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));

		for(int i=0;i<k;i++) {
			int x, y;
			scanf("%d %d", &x, &y);

			arr[y][x] = 1;
		}

		// 필요한 최소 배추흰지렁이 마리 수 출력
		ans = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				// 배추가 있고, 아직 방문안했으면
				if(check[i][j] == false && arr[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}

		printf("%d\n", ans);

	}
}
