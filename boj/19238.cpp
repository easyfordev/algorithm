/*
19238. 스타트 택시
- 종료조건, 세부 조건 (위치가 같으면 거리 0이라든지)을 꼼꼼하게 처리해야 함
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

class Passenger{
public:
    int sx, sy; // 출발지
    int ex, ey; // 도착지
    int dist; // 지금 내 위치로부터 거리

    Passenger() {
        this->sx = this->sy = this->ex = this->ey = this->dist = 0;
    }

    Passenger(int sx, int sy, int ex, int ey) {
        this->sx = sx; this->sy = sy; this->ex = ex; this->ey = ey; 
        this->dist = 0;
    }
};

int n, m, fuel;

vector<Passenger> passengers; // 승객 관리
int arr[21][21], check[21][21];// 맵

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int tx, ty; // 현재 택시의 위치

bool cmp(const Passenger &a, const Passenger &b) {
    // 최단거리 짧은 순 => 출발지 행 번호 작은 순 => 출발지 열 번호 작은 순
    if(a.dist == b.dist) {
        if(a.sx == b.sx) {
            return a.sy < b.sy;
        } else
            return a.sx < b.sx;
    } else
        return a.dist < b.dist;
}

void bfs(int a, int b){
    memset(check, -1, sizeof(check));

    // 시작점 초기화
    queue<pair<int, int> > q;
    check[a][b] = 0;
    q.push(make_pair(a,b));

    while(!q.empty()) {
        // 큐에서 하나 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 다음 방문할 곳 정하기
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 유효하고,
            // 벽이 아니고, 아직 방문 안했으면
            if(nx>=1 && nx <=n && ny>=1 && ny<=n){
                if(arr[nx][ny] == 0 && check[nx][ny] == -1) {
                    check[nx][ny] = check[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
}

bool solution(){
    // 1. 태울 승객 정하기
    // 1-1. 택시와 손님 거리 구하기
    bfs(tx, ty);

    // 1-2. 승객 정보 업데이트
    for(int i=0;i<passengers.size();i++) {
        // (종료조건) 태우러 못가면 실패
        if(check[passengers[i].sx][passengers[i].sy] == -1) {
            // 택시와 승객이 같은 위치에 있으면 최단거리는 0
            if(passengers[i].sx == tx && passengers[i].sy == ty) {
                passengers[i].dist = 0;
            }
            else return false;
        } else {
            passengers[i].dist = check[passengers[i].sx][passengers[i].sy];
        }
    }
    
    // 1-3. 태우러 갈 승객 정하기
    sort(passengers.begin(), passengers.end(), cmp);
    
    // print();
    Passenger target = passengers[0];

    // 2. (이동) 승객 태우러 가기
    // (종료조건) 연료가 부족하면 실패다.
    if(fuel < target.dist)  return false;
    tx = target.sx;
    ty = target.sy;
    fuel -= target.dist;

    // 3. (이동) 승객 출발지 => 목적지
    // 현재 위치에서 목적지까지 거리 구하기
    bfs(tx, ty);
    int dist = check[target.ex][target.ey];
    
    if(dist == -1)  return false; // (종료조건1) 태우러 못가면 실패
    if(fuel < dist) return false; // (종료조건2) 연료가 부족하면 실패

    // 태우고 간다
    tx = target.ex;
    ty = target.ey;
    fuel -= dist;

    // 승객을 태워 이동하면서 소모한 연료 양의 두배 충전
    // 승객을 목적지로 이동시킨 후에 연료가 바닥나는 경우는 실패한 것으로 간주하지 않음
    fuel += (2*dist);

    // 4. 성공적으로 태워준 승객 없애기
    passengers.erase(passengers.begin());

    return true;
}

int main(){
    // 입력받기
    scanf("%d %d %d", &n, &m, &fuel);

    // 맵
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // 운전 시작점
    scanf("%d %d", &tx, &ty);

    // 승객
    for(int i=0;i<m;i++) {
        int sx, sy, ex, ey;
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        passengers.push_back(Passenger(sx, sy, ex, ey));
    }

    // 승객 수 만큼 반복하는데, 중간에 연료 떨어지면 바로 -1 리턴
    for(int i=0;i<m;i++){
        if(!solution()) {
            printf("-1\n");
            return 0;
        } 
    }
    
    // 끝까지 잘 왔으면, 남은 연료 수 출력
    // 남은 승객
    printf("%d\n", fuel);

    // 결과 출력
    // 모든 승객을 성공적으로 데려다 줄 수 있는지 알아내고,
    // 데려다줄 수 있을 경우 최종적으로 남는 연료의 양 출력
    // 모든 손님을 이동시키고 연료를 충전했을 때, 남은 연료의 양 출력
    // 이동중에 연료가 바닥나서 ** 다음 출발지나 목적지로 이동할 수 없으면 -1 출력
    // (종료조건 2개다!) 모든 손님을 이동시킬 수 없는 경우에도 -1 출력 (벽 같은걸로 막혀있어서)

}