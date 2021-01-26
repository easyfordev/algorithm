#include <iostream>
#include <cstring>
using namespace std;

int arr[101][101];

bool check[101];
int ans[101][101];

int n;

void dfs(int x) {
    for(int i=0;i<n;i++) {
        // 인접하고, 아직 방문 안했으면
        if(arr[x][i] == 1 && check[i] == false) {
            check[i] = true; // 여기서 check를 해줘야한다. 맨 위가 아니라.. 생각을 해봐
            dfs(i);
        }
    }

}
int main(void){
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0;i<n;i++) {
        // 정점 하나마다 dfs돌기
        memset(check, false, sizeof(check));
        dfs(i);

        for(int j=0;j<n;j++) {
            if(check[j] == true)    ans[i][j] = 1;
            else    ans[i][j] = 0;
        }
    }

    // 정답 출력
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

}
