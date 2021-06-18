/*
17837. 새로운 게임 2
- 맨 처음에 입력받을 떄 모든 자료구조를 잘 초기화 해줘야 함
    - pieces만 넣고, check를 안넣어서 계속 삽질함
- 종료조건 틀렸음
    - vector의 size()는 리턴타입이 int 가 아니라서, 바로 비교연산하면 결과 이상하게 나온다.
    - 반드시 변수로 한번 빼주고, 4 이상인지 비교해야 함
- 파란색, 빈칸일때 방향, 좌표 다시 바꿨으면, color도 바꿔줘야지 ㅠㅠ
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Piece{
public:
    int x, y, dir; // 위치, 이동 방향
    Piece(){
        this->x = 0; this->y = 0; this->dir = 0;
    }
    Piece(int x, int y, int dir) {
        this->x = x;
        this->y = y;
        this->dir = dir;
    }
};
int n, k;

// 방향 (1-오른쪽, 2-왼쪽, 3-위, 4-아래)
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

// 관리해야 할 자료구조
int arr[13][13]; // 보드판. 0-흰색 1-빨 2-파
vector<int> check[13][13];// 맵에 위치한 말 정보. 말의 번호만 딱 저장
vector<Piece> pieces; // 말 정보 저장 (1번말부터 시작. 0번에 더미 넣기)

int oppositeDir(int d) {
    int nd=0;
    if(d == 1)  nd=2;
    else if(d == 2)   nd=1;
    else if(d == 3)   nd=4;
    else if(d == 4)   nd=3;
    return nd;
}

bool solution(){
    // (종료 조건) 턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료됨
    for(int i=1;i<=k;i++) { // 1번 ~ K번 순서대로 이동
        // 1. 이동하려는 칸의 위치 구하기
        int x = pieces[i].x;
        int y = pieces[i].y;
        int dir = pieces[i].dir;

        // 종료조건
        int len = check[x][y].size();
        if(len >= 4) return false;

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // 0. 영역 넘는 경우
        if(!(nx>=1 && nx<=n && ny>=1 && ny<=n)) {
            // 이동방향 반대로 바꿈
            int ndir = oppositeDir(dir);
            pieces[i].dir = ndir;
            nx = x + dx[ndir];
            ny = y + dy[ndir];

            // 또 영역 넘거나, 또 파란색이면 안움직인다.
            if(!(nx>=1 && nx<=n && ny>=1 && ny<=n)) continue;
            if(arr[nx][ny] == 2) continue;
            
            // 하얀색, 빨간색이면 위치 진짜로 바꿔주기
            pieces[i].x = nx;
            pieces[i].y = ny;
        }

        
        int color = arr[nx][ny];
        // 1. 파란색인 경우
        if(color == 2) {
            // 이동방향 반대로 바꿈
            int ndir = op positeDir(dir);
            pieces[i].dir = ndir;
            nx = x + dx[ndir];
            ny = y + dy[ndir];

            // 또 영역 넘거나, 또 파란색이면 안움직인다.
            if(!(nx>=1 && nx<=n && ny>=1 && ny<=n)) continue;
            if(arr[nx][ny] == 2)    continue;

            // 하얀색, 빨간색이면 위치 진짜로 바꿔주기
            pieces[i].x = nx;
            pieces[i].y = ny;
        }

        // 이거때문에 계속 틀렸었음 ㅠㅠㅠㅠㅠㅠㅠ 컬러도 새롭게 바꿔줘야지 ..
        color = arr[nx][ny];
        // 2. 흰색인 경우
        if(color == 0) { // A번 말과 위에 있는 모든 말이 이동함
            // 1) 원래 위치 정리
            // 이번 말의 시작점 구하기
            int idx;
            for(int j=0;j<check[x][y].size();j++) {
                if(check[x][y][j] == i) {// 이번 말 번호이면
                    idx = j;
                    break;
                }
            }

            queue<int> q;
            // 이번 말의 위에 있는 애들 모두 큐에 넣기
            for(int j=idx;j<check[x][y].size();j++)
                q.push(check[x][y][j]);
            
            
            // 삭제(삭제하지 말고, temp 벡터 만들어서 하나씩 넣고 업데이트
            vector<int> temp;
            for(int j=0;j<idx;j++) {
                temp.push_back(check[x][y][j]);
            }

            check[x][y] = temp;
          
            // 2) 새로 옮길 위치에 넣기, 말 정보 업데이트
            while(!q.empty()) {
                check[nx][ny].push_back(q.front());
                // 말 정보 업데이트
                pieces[q.front()].x = nx;
                pieces[q.front()].y = ny;
                q.pop();
            }
        }
        // 3. 빨간색인 경우
        else if(color == 1) {
            // 1) 원래 위치 정리
            // 이번 말의 시작점 구하기
            int idx;
            for(int j=0;j<check[x][y].size();j++) {
                if(check[x][y][j] == i) {// 이번 말 번호이면
                    idx = j;
                    break;
                }
            }
            stack<int> s;
            // 이번 말의 위에 있는 애들 모두 큐에 넣기
            for(int j=idx;j<check[x][y].size();j++)
                s.push(check[x][y][j]);
            
            // 삭제(삭제하지 말고, temp 벡터 만들어서 하나씩 넣고 업데이트
            vector<int> temp;
            for(int j=0;j<idx;j++) {
                temp.push_back(check[x][y][j]);
            }

            check[x][y] = temp;
          
            // 2) 새로 옮길 위치에 넣기, 말 정보 업데이트
            while(!s.empty()) {
                check[nx][ny].push_back(s.top());
                // 말 정보 업데이트
                pieces[s.top()].x = nx;
                pieces[s.top()].y = ny;
                s.pop();
            }

        }
        
        // 종료조건
        len = check[nx][ny].size();
        if(len >= 4) return false;
    }

    return true;
}

int main(){
    // 입력받기
    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    pieces.push_back(Piece(0,0,0)); // 말 index를 번호와 맞추기 위해 0번 넣어준다.
    for(int i=1;i<=k;i++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);

        pieces.push_back(Piece(x,y,d));
        check[x][y].push_back(i); // 이거 처음에 안해줬었음..
        
    }
    
    for(int t=1;t<=1000;t++) {
        if(!solution()) { // 턴이 진행되는 도중에 말이 4개 이상 쌓이면 종료
            printf("%d\n", t);
            
            return 0;
        }
    }

    // 1000번보다 크면 -1
    printf("-1\n");
}
