/*
17140. 이차원 배열과 연산
- 벡터 정렬하는 방식으로 풀었다.
- 어차피 둘다 증가하는 순(greater)로 정렬하면 되니까, 우선순위 큐 써도 좋을 것 같다.
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    - pair로 들어가면, first 기준 정렬 => 그 다음에 second 기준 정렬
    - push(), size(), empty(), pop(), top() 사용
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r,c,k;
int n=3, m=3; 
int a[101][101];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) { // <수, 등장 횟수>
    // 등장 횟수 커지는 순 => 수가 커지는 순
    if(a.second == b.second) { 
        return a.first < b.first;
    } else 
        return a.second < b.second;
}

void solution(){
    // (중오) 행 또는 열의 크기가 100을 넘어가는 경우에는 처음 100개를 제외한 나머지는 버린다.
    if(n >= m) { // R 연산
        // 배열 A의 모든 행(가로!)에 대해 정렬 수행
        for(int i=0;i<n;i++) {
            // 각 수가 몇 번 나왔는지 센다 (0 무시)
            int check[101] = { 0 };
            for(int j=0;j<m;j++) {
                check[a[i][j]]++;
            }

            // 넣는다
            vector< pair<int, int> > v; // 수, 등장횟수
            for(int j=1;j<=100;j++) {
                if(check[j] != 0) 
                    v.push_back(make_pair(j, check[j]));
            }

            // 등장 횟수가 커지는 순 => 수가 커지는 순으로 정렬
            sort(v.begin(), v.end(), cmp);

            // 배열 A에 정렬된 결과를 다시 넣는다
            int len = v.size();
            // 100개 넘어가는 경우, 나머지는 버린다
            if(len > 50)    len = 50;

            int index = 0;
            for(int j=0;j<len;j++) {
                a[i][index] = v[j].first;
                a[i][index+1] = v[j].second;
                index+=2;
            }
            len *= 2;

            // 행 또는 열 크기 업데이트
            m = len > m ? len : m;

            // 크기만큼 나머지를 0으로 채우기
            for(int j=len;j<m;j++) {
                a[i][j] = 0;
            }
        }

    } else { // C 연산
        // 배열 A의 모든 열(세로)에 대해 정렬 수행
        for(int i=0;i<m;i++) {
            // 각 수가 몇 번 나왔는지 센다 (0 무시)
            int check[101] = { 0 };
            for(int j=0;j<n;j++) {
                check[a[j][i]]++;
            }

            // 넣는다
            vector< pair<int, int> > v; // 수, 등장횟수
            for(int j=1;j<=100;j++) {
                if(check[j] != 0) 
                    v.push_back(make_pair(j, check[j]));
            }

            // 등장 횟수가 커지는 순 => 수가 커지는 순으로 정렬
            sort(v.begin(), v.end(), cmp);

            // 배열 A에 정렬된 결과를 다시 넣는다
            int len = v.size();
            // 100개 넘어가는 경우, 나머지는 버린다
            if(len > 50)    len = 50;

            int index = 0;
            for(int j=0;j<len;j++) {
                a[index][i] = v[j].first;
                a[index+1][i] = v[j].second;
                index+=2;
            }
            len *= 2;

            // 행 또는 열 크기 업데이트
            n = len > n ? len : n;

            // 크기만큼 나머지를 0으로 채우기
            for(int j=len;j<n;j++) {
                a[j][i] = 0;
            }
        }
    }
}



int main(){
    // 입력받기
    scanf("%d %d %d", &r, &c, &k);
    r--; c--; // (r,c)는 1부터 주어진다 => 하지만, 정렬을 하기 편해야 하니까 0부터 쓰도록 하자. 

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // 100초가 지나도 A[r][c] = k가 되지 않으면 -1 출력
    // 예외처리
    if(a[r][c] == k) {
        printf("0\n");
        return 0;
    }

    for(int t=1;t<=100;t++) {
        solution();
        if(a[r][c] == k) {  // (종료 조건)  A[r][c] == k
            printf("%d\n", t);
            return 0;
        }
    }

    printf("-1\n");
}
