/*
SWEA 1949. 등산로 조성 (*)
- 처음에 다 틀렸다.
- 문제 이해 자체가 너무 어려웠다.

- (진짜 중요) 이 문제는 bfs가 아니라 dfs를 해야한다 !!!!!!!!!!!!!!!!!!!
    - 퍼져나가는게 아니라 한 길을 계속 쭉 가야하니까 ...
- 그냥 dfs도 아니고 백트래킹을 해야한다.
    - 작은 애가 사방 중에 여러개일 수 있고, 모든 경우를 다 탐색해야 한다.
- (중요) 원복이 진짜 중요한 문제였다.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int T;
int n, K;
int arr[9][9], check[9][9];
int ans = -1; // 가장 긴 등산로의 길이
vector< pair<int, int> > v; // 가장 높은 봉우리들

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int cnt){
    // 정답 업데이트
    ans = cnt > ans ? cnt : ans;

    // 다음 방문할 점 정하기
    for(int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 영역 유효한지
        if(!(nx>=0 && nx<n && ny>=0 && ny<n))
            continue;
        if(check[nx][ny] != -1)   continue; //  이미 방문했으면 통과
        
        if(arr[nx][ny] < arr[x][y]) { // 나보다 작으면 방문
            check[nx][ny] = check[x][y] + 1;
            dfs(nx, ny, cnt+1);
            check[nx][ny] = -1;
        }
    }
}
void solve(){ 
    // 가장 높은 봉우리부터 시작해서 bfs돌리기
    int len = v.size();

    for(int i=0;i<len;i++) {
        memset(check, -1, sizeof(check));

        check[v[i].first][v[i].second] = 1;
        dfs(v[i].first, v[i].second, 1);
        check[v[i].first][v[i].second] = 0;
    }
}

int main(){
    freopen("sample_input.txt", "r", stdin);

    scanf("%d", &T);

    for(int t=1;t <= T; t++) {
        // 이번 TC에서 쓰는 값 초기화
        int maxV = -1; // 가장 높은 봉우리
        ans = -1;
        v.clear();

        // 입력받기
        scanf("%d %d", &n, &K);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                scanf("%d", &arr[i][j]);
                // 최댓값 구하기
                maxV = maxV > arr[i][j] ? maxV : arr[i][j];
            }
        }
        
        // 1. 가장 높은 봉우리 구하기
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j] == maxV)
                    v.push_back(make_pair(i, j));
            }
        }

        // 아무것도 공사 안한 상태
        solve();
        
        // 공사할 곳 하나씩 고르기
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {                
                // 최대 K 깊이만큼 공사
                for(int amount=1;amount<=K;amount++) {
                    arr[i][j] -= amount;
                    solve();
                    arr[i][j] += amount; // 원복
                }                
            }
        }

        // (결과) 만들 수 있는 가장 긴 등산로의 기이
        printf("#%d %d\n", t, ans);
    }
}

