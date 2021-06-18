/*
19236. 청소년 상어

- 진짜 노답이다. 진짜 진짜 노답이다. 사람이 자기 마음대로 뭘 하려고하면 잘 안된다 ... 진짜로 하나님께 맡겨야한다.
- 아래 두 블로그 보고, 진짜 그냥 코드 따라치자. 그리고 내 입맛에 맞게 바꾸자. 그러면서 익히자.
https://imnotabear.tistory.com/386
https://jaimemin.tistory.com/1481

- move_fishes()에서 틀렸음
    -  방향 다시 잡을거면 nx랑 ny도 다시 초기화 해줘야지..
- 또 맨처음에 모든 TC 다틀렸다............ 하.......
    - move_fishts()가 또 이상했다.
    - 방향 %로 바꿀 때, 8 넘어가면 1로 바꿔야하는데 0으로 바뀌었다
- 이번엔 move_shark()에서 잘못됐다.
    - 문제 접근 자체가 틀렸다. 그리디하게 푸는게 아니라 완전탐색으로 풀어야 한다.
    - dfs(재귀)로 풀어야함. 지금 당장 최대값을 먹는다고 끝까지 최대인 그리디적인 접근으로 풀면 안된다 !!!!!!!!!!!!!!!
- 진~짜 중요한 거! 재귀로 풀 때, 배열을 복사해서 넘겨야한다.
    - 벡터는 어떻게 넘기징?
    - 벡터든 배열이든, 값만 넘기는거니까 진짜 그냥 맨 처음에 배우는 아무것도 모르는 사람처럼 넘기면 된다.
    - 근데, 그냥 다 사이즈 정해져있으니까 2차원 배열로 넘기자.
    - 값 copy할때, 그냥 for문 돌면서 함수 만들어서 복사하자. 이게 제일 안전해 ㅠㅠ
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Fish{
public:
    int x, y, num, dir;
    bool ate;

    Fish(int x, int y, int num, int dir) {
        this->x = x;
        this->y = y;
        this->num = num;
        this->dir = dir;
        this->ate = false;
    }
};

class Shark {
public:
    int x, y, dir;
    Shark() {
        this->x = 0;
        this->y = 0;
        this->dir = 0;
    }
    Shark(int x, int y, int dir) {
        this->x = x;
        this->y = y;
        this->dir = dir;
    }
};

void solution(vector<Fish> fishes, int arr[5][5], Shark shark, int sum);
void move_fishes();
void move_shark(vector<Fish> fishes, int arr[5][5], Shark shark, int sum);
int arr[5][5]; // 맵. (int)로 물고기의 번호를 넣자. 0은 빈칸이고, 1~16은 물고기, -1은 상어
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1}; // 방향 - 1~8. 위부터 반시계 
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

vector<Fish> fishes; // 물고기들
Shark shark; // 상어

int ans = 0; // 먹은 물고기 번호의 최댓값

bool cmp(const Fish &a, const Fish &b) { // 번호가 빠른 애가 앞으로 정렬. 번호 같은 애 없음
    return a.num < b.num;
}

void print(){
    // 물고기 상태 출력 (아직 안 먹힌 물고기만)
    printf("==================\n");
    printf("상어 - (%d, %d), dir - %d\n", shark.x, shark.y, shark.dir);


    for(int i=0;i<fishes.size();i++) {
        if(fishes[i].ate == false) 
            printf("%d번 물고기 - (%d, %d), dir - %d\n", fishes[i].num, fishes[i].x, fishes[i].y, fishes[i].dir);
    }
    printf("\n");

    // 맵 상태 출력
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void move_fishes(){
    // 1. 이후 물고기 이동
    // 번호가 작은 물고기부터 순서대로 이동
    for(int i=1;i<fishes.size();i++) {
        // 이미 먹힌 물고기면 이동하지 않음
        if(fishes[i].ate == true)   continue;
        // printf("%d번 물고기 \n", fishes[i].num);

        int x = fishes[i].x, y = fishes[i].y, dir = fishes[i].dir;
        int nx = x, ny = y, ndir = dir;

        // 이동할 수 있는 칸 찾기
        bool flag = false;
        for(int k=0;k<8;k++) { // 이동할 수 있는 칸을 향알 때 까지 방향을 45도 반시계 회전시킴
            // printf("내 방향 : %d\n", ndir);
            nx += dx[ndir];
            ny += dy[ndir];

            // 이동 조건 - 영역이 유효하고, 상어가 아니면
            if(nx >= 0 && nx <4 && ny>=0 && ny<4) {
                if(arr[nx][ny] != -1) {
                    flag = true;
                    break;
                }
            }
            
            // 여기까지 왔으면 방향 바꾸고 다시
            // (여기서 틀림) nx랑 ny도 다시 초기화 해줘야지..
            nx -= dx[ndir];
            ny -= dy[ndir];
            ndir = ndir == 8 ? 1 : ndir+1; // (여기서 또 틀림) %로 방향 바꾸는 로직 망했다.
            // ndir = ndir == 8 ? 1 : (ndir+1)%8;
            continue;
        }
        // 이동할 수 있는 칸이 없으면 이동하지 않는다.
        if (!flag)   {
            // printf("난 못움직여!!\n");
            continue;
        }
        // printf("새로운 이동 방향 : %d\n", ndir);

        // 이동할 수 있으면 이동함
        // (완전 큰 오류를 범했다)
        // 이동할 수 있는 칸은 2가지 종류가 있다. 빈칸인 경우와 물고기가 있는 경우를 나눠서 처리해줘야 한다.
        if(arr[nx][ny] == 0) {
            // 빈 칸이면, 그냥 가면 된다.
            arr[nx][ny] = fishes[i].num;
            arr[x][y] = 0;

            fishes[i].x = nx;
            fishes[i].y = ny;
            fishes[i].dir = ndir;

        } else {
            // 이동할때는, 원래 그 칸에 있던 물고기와 서로 위치를 바꾸는 방식으로 이동
            int target = arr[nx][ny];

            // 맵도 바꿔야함
            arr[nx][ny] = fishes[i].num;
            arr[x][y] = target;

            // 벡터도 바꾸고
            fishes[i].x = nx;
            fishes[i].y = ny;
            fishes[i].dir = ndir;

            fishes[target].x = x;
            fishes[target].y = y;
        }
        
        // print();
    }
}

void move_shark(vector<Fish> fishes, int arr[5][5], Shark shark, int sum){
    // 2. 상어 이동
    // int flag = -1; // 이번 턴에 이동했으면 먹은 물고기 번호의 최댓값을, 이동 안했으면 -1을 리턴
    // 설마 ... dfs(재귀)로 풀어야하나..? 지금 당장 최대값을 먹는다고 끝까지 최대인 그리디적인 접근으로 풀면 안되는건가 !!!!!!!!!!!!!!!

    int x = shark.x;
    int y = shark.y;
    int dir = shark.dir;

    // int target = -1; // 먹을 수 있는 물고기 번호의 최댓값
    int nx=x, ny=y;

    for(int i=1;i<=3;i++) { // 가능한 경우 탐색하면서 무조건 최대로 이동
        // 이동할 수 있는지 검사
        nx += dx[dir];
        ny += dy[dir];

        // 범위가 유효하고, 물고기가 있으면
        if(!(nx >=0 && nx < 4 && ny>=0 && ny<4)) continue;
    
        if(1 <= arr[nx][ny] && arr[nx][ny] <= 16) {
            // target = arr[nx][ny] > target ? arr[nx][ny] : target;
            // 원래 상태 카피
            int tempArr[5][5];
            vector<Fish> tempFishes;
            
            for(int i=1;i<=16;i++)  tempFishes[i] = fishes[i];
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                tempArr[i][j] =  arr[i][j];

            int target = arr[nx][ny];
            // int target_x = fishes[target].x;
            // int target_y = fishes[target].y;
            // printf("이번에 먹을 물고기 : %d번\n", target);
            tempArr[fishes[target].x][fishes[target].y] = -1;
            tempArr[x][y] = 0;

            // 벡터 변경
            tempFishes[target].ate = true;

            shark.x = fishes[target].x;
            shark.y = fishes[target].y;
            shark.dir = fishes[target].dir;

            // arr[fishes[target].x][fishes[target].y] = -1;
            // arr[x][y] = 0;

            // // 벡터 변경
            // fishes[target].ate = true;
            // shark.x = fishes[target].x;
            // shark.y = fishes[target].y;
            // shark.dir = fishes[target].dir;

            solution(tempFishes, tempArr, shark, sum + target);
        }
    }
    
    // 진짜로 이동
    // 이동했다면, 그 칸에 있는 물고기를 먹고, 그 물고기의 방향을 가지게 된다.
    // printf("이번에 먹을 물고기 : %d번\n", target);
    // if(target != -1) {
    //     // 맵 변경
    //     arr[fishes[target].x][fishes[target].y] = -1;
    //     arr[x][y] = 0;

    //     // 벡터 변경
    //     fishes[target].ate = true;
    //     shark.x = fishes[target].x;
    //     shark.y = fishes[target].y;
    //     shark.dir = fishes[target].dir;

    // }

    // (종료 조건) 
    // return target;
}

void solution(vector<Fish> fishes, int arr[5][5], Shark shark, int sum){
    printf("====현재까지 합 : %d\n", sum);
    // 정답 업데이트
    ans = sum > ans ? sum : ans;
    // while(true) {
        // 1. 물고기 이동
    move_fishes();
        // print();
        // 2. 상어 이동
        // move_shark(fishes, arr, shark, sum);
                // print();

        // if(result == -1) return; // (종료조건) 상어가 이동할 수 있는 칸이 없으면, 공간에서 벗어나 집으로 간다.
        // else sum += result;
    // }
    print();

    int x = shark.x;
    int y = shark.y;
    int dir = shark.dir;

    // // int target = -1; // 먹을 수 있는 물고기 번호의 최댓값
    int nx=x, ny=y;

    while(true) { // 가능한 경우 탐색하면서 무조건 최대로 이동
        // 이동할 수 있는지 검사
        nx += dx[dir];
        ny += dy[dir];

    //     // 범위가 유효하고, 물고기가 있으면
        if(!(nx >=0 && nx < 4 && ny>=0 && ny<4)) break;
    
        if(1 <= arr[nx][ny] && arr[nx][ny] <= 16) {
    //         // target = arr[nx][ny] > target ? arr[nx][ny] : target;
    //         // 원래 상태 카피
            int tempArr[5][5];
            vector<Fish> tempFishes;
            // tempFishes.resize(17);
            tempFishes = fishes;

            // Shark tempShark = Shark();
            
            for(int i=1;i<=16;i++)  tempFishes[i] = fishes[i];
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    tempArr[i][j] =  arr[i][j];

            int target = arr[nx][ny];
    //         // int target_x = fishes[target].x;
    //         // int target_y = fishes[target].y;
            printf("이번에 먹을 물고기 : %d번\n", target);
            tempArr[fishes[target].x][fishes[target].y] = -1;
            tempArr[x][y] = 0;

            // 벡터 변경
            tempFishes[target].ate = true;

            shark.x = fishes[target].x;
            shark.y = fishes[target].y;
            shark.dir = fishes[target].dir;

    //         // arr[fishes[target].x][fishes[target].y] = -1;
    //         // arr[x][y] = 0;

    //         // // 벡터 변경
    //         // fishes[target].ate = true;
    //         // shark.x = fishes[target].x;
    //         // shark.y = fishes[target].y;
    //         // shark.dir = fishes[target].dir;
            
            solution(tempFishes, tempArr, shark, sum + target);
        }
    }
}

int main(){
    // 입력받기
    // 인덱스 맞춰주기 위해 맨 앞에 0번 물고기를 넣어준다.
    fishes.push_back(Fish(0,0,0,0));

    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            int a, b; // 번호, 방향
            scanf("%d %d", &a, &b);
            fishes.push_back(Fish(i,j,a,b));
            arr[i][j] = a;
        }
    }
    // 번호 순서대로 정렬
    sort(fishes.begin(), fishes.end(), cmp);
    
    // 0. 맨 처음에 들어가기
    // (0,0)에 있는 물고기를 먹는다.
    int target = arr[0][0];
    // 상어의 위치, 방향 변경
    shark.x = 0; shark.y = 0;
    shark.dir = fishes[target].dir;
    arr[0][0] = -1;

    // 먹힌 물고기 상태 변경
    fishes[target].ate = true;

    solution(fishes, arr, shark, target); // 맨 처음에 먹은 합에 물고기 번호 수 더해주기

    // 3. 결과 출력 : 상어가 먹울 수 있는 물고기 번호의 합의 최댓값
    printf("%d\n", ans);
    
}