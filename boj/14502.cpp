/*
14502. 연구소
- 처음부터 모두 안전하지 않은경우(빈칸이 하나도 없는 경우) 예외처리
- 벽 세울 후보 배열 최대 크기 잘못잡았음
- 완전탐색 종료 조건 실수. index>size가 아니라 index>=size .. 
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int arr[9][9], dist[9][9]; // 맵, bfs용 (0-빈 칸, 1-벽, 2-바이러스가 있는 위치)
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector< pair<int, int> > v; // 벽을 세울 수 있는 곳(빈칸) 위치 넣기
int s; // 빈 칸의 갯수
bool check[81]; // 벽을 세울 곳 체크

int ans = -1; // 안전영역의 최대 크기 구하기

int calc(){ // 안전영역의 개수 세기
    int cnt = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 0 && dist[i][j] == -1)    cnt++;
        }
    }
    return cnt;
}

void bfs(){ // 바이러스 퍼뜨리기
    // 시작상태 초기화
    memset(dist, -1, sizeof(dist));
    queue< pair<int, int> > q;

    // 바이러스 위치 초기 큐에 넣기
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j] == 2) { // 바이러스면
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
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
            if(nx>=0 && nx<n && ny>=0 && ny<m) {
                if(dist[nx][ny] == -1 && arr[nx][ny] != 1) { // 아직 방문 안했으면서 벽이 아니면
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }

        }
    }
}

void solution(int index, int cnt){ // 검사할 인덱스
    // 정답을 찾은 경우(벽 세울 곳 딱 3개 고르기)
    if(cnt == 3) {
        // 벽 세우기
        for(int i=0;i<s;i++) 
            if(check[i] == true)
                arr[v[i].first][v[i].second] = 1;

        // 바이러스를 퍼뜨린다.
        bfs();
        // 안전영역의 갯수 세기
        int result = calc();
        ans = result > ans ? result : ans;

        // 벽 세운거 원복
        for(int i=0;i<s;i++) 
            if(check[i] == true)
                arr[v[i].first][v[i].second] = 0;
        return;
    }

    // 불가능한 경우
    if(index >= s) return;

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
        for(int j=0;j<m;j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 0) { // 빈 칸
                v.push_back(make_pair(i, j));
                zero++;
            }
        }
    }
    // 예외처리
    if(zero == 0) {
        printf("0\n");
        return 0;
    }

    s = v.size();

    // 완전탐색
    solution(0, 0);
    
    // 안전 영역의 최대 크기 구하기
    printf("%d\n", ans);
}
