#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int m, n;
int arr[1001][1001];
int check[1001][1001];
queue< pair<int, int> > q;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int ans = -1;
int cnt = 0;

void bfs(){
	while(!q.empty()) {
		// 큐에서 하나 꺼내기
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 다음 정점 정하기
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >=0 && nx < n && ny >=0 && ny < m) { // 범위 유효하고
				if(arr[nx][ny] != -1 && check[nx][ny] == -1) { // 벽이 아니고 아직 방문 안했으면
					check[nx][ny] = check[x][y] + 1;
					ans = max(ans, check[nx][ny]); // 값 업데이트
					cnt++; // 토마토가 익을때마다 수 증가
					q.push(make_pair(nx, ny));
				}
			}
			
		}
	}
}

int main(){
	// 며칠이 지나면 토마토들이 모두 익는지
	scanf("%d %d", &m, &n);
	memset(check, -1, sizeof(check));

	int hasZero = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = 0;
			}
			if(arr[i][j] == 0)
				hasZero++;
		}
	}
	
	// // 처음부터모든 토마토가 익어있는 상태이면 0 출력
	if(hasZero==0) {
		printf("0\n");
		return 0;
	}

	bfs();

	if(hasZero != cnt) { // 처음에 들어온 0의 갯수와, 돌면서 익은 토마토 갯수가 다르면 다 안익은 것으로 판단
		printf("-1\n");
	} else
		printf("%d\n", ans);


}
