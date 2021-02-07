/* 슬라이딩 윈도우 + dp 
    // dp[i][0] : i번째 row의 0번째 값까지 오기 위한 최솟값
    // dp[row번호][0] = 내 값 + min(dp[row번호][0], dp[row번호][1])
    // dp[row번호][1] = 내 값 + min(dp[row번호][0], dp[row번호][1], dp[row번호][2])
    // dp[row번호][2] = 내 값 + min(dp[row번호][1], dp[row번호][2])
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

int main() {
    scanf("%d", &n);

    // 일단 최소점수만 구해보장
    int colMin[3] = {0}, tempMin[3] = {0};
    int colMax[3] = {0}, tempMax[3] = {0};

    // 초기값 딱 한줄만 입력받기
    int a, b, c;
    scanf("%d %d %d", &colMin[0], &colMin[1], &colMin[2]);
    memcpy(colMax, colMin, sizeof(colMax));

    for(int i=1;i<n;i++) {
        for(int j=0;j<3;j++) {
            int num;
            scanf("%d", &num);

            if(j == 0) {
                tempMin[0] = num + min(colMin[0], colMin[1]);
                tempMax[0] = num + max(colMax[0], colMax[1]);
            } else if (j == 1) {
                tempMin[1] = num + min(colMin[0], min(colMin[1], colMin[2]));
                tempMax[1] = num + max(colMax[0], max(colMax[1], colMax[2]));
            } else if (j == 2) {
                tempMin[2] = num + min(colMin[1], colMin[2]);
                tempMax[2] = num + max(colMax[1], colMax[2]);
            }
        }

        // 값 바꾸기
        memcpy(colMin, tempMin, sizeof(colMin));
        memcpy(colMax, tempMax, sizeof(colMax));
    }

    // 값 세개 정렬 후 제일 작은 값, 큰 값 출력
    sort(colMin, colMin+3);
    sort(colMax, colMax+3);
    // printf(">>%d %d %d\n", colMin[0], colMin[1], colMin[2]);

    printf("%d %d\n", colMax[2], colMin[0]);

}