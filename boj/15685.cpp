/*
15685. 드래곤 커브

- 드래곤 커브의 다음 세대를 방향 규칙!!을 이해하는게 가장 핵심
    - 이런 시뮬레이션 문제는 패턴이 무조건 있다. 패턴 파악을 잘 하자.
    - 이번 규칙 : 역순으로 돌면서 1씩 증가
- 역순으로 도는 for문 실수했었음 (++ -> --)
*/
#include <iostream>
#include <vector>
using namespace std;

int n; // 주어진 드래곤 커브 개수

// 방향 (0 -오른쪽, 1 - 위쪽, 2 - 왼쪽, 3-아래쪽)
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

// 관리해야 할 자료구조
bool arr[101][101]; // 커브 그리면서 방문했으면 체크

// 드래곤 하나 그릴 때 마다 업데이트
vector<int> dragonDir; // 하나의 드래곤 커브를 그리면서, 지금까지 지나왔던 방향 저장
int ex, ey; // 끝점 위치

int count(){ // 정사각형의 갯수 세기
    int cnt = 0;

    for(int i=0;i<100;i++) {
        for(int j=0;j<100;j++) {
            if(arr[i][j] && arr[i][j+1] && arr[i+1][j] && arr[i+1][j+1])    cnt++;
        }
    }
    return cnt;
}

void dragon(){
    // 지금까지 저장한 방향을 역순으로 돌면서, 새로운 세대를 만들어준다.
    int len = dragonDir.size();
    for(int i=len-1;i>=0;i--) {
        // 주의! 방향 +1 할때 % 꼭 해줘야 함
        int ndir = (dragonDir[i]+1)%4;

        // 방향 기준으로 끝점 좌표 구하기
        ex += dx[ndir];
        ey += dy[ndir];

        // 끝점 방문
        arr[ex][ey] = true;

        // 배열에 저장
        dragonDir.push_back(ndir);
    }
}

void solution(int x, int y, int d, int g){ // 드래곤 커브 그리기
    dragonDir.clear();
    // 일단 0세대 그리기
    // 시작점 방문
    arr[x][y] = true;
    // 방향 기준으로 끝점 좌표 업데이트
    ex = x + dx[d];
    ey = y + dy[d];
    // 끝점 방문
    arr[ex][ey] = true;
    // 배열에 저장
    dragonDir.push_back(d);

    // 나머지 g번 반복하면서 그리기
    for(int i=1;i<=g;i++) {
        dragon();
    }

}

int main(){
    // 입력받으면서 하나씩 드래곤 커브 그리기
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        int x,y,d,g;
        scanf("%d %d %d %d", &y, &x, &d, &g); // (주의!!) x,y좌표 반대로 입력받아야 함

        solution(x,y,d,g);
    }

    // 결과 출력 : 정사각형의 네 꼭짓점이 모두 드래곤커브의 일부인 정사각형의 개수 구하기
    printf("%d\n", count());
}