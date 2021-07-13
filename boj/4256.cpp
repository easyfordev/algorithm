/*
BOJ - 4256. 트리
- 전위, 중위 순회 => 후위 순회
- 전위 순회의 특징 : 루트를 정확하게 찾는다.

*/
#include <iostream>
#include <vector>
using namespace std;

int pre_order[1001];
int in_order[1001];

void post_order(int s, int e, int r){ // 시작, 끝, 루트 값을 나타내는 index (preoreder에서 씀)
    // 일단 루트를 찾는다.
    for(int i=s;i<=e;i++) {
        if(in_order[i] == pre_order[r]) {
            // 왼쪽
            post_order(s, i-1, r+1);
            // 오른쪽 
            post_order(i+1, e, r+1+i-s);
            // 루트(여기서 출력)
            printf("%d ", pre_order[r]);
        }
    }
}

int main(){
    int tc;
    scanf("%d", &tc);

    for(int t=0;t<tc;t++) {
        // 입력 받기
        int n;
        scanf("%d", &n);
        // printf("%d\n", n);
        for(int i=1;i<=n;i++) 
            scanf("%d", &pre_order[i]);
        for(int i=1;i<=n;i++) 
            scanf("%d", &in_order[i]);
        
        // 문제 풀기
        post_order(1,n,1);
        printf("\n");
    }
}

