/*
17142. 연구소 3
    - 예외처리 안해줬었다! 맨 처음부터 모든 빈 칸이 차있는 경우
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int arr[51][51], dist[51][51]; // 맵, bfs용
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector< pair<int, int> > viruses; // 바이러스를 놓을 수 있는 곳 후보
int virusesSize = 0;
bool check[10]; // 활성화시킬 바이러스 체크

int ans = 99999999; // 모든 빈 칸에 바이러스가 있게 되는 최소 시간

int validate(){ // 걸린 시간 구하기 && 모든 빈 칸에 바이러스를 잘 퍼뜨렸는지 검사
    // 모든 빈 칸에 바이러스를 잘 퍼뜨렸는지 검사
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            // 빈칸인데, 아직 -1이면 안된다
            if(arr[i][j] == 0 && dist[i][j] == -1)
                return -1;
        }
    }

    // 빈 칸 중 최댓값 구하기
    int maxV = -1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j] == 0) { // 원래 빈칸이었던 애들 중에서,
                if(dist[i][j] > maxV)   maxV = dist[i][j];
            }
        }
    }

    return maxV;
}

void bfs(){ // 바이러스 퍼뜨리기
    // 시작상태 초기화
    memset(dist, -1, sizeof(dist));
    queue< pair<int, int> > q;

    // 선택한 바이러스 위치 초기 큐에 넣기
    for(int i=0;i<virusesSize;i++) {
        if(check[i]) {
            dist[viruses[i].first][viruses[i].second] = 0;
            q.push(make_pair(viruses[i].first,viruses[i].second));
        }
    }

    while(!q.empty()) {
        // 큐에서 하나 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 다음 방문할 정점 고르기
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 유효하고,
            if(nx>=0 && nx<n && ny>=0 && ny<n) {
                if(dist[nx][ny] == -1 && arr[nx][ny] != 1) { // 아직 방문 안했으면서 벽이 아니면
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }

        }
    }
}

void solution(int index, int cnt){ // 검사할 인덱스
    // 정답을 찾은 경우 (M개 고르기)
    if(cnt == m) {
        bfs();

        // 걸린 시간(최댓값) 구하기 && 모든 칸에 바이러스를 잘 퍼뜨렸는지 검사
        int result = validate();
        if(result != -1) {
            ans = result < ans ? result : ans;
        }
        return;
    }

    // 불가능한 경우
    if(index > virusesSize) return;

    // 다음 경우
    // 이번 선택
    check[index] = true;
    solution(index+1, cnt+1);

     // 이번 선택 안함
    check[index] = false;
    solution(index+1, cnt);
}

int main(){
    // 입력받기
    scanf("%d %d", &n, &m);

    int zero = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 2) { // 바이러스를 놓을 수 있는 곳
                viruses.push_back(make_pair(i, j));
            } else if(arr[i][j] == 0)
                zero++;
        }
    }
    // 예외처리 안해줬었다! 맨 처음부터 모든 빈 칸이 차있는 경우
    if(zero == 0)   {
        printf("0\n");
        return 0;
    }
    virusesSize = viruses.size();

    // 완전탐색
    solution(0, 0);
    
    // 결과 : '모든 빈 칸'에 바이러스를 퍼뜨리는 최소 시간 구하기
    // 바이러스를 어떻게 놓아도 모든 빈 칸에 퍼뜨릴 수 없는 경우 -1 출력
    if(ans == 99999999)    printf("-1\n");
    else printf("%d\n", ans);
    
}
