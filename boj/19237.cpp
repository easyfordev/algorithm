/*
19237. 어른 상어
- 관리할 자료구조를 잘 정하는게 제일 중요했다.
    - 번호만 들어있는 arr
    - 냄새 정보(상어번호, 남은 횟수) 들어있는 scentArr
    - 상어의 방향만 관리하는 int []
- 전역변수로 클래스 배열 선언할 떄, 기본 생성자 만들어줘야 함
- 이동할 때, 로직실수 있었다. 최종적으로 이동할 좌표가 정해지고나서, 기존 좌표를 0으로 만들어준다.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;

class Scent {
public:
    int num; // 상어 번호
    int time; // 없어지기까지 남은 시간

    Scent() {
        this->num = 0;
        this->time = 0;
    }
    Scent(int num, int time) {
        this->num = num;
        this->time = time;
    }
};

// 관리해야하는 자료구조 3개
vector<int> sharks; // 현재 상어의 방향 저장. (1~M)

int arr[21][21]; // 맵 (상어의 번호만 저장)
Scent scentArr[21][21]; // 맵 (현재 남겨진 냄새 저장)

// 방향 (1,2,3,4 위,아래,왼쪽,오른쪽)
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
// 우선순위 : 방향에 맞게 입력받아서 넣기 [상어번호][방향][우선순위]
int priority[21*21+1][5][4];

bool solution(){
    // 1. 상어 이동
    // 여러마리가 들어올 수 있으므로 임시 맵으로 관리
    vector<int> tempArr[21][21];
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            // 상어가 있는 칸만 진행
            if(arr[i][j] == 0)  continue;

            int num = arr[i][j];
            int dir = sharks[num];
            
            // 1-1. 아무냄새 없는 칸 중 이동할 칸 고르기
            bool flag = false;
            int nx, ny;
            for(int k=0;k<4;k++) {
                // 현재방향에서 우선순위대로 돈다
                // priority[상어번호][현재방향][0~4]
                int ndir = priority[num][dir][k];
                nx = i + dx[ndir];
                ny = j + dy[ndir];

                // 영역 유효하고, 아무 냄새도 없으면
                if(nx >= 0 && nx < n && ny>=0 && ny<n) {
                    if(scentArr[nx][ny].num == 0) {
                        // 이동하니까, 지금 칸은 빈칸으로 만들어준다.
                        arr[i][j] = 0;
                        // 여기로 방향 정하고 빠져나가기
                        sharks[num] = ndir;
                        tempArr[nx][ny].push_back(num);
                        flag = true;
                        break;
                    }
                }                
            }

            // 1-2. 빈칸 없으면, 자신의 냄새 있는 칸의 방향 고르기
            if(!flag) {
                int num = arr[i][j];
                int dir = sharks[num];


                int nx, ny;
                for(int k=0;k<4;k++) {
                    // 현재방향에서 우선순위대로 돈다
                    // priority[상어번호][현재방향][0~4]
                    int ndir = priority[num][dir][k];
                    nx = i + dx[ndir];
                    ny = j + dy[ndir];

                    // 영역 유효하고, 내 냄새면
                    if(nx >= 0 && nx < n && ny>=0 && ny<n) {
                        if(scentArr[nx][ny].num == num) {
                            // 이동하니까, 지금 칸은 빈칸으로 만들어준다.
                            arr[i][j] = 0;
                            // 여기로 방향 정하고 빠져나가기
                            sharks[num] = ndir;
                            tempArr[nx][ny].push_back(num);
                            flag = true;
                            break;
                        }
                    }                
                }
            }
        }
    }

    // 2. 여러마리 있는 칸은 상어 내쫓기
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int cnt = tempArr[i][j].size();

            // 한마리면, 그냥 넣어주기
            if(cnt == 1) {
                arr[i][j] = tempArr[i][j][0];
            }

            // 한마리보다 많으면
            if(cnt > 1) {
                // 번호로 정렬
                sort(tempArr[i][j].begin(), tempArr[i][j].end());
                arr[i][j] = tempArr[i][j][0];
                // 하나 빼고 다 내쫓기
                m -= (cnt-1);
            }
        }
    }

    // 3. 냄새 뿌리기 
    // 3-1. 기존 냄새 하나 줄이기
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(scentArr[i][j].time > 0) {
                scentArr[i][j].time--;
            }
            // time=0되면, 아얘 내 번호를 지운다.
            if(scentArr[i][j].time == 0) {
                scentArr[i][j].num = 0;
            }
        }
    }

    // 3-2. 새로운 냄새 뿌리기
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j] != 0) {
                scentArr[i][j] = Scent(arr[i][j], k);
            }
        }
    }

    // 종료 조건
    if(m == 1)  return false;
    else return true;
}

// 상어 - 구조체 
int main(){    
    // 입력받기
    scanf("%d %d %d", &n, &m, &k);

    // 맵
    // 0. 맨 처음에는 모든 상어가 자신의 위치에 자신의 냄새를 뿌린다.
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] != 0) { // 상어 번호면, 냄새 초기화
                scentArr[i][j] = Scent(arr[i][j], k);
            }
        }
    }

    // 각 상어의 현재 방향
    sharks.resize(m+1);

    for(int i=1;i<=m;i++) {
        scanf("%d", &sharks[i]);
    }

    // 각 상어의 방향 우선순위 (한 마리당 4줄씩)
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=4;j++) {
            for(int k=0;k<4;k++) {
                scanf("%d", &priority[i][j][k]);
            }
        }
    }
    
    for(int t=1;t<=1000;t++) {
        if (!solution())  {
            // (결과) 1번 상어만 격자에 남게 되기까지 몇 초가 걸리는지 출력
            printf("%d\n", t);
            return 0;
        }
    }

    // 중요!! 1000초가 넘어도 다른 상어가 격자에 남아있으면 -1을 출력한다
    printf("-1\n");
}