/*
20057. 마법사 상어와 토네이도

(내 마음을 대변해주는 글이다.)
그동안 삼성에서 자주 출제되던 시뮬레이션 문제들과 사뭇 다른 느낌의 시뮬레이션 문제이다.
- 상하좌우 움직임이 아닌 토네이도
- 순차적인 시뮬레이션이 아닌 단순 수치 계산
- 그래프 탐색 또는 완전탐색 개념의 부재
크게 이 3가지로 인해 꾸준히 삼성 기출을 풀어오던 사람이라면 조금 낯설게 느껴질 수 있다. 
하지만 이러한 유형은 정확하고 효율적으로 구현하는 방법을 떠올리거나 비슷한 문제를 한 번이라도 풀어봤다면,
그동안의 기출 문제보다 훨씬 짧은 시간 안에 해결할 수 있다.

- 토네이도 이동은 '패턴'을 찾아내야 함 (겁먹지 말자. 무조건 패턴 있다.)
- 흩날리는 모래 : 모든 좌표 (상대적으로) 다 저장 (겁먹지 말자. 좌표 몇개 안된다.)

- 처음에 TC 1개 빼고 다 틀렸다.
    - 이유 : 와 수식 계산 딱 한줄 괄호 순서를 다르게 했다 ...... 똑같은줄 알았는데 ㅠㅠ
        int 형변환이 일어나니까 !!!!!! 정수 짤리니까 !!! 나누기 먼저 하면 0 나온다.
        전 ) int amount = originalSand * (proportion[i]/100);
        후 ) int amount = (originalSand * proportion[i])/100;
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[500][500]; // 모래의 양
int ans = 0; // 격자 밖으로 나간 모래의 양

// 이동 방향 ( 서 - 남 - 동 - 북)
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

// 흩날리는 비율 순서대로 
int proportion[9] = {1, 1, 7, 7, 10, 10, 2, 2, 5};
// 방향에 따른 흩날리는 칸 (맨 마지막은 a)
int xdx[4][10] = {
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, // 서
    {0, 0, 1, 1, 2, 2, 1, 1, 3, 2}, // 남
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, // 동
    {0, 0, -1, -1, -2, -2, -1, -1, -3, -2} // 북
};
int ydy[4][10] = {
    {0, 0, -1, -1, -2, -2, -1, -1, -3, -2}, // 서
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, // 남
    {0, 0, 1, 1, 2, 2, 1, 1, 3, 2}, // 동
    {-1, 1, -1, 1, -1, 1, -2, 2, 0, 0} // 북
};


void spread(int x, int y, int dir){ // 시작점, 이동중인 방향
    // 목적지
    int xx = x + dx[dir];
    int yy = y + dy[dir];

    // 모래가 없으면 퍼뜨릴게 없다
    if(arr[xx][yy] == 0)    return;

    int sand = arr[xx][yy]; // 목적지에 있는 모래 양
    int originalSand = sand; // 처음 값 저장

    // 비율만큼 모래 뿌리기
    for(int i=0;i<9;i++) {
        int nx = x + xdx[dir][i];
        int ny = y + ydy[dir][i];

        // 옮길 양
        int amount = (originalSand * proportion[i])/100;
        sand -= amount; // 모래에서 뺀다.

        // 격자 밖으로 빠져나가면, 정답에 더하고 넘어가기
        if(!(nx >=1 && nx <=n && ny>=1 && ny <=n)) {
            ans += amount;
        } else { // 영역 안이면, 모래의 양을 더해주기
            arr[nx][ny] += amount;
        }
    }

    // 남은 모래 a에 뿌리기
    int nx = x + xdx[dir][9];
    int ny = y + ydy[dir][9];

    // 격자 밖으로 빠져나가면, 정답에 더하고 넘어가기
    if(!(nx >=1 && nx <=n && ny>=1 && ny <=n)) {
        ans += sand;
    } else { // 영역 안이면, 모래의 양을 더해주기
        arr[nx][ny] += sand;
    }

    // y에는 아무것도 안남는다
    arr[xx][yy] = 0;
}

void solution(){
    // 가운데에서 시작
    // 맨 처음에 가운데를 잘못잡았다.
    int x = (n+1)/2;
    int y = (n+1)/2;
    int d = 0;
    int moveCnt = 1;

    while(true) {
        // 1. 이동
        // 한번에 한 칸 이동
        // 이동은 <- 서쪽부터 시작해서, 2번씩 같은 cnt를 반복한다.
        for(int i=0;i<2;i++) { // 방향 바꾸기
            for(int j=0;j<moveCnt;j++) { // cnt 만큼 이동
                // 2. 흩날리기 (한 칸 이동할 때 마다)
                spread(x, y, d);
                x += dx[d];
                y += dy[d];
            }
            d = (d+1)%4; // 방향 바꾸기
        }
        moveCnt++;

        // 토네이도 끝났으면, 한번만 더 <- 쭉 가고 끝난다.
        if(moveCnt == n) {
            for(int j=0;j<moveCnt;j++) {
                spread(x, y, d);
                x += dx[d];
                y += dy[d];
            }
            break;
        }
    }
}

int main(){
    // 입력 받기
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    solution();

    // 격자 밖으로 나간 모래의 양 구하기
    printf("%d\n", ans);
}



