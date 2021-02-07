/* 시뮬레이션 
아래 사람들꺼 참고해서 풀었다. 1시간 쫌 안걸린듯.
진짜 차분히 그냥 돌려주면 된다

https://intaehwang.tistory.com/100
https://yabmoons.tistory.com/267
*/

#include <iostream>
#include <cstring>
using namespace std;
int n, m, r;
int arr[301][301], temp[301][301];

void rotate() { // 한 번 회전
    bool check[301][301] = {false};

    // 시작점 정하기
    int x1=0, y1=0; // 시작점
    int x2=n-1, y2=0;
    int x3=n-1, y3=m-1;
    int x4=0, y4=m-1;

    // 모든 점을 다 회전함
    while(true) {
        // 종료조건
        if(check[x1][y1])  break;

        // 회전하기
        // 아래로 -> 오른쪽으로 -> 위로 -> 왼쪽으로
        for(int i=x1;i<x2;i++) {
            temp[i+1][y1] = arr[i][y1];
            check[i+1][y1] = true;
        }

        for(int j=y2;j<y3;j++) {
            temp[x2][j+1] = arr[x2][j];
            check[x2][j+1] = true;
        }

        for(int i=x3;i>x4;i--) {
            temp[i-1][y3] = arr[i][y3];
            check[i-1][y3] = true;
        }

        for(int j=y4;j>y1;j--) {
            temp[x4][j-1] = arr[x4][j];
            check[x4][j-1] = true;
        }

        // 다음을 위해 네 꼭지점 업데이트
        x1++, y1++;
        x2--, y2++;
        x3--, y3--;
        x4++, y4--;
    }  
}

int main() {
    scanf("%d %d %d", &n, &m, &r);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    // R번 회전
    while(r--) {
        rotate();
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