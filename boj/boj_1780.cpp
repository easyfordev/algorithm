#include <iostream>
using namespace std;
int n;
int arr[3*3*3*3*3*3*3 +1][3*3*3*3*3*3*3 +1];
int ans1, ans2, ans3;

void solve(int x, int y, int size) {
    // 이번에 모두 같은 종이인지 판단
    bool flag = true;
    int num = arr[x][y];

    for(int i=x;i<x+size;i++) {
        for(int j=y;j<y+size;j++) {
            if(arr[i][j] != num){
                flag = false;
            }
        }
    }

    if(flag) { // 모두 같은 종이면, 그 종이의 답에 따라 정답 증가시킴
        if(num == -1)   ans1++;
        else if(num == 0)   ans2++;
        else    ans3++;
        return;
    }
    // 아니면, 같은 크기의 9개의 종이(가로 3등분, 세로 3등분)로 자름
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            solve(x+size/3*i, y+size/3*j, size/3); // 이거 식 이상하게 세워서 틀렸었음.. 주의 ...
        }
    }
}

int main(void) {
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    solve(0, 0, n);

    // -1 종이 개수, 1 종이 개수, 0종 종이 개수
    printf("%d\n%d\n%d\n", ans1, ans2, ans3);

}