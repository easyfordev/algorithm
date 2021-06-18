/*
13460. 구슬 탈출 2
- 4차원 배열로 현재 상태를 방문한 적 있는지 저장
- 왜 BFS를 써야하지?
    - 동시에 여러 경우의 수로 계속 뻗어나가고, **최소 단계를 찾는거니까** BFS임
    - 모든 경우를 다 해봐야 풀 수 있는 것이 아니라 최소 거리를 구하는 것이기 때문에 bfs를 통해 풀면 된다!
    - 근데, 재귀(DFS)를 통한 완전탐색으로 풀어도 된다.
*/
#include <iostream>
#include <queue>
using namespace std;

class State {
public:
    int rx, ry, bx, by, cnt; // 지금까지 움직인 횟수
    State(int rx, int ry, int bx, int by, int cnt){
        this->rx = rx;
        this->ry = ry;
        this->bx = bx;
        this->by = by;
        this->cnt = cnt;
    }
    State(){
        this->rx = 0; this->ry = 0;
        this->bx = 0; this->by = 0;
        this->cnt = 0;
    }
};
char arr[11][11];
int n, m;

queue< State > q;
bool check[11][11][11][11]; // [rx][ry][bx][by]

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void move(int &x, int &y, int &c, int d) { // d방향으로 벽이나 구멍을 만날때까지 이동
    while(true) {
        if(arr[x + dx[d]][y+dy[d]] != '#' && arr[x][y] != 'O') {
            x += dx[d];
            y += dy[d];
            c++;
        } else {
            return;
        }
    }
}

void bfs() {
    // 빨간 구슬을 빼내면 여기서 아얘 출력하고 프로그램 종료
    // 파란 구슬 빼내면, 여기서 아얘 안된다고 -1 출력하고 프로그램 종료

    while(!q.empty()) {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int cnt = q.front().cnt;
        q.pop();

        // 종료조건(딱 10번만 움직인다)
        if(cnt >= 10)  break;
        
        // 네 방향으로 모두 움직이기(다음으로 방문할 상태를 정한다)
        for(int i=0;i<4;i++) {
            int dir = i;
            int nrx = rx;
            int nry = ry;
            int nbx = bx;
            int nby = by;
            int rc=0, bc=0;
            // 빨간구슬 움직이기
            move(nrx, nry, rc, dir);
            // 파란구슬 움직이기
            move(nbx, nby, bc, dir);

            // 파란 구슬 먼저 빠지나 검사
            if(arr[nbx][nby] == 'O') {
                continue; // 여기 틀렸었다. 종료가 아니라 이번 케이스는 넘어가는거다.
            }
            
            // 빨간 구슬 빠졌나 검사
            if(arr[nrx][nry] == 'O') {
                printf("%d\n", cnt+1); // 빠졌으면 게임 종료
                return;
            }

            // 둘다 안빠지고, 둘이 위치 같으면 보정
            if(nrx == nbx && nry == nby) {
                if(rc>bc)   { // 더 많이 움직인 애를 하나 뒤로 빼준다
                    nrx -= dx[dir];
                    nry -= dy[dir];
                } else {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }
            
            // 상태 방문하고 넣기
            if(check[nrx][nry][nbx][nby] == false) {
                check[nrx][nry][nbx][nby] = true;
                q.push(State(nrx, nry, nbx, nby, cnt+1));
            }

        }
    }
   
    printf("-1\n");
}

int main(){
    scanf("%d %d", &n, &m);
    getchar();
    
    int rx, ry, bx, by; // 현재 구슬의 위치

    // . - 빈 칸, # - 벽 또는 장애물 , O - 구멍, R-빨간구슬 , B-파란구슬
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%1c", &arr[i][j]);
            if(arr[i][j] == 'R') {
                rx = i; ry = j;
                arr[i][j] = '.';
            }
            else if(arr[i][j] == 'B') {
                bx = i; by = j;
                arr[i][j] = '.';
            }
        }
        getchar();
    }

    // 시작점 넣기
    check[rx][ry][bx][by] = true;
    q.push(State(rx, ry, bx, by, 0));

    // 보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램
    bfs();
    
}

