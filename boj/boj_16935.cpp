/* 시뮬레이션 
한번에 맞긴 했지만, 푸는데 너무 오래걸렸다.(1시간 20분..)
*/
#include <iostream>
#include <cstring>
using namespace std;

int n, m, r;
int arr[101][101], temp[101][101];

void calc(int op){
    // 연산 수행하고, n과 m의 값을 변경한다
    if (op == 1) { // 상하 반전
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                temp[n-1-i][j] = arr[i][j];
            }
        }
    } else if (op == 2) { // 좌우 반전
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                temp[i][m-1-j] = arr[i][j];
            }
        }
    } else if (op == 3) { // 오른쪽 90도
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                temp[j][n-1-i] = arr[i][j];
            }
        }
        // n과 m을 바꾼다
        int t = n;
        n = m;
        m = t;
    } else if (op == 4) { // 왼쪽 90도
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                temp[m-1-j][i] = arr[i][j];
            }
        }
        // n과 m을 바꾼다
        int t = n;
        n = m;
        m = t;
    } else if (op == 5) { // 영역 1 -> 2 .... 로 바꾸기
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                // 범위에 따라 영역 나누고, 영역에 맞게 이동함
                if( i>=0 && i<n/2 && j >=0 && j < m/2) { // 1번영역
                    temp[i][j+m/2] = arr[i][j];
                    // temp[i][j] = 1;
                } else if (i>=0 && i<n/2  && j>=m/2 && j < m ) { // 2번영역
                    temp[i+n/2][j] = arr[i][j];
                    // temp[i][j] = 2;
                } else if ( i>=n/2 && i<n && j>=m/2 && j < m ) { // 3번영역
                    temp[i][j-m/2] = arr[i][j];
                    // temp[i][j] = 3;
                } else if ( i>=n/2 && i<n && j >=0 && j < m/2  ) { // 4번영역
                    temp[i-n/2][j] = arr[i][j];
                    // temp[i][j] = 4;               
                }
            }
        }
    } else if (op == 6) { // 영역 4 -> 1 .... 로 바꾸기
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                // 범위에 따라 영역 나누고, 영역에 맞게 이동함
                if( i>=0 && i<n/2 && j >=0 && j < m/2) { // 1번영역
                    temp[i+n/2][j] = arr[i][j];
                    // temp[i][j] = 1;
                } else if (i>=0 && i<n/2  && j>=m/2 && j < m ) { // 2번영역
                    temp[i][j-m/2] = arr[i][j];
                    // temp[i][j] = 2;
                } else if ( i>=n/2 && i<n && j>=m/2 && j < m ) { // 3번영역
                    temp[i-n/2][j] = arr[i][j];
                    // temp[i][j] = 3;
                } else if ( i>=n/2 && i<n && j >=0 && j < m/2  ) { // 4번영역
                    temp[i][j+m/2] = arr[i][j];
                    // temp[i][j] = 4;               
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &r);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int tc = r;
    // R개의 연산 수행
    while(tc--) {
        scanf("%d", &r);
        
        calc(r);

        memcpy(arr, temp, sizeof(temp));
    }

    // 맨 마지막 결과 출력
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}