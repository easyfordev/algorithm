/*
16236. 아기상어
- (컴파일에러) : reference to ‘size’ is ambiguous
    - s로 바꿔줬다. 변수명 기존 함수/변수 키워드와 겹치는거 쓰지 말자
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

class Fish{
public:
    int x, y, dist;
    Fish() {
        this->x = 0;
        this->y = 0;
        this->dist = 0;
    }
    Fish(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

int n;
int arr[21][21], check[21][21];// 맵, bfs용
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

pair<int, int> shark;// 아기상어 위치
int s=2;// 아기상어 크기
int mari=0;// 아기상어가 잡아먹은 마리 수

int times = 0;

bool cmp(const Fish &a, const Fish &b) {
    // 거리가 가까운 물고기 -> 가장 위에 있는 물고기 -> 가장 왼쪽에 있는 물고기
    if(a.dist == b.dist) {
        if(a.x == b.x) {
            return a.y < b.y;
        } else
            return a.x < b.x;
    } else
        return a.dist < b.dist;
}

void bfs(int a, int b){
    // (주의!!!) 벽같은 존재.. 지나갈 수 있는 물고기 : 크기가 같거나 작은 물고기(크기가 크면 지나갈 수 없음)
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

        // 다음 방문할 점 정하기
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 유효하고, 아직 방문 안했으면서
            if(nx>=0 && nx < n && ny>=0 && ny<n) {
                // 나보다 크기 같거나 작으면 지나갈 수 있음
                if(check[nx][ny] == -1 && arr[nx][ny] <= s) {
                    check[nx][ny] = check[x][y] +1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
}

bool solution(){
    // 1. 먹으러 갈 물고기 정하기
    // 1-1. 거리 구하기
    bfs(shark.first, shark.second);

    // 1-2. 먹을 수 있는 물고기 후보들
    vector<Fish> fishes;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            // check 값이 -1이 아니고, 나도 아니고
            if(check[i][j] != -1 && check[i][j] != 0) {
                // 물고기가 있는 칸이고, 나보다 작은 애들만 먹을 수 있음
                if(arr[i][j] == 0 || arr[i][j] == 9)  continue;
                if(arr[i][j] < s) {
                    fishes.push_back(Fish(i, j, check[i][j]));
                }
            }
        }
    }

    // 1-3. 그 중에 우선순위 제일 높은 애 (정렬)
    // (종료조건) 먹으러 갈 수 있는 물고기가 없으면 종료
    if(fishes.size() == 0)  return false;
    Fish target;

    // 먹을 수 있는 물고기가 1마리면, 그 물고기를 먹으러 간다.
    if(fishes.size() == 1) {
        target = fishes[0];
    } else { // 먹을 수 잇는 물고기가 1마리보다 많으면, 거리가 가장 가까운 물고기를 먹으러 간다.
        sort(fishes.begin(), fishes.end(), cmp);
        target = fishes[0];
    }

    // 2. 이동하기
    // 맵 변경
    // 물고기 있던 칸,
    arr[target.x][target.y] = 9;
    // 상어 있던 칸
    arr[shark.first][shark.second] = 0;

    // 상어 상태 변경
    // 마리, 크기
    mari++;
    if(mari == s) { // 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가
        s++;
        mari = 0;
    }

    // 위치
    shark.first = target.x;
    shark.second = target.y;
    // 이동 시간 더하기
    times += target.dist;

    // 끝까지 잘 왔으면 true 리턴
    return true;
}

int main(){
    // 입력받기
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]); // 0-빈칸, 1~6:물고기, 9:아기상어 위치

            if(arr[i][j] == 9) { // 상어 위치 넣어주기
                shark.first = i;
                shark.second = j;
            }
        }
    }

    while(true) {
        if(!solution()) break;
    }
    
    // 결과 출력 : 아기상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지
    printf("%d\n", times);
}