/* 시뮬레이션 - 되면 다음에 다시 풀자 꼭
배열 돌리기 1과 똑같은데, R범위가 10^9로 엄청 커졌다. 단순하게 풀면 시간초과가 난다.
우앜 자꾸 시간초과.. ㅠㅠ
해결 포인트 
1) (매우 중요) R번 회전이 아닌, 전체 칸수 % R번만큼만 회전
2) temp 배열을 쓰고, 다시 copy하는 과정도 시간을 잡아먹음 -> 이거때문에 여전히 시간초과였음
3) Out of bounds 해결 : 종료 조건을 배열 index 접근하기 전에 걸어줌

*/

#include <iostream>
#include <cstring>
using namespace std;
int n, m, r;
int arr[301][301], temp[301][301], origin[301][301];
int check[301][301];
void rotate() { // 한 번 회전

    // 시작점 정하기
    int x1=0, y1=0; // 시작점
    int x2=n-1, y2=0;
    int x3=n-1, y3=m-1;
    int x4=0, y4=m-1;

    // 모든 점을 다 회전함
    while(true) {
        // 종료조건
        // if(check[x1][y1] != 0)  break;

        int rowStart = x1, colStart = y1;
        int rowEnd = x3, colEnd = y3;
        if(rowStart>rowEnd || colStart>colEnd) break; // Out of bounds 해결

        // 이번 턴에서 가야할 칸의 수 계산
        int x = x2-x1+1;
        int y = y4-y1+1;
        int cnt = (x + y-2) * 2 ;
        int rot = r % cnt;
		// int size = (rowEnd-rowStart+1)*2 + (colEnd-colStart+1)*2 -4;
        // printf(" TURN < %d >  총 칸 수 : %d 이번에 회전해야 하는 수 : %d (이사람 계산 %d) \n", x1+1,cnt, rot  );

        // 나머지만큼 회전하기
		for(int k=0;k<rot;k++) {
            // 아래로 -> 오른쪽으로 -> 위로 -> 왼쪽으로
            // for(int i=x1;i<x2;i++) {
            //     temp[i+1][y1] = arr[i][y1];
            //     check[i+1][y1] = x1+1; // 턴 수 저장
            // }

            // for(int j=y2;j<y3;j++) {
            //     temp[x2][j+1] = arr[x2][j];
            //     check[x2][j+1] = x1+1;
            // }

            // for(int i=x3;i>x4;i--) {
            //     temp[i-1][y3] = arr[i][y3];
            //     check[i-1][y3] = x1+1;
            // }

            // for(int j=y4;j>y1;j--) {
            //     temp[x4][j-1] = arr[x4][j];
            //     check[x4][j-1] = x1+1;
            // }
            // memcpy(arr, temp, sizeof(temp));
           

            int t = arr[rowStart][colStart];

			for(int j=colStart;j<colEnd;j++) {
				arr[rowStart][j] = arr[rowStart][j+1]; 
                // check[rowStart][j] = x1+1; // 턴 수 저장
			}
			
			for(int i=rowStart;i<rowEnd;i++) {
				arr[i][colEnd] = arr[i+1][colEnd];
                // check[i][colEnd]  = x1+1; // 턴 수 저장
			}
			
			for(int j=colEnd;j>colStart;j--) {
				arr[rowEnd][j] = arr[rowEnd][j-1];
                // check[rowEnd][j] = x1+1; // 턴 수 저장
			}
			
			for(int i=rowEnd;i>rowStart;i--) {
				arr[i][colStart] = arr[i-1][colStart];
                // check[i][colStart] = x1+1; // 턴 수 저장
			}
			arr[rowStart+1][colStart] = t;
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

    memcpy(origin, arr, sizeof(arr));
    // (중요) R번 회전 - 한 둘레마다 r의 나머지만큼만 회전해주는 방식으로 바꾼다. (계속 돌면 제자리로 돌아오기 때문)

    // while(r--) {
    rotate();
    // }

    // 맨 마지막 결과 출력
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}